#include <stdio.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
void error(char *msg) {//エラーが生じたらエラーメッセージを標準出力
  perror(msg);
  exit(1); }

int setserversocket(int argc,char *argv[]){
  int sockfd, portno;
  struct sockaddr_in serv_addr;
  if (argc < 2) {//引数が足りなければ終了
    fprintf(stderr,"ERROR, no port provided¥n"); exit(1);
  }
  portno = atoi(argv[1]);//一つ目の引数をポートナンバーとして取得
  //printf("portno:%d\n",portno);

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  //sockfdは新しいソケット (IPv4 インターネットプロトコルを用い、順序性と信頼性があり、双方向の、
  //接続された バイトストリーム (byte stream) を提供)のファイルディスクリプター
  //printf("errorcheck\n");
  if (sockfd < 0)//ソケット取得に失敗したらエラーを起こす
    error("ERROR opening socket");
  //bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;//IPアドレス
  serv_addr.sin_port = htons(portno);//ポート番号をバイトオーダーに変換

  //先ほど新しく作ったソケットにaddr でローカルアドレスを割り当てる、失敗したらエラーを起こす
  if (bind(sockfd, (struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
    error("ERROR on binding");
  return sockfd;
}

int receivemessage(int num,int newsockfd,int newsockfdr){
  int n;
  char buffer[256],bufferr[7];//メッセージを格納
  n = read(newsockfd,buffer,255);
  //if (n < 0) error("ERROR reading from socket");
  if(n>0){
    if(strcmp(buffer,"quit\n")==0)return 2;
    write(STDOUT_FILENO,"\nclient",6*sizeof(char));
    if(num==1)write(STDOUT_FILENO,"1",1);
		if(num==2)write(STDOUT_FILENO,"2",1);
		write(STDOUT_FILENO,":",1*sizeof(char));
    write(STDOUT_FILENO,buffer,sizeof(buffer));
    write(STDOUT_FILENO,"\nyou:",5*sizeof(char));
		if(num!=0){
    if(num==1){
    strcpy(bufferr,"client1") ;
		}
		if(num==2){
		strcpy(bufferr,"client2") ;
		}
		strcat(bufferr,buffer);
		write(newsockfdr,bufferr,255);
  	}
  }
  return 1;
}

int sendmessage(int num,int newsockfd,int newsockfd2){
  int n;
  char buffer[256];//メッセージを格納
  memset(buffer, '\0', 256);
  n=read(STDIN_FILENO,buffer,255);
  if(n>0){
    write(newsockfd,buffer,255);
		if(num==1)write(newsockfd2,buffer,255);
    if(strcmp(buffer,"quit\n")==0)return 2;
    write(STDOUT_FILENO,"\nyou:",4*sizeof(char));
  }
  return 1;
}

int main(int argc, char *argv[]) {
  int sockfd, newsockfd1,newsockfd2;
  socklen_t clilen;
  struct sockaddr_in serv_addr, cli_addr;
  sockfd=setserversocket(argc,argv);
  listen(sockfd,2);//接続要求を受け付ける意志と一時的な接続要求の待ち行列の大きさを表明
  clilen = sizeof(cli_addr);
  //待ち行列の先頭にあるアドレスと接続する参照用のファイルディスクリプタ
  newsockfd1 = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
	if (newsockfd1 < 0){
    error("ERROR on accept");
  }
	write(STDOUT_FILENO,"send quit to stop\n",18*sizeof(char));
  fcntl(newsockfd1,F_SETFL,O_NONBLOCK);
  fcntl(STDIN_FILENO,F_SETFL,O_NONBLOCK);
	cntl(cli_addr,F_SETFL,O_NONBLOCK);
  write(STDOUT_FILENO,"Please enter the message: ",26*sizeof(char));
  while(1){
    if(receivemessage(0,newsockfd1,newsockfd1)==2)break;
    if(sendmessage(0,newsockfd1,newsockfd1)==2)break;
		write(STDOUT_FILENO,"a\n",1*sizeof(char));
		newsockfd2 = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
	  if(newsockfd2>0){
    write(STDOUT_FILENO,"new member\n",11*sizeof(char));
	  break;
    }
		write(STDOUT_FILENO,"loop\n",11*sizeof(char));
  }
  fcntl(newsockfd2,F_SETFL,O_NONBLOCK);
	while(1){
    if(receivemessage(1,newsockfd1,newsockfd2)==2)break;
		if(receivemessage(2,newsockfd1,newsockfd2)==2)break;
    if(sendmessage(1,newsockfd1,newsockfd2)==2)break;
  }
  write(STDOUT_FILENO,"\nfinish conversation\n",21*sizeof(char));
  close(newsockfd1);
	close(newsockfd2);
  close(sockfd);
  return 0;
}
