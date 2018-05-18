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
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  //sockfdは新しいソケット (IPv4 インターネットプロトコルを用い、順序性と信頼性があり、双方向の、
  //接続された バイトストリーム (byte stream) を提供)のファイルディスクリプター
  if (sockfd < 0)//ソケット取得に失敗したらエラーを起こす
    error("ERROR opening socket");
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;//IPアドレス
  serv_addr.sin_port = htons(portno);//ポート番号をバイトオーダーに変換

  //先ほど新しく作ったソケットにaddr でローカルアドレスを割り当てる、失敗したらエラーを起こす
  if (bind(sockfd, (struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
    error("ERROR on binding");
  return sockfd;
}

int receivemessage(int newsockfd){
  int n;
  char buffer[256];//メッセージを格納
  
  n = read(newsockfd,buffer,255);
  if(n>0){
    if(strcmp(buffer,"quit\n")==0)return 2;
    write(STDOUT_FILENO,"\nHere is the message:",21*sizeof(char));
    write(STDOUT_FILENO,buffer,sizeof(buffer));
    write(STDOUT_FILENO,"\nPlease enter the message:",26*sizeof(char));
  }
  return 1;
}

int sendmessage(int newsockfd){
  int n;
  char buffer[256];//メッセージを格納
  memset(buffer, '\0', 256);
  n=read(STDIN_FILENO,buffer,255);
  if(n>0){
    write(newsockfd,buffer,255);
    if(strcmp(buffer,"quit\n")==0)return 2;
    write(STDOUT_FILENO,"\nPlease enter the message: ",26*sizeof(char));
  }
  return 1;
}

int main(int argc, char *argv[]) {
  int sockfd, newsockfd;
  socklen_t clilen;
  struct sockaddr_in cli_addr;
  sockfd=setserversocket(argc,argv);
  listen(sockfd,1);//接続要求を受け付ける意志と一時的な接続要求の待ち行列の大きさを表明
  clilen = sizeof(cli_addr);
  //待ち行列の先頭にあるアドレスと接続する参照用のファイルディスクリプタ
  newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
  if (newsockfd < 0){
    error("ERROR on accept");
  }
  write(STDOUT_FILENO,"send quit to stop\n",18*sizeof(char));
  fcntl(newsockfd,F_SETFL,O_NONBLOCK);
  fcntl(STDIN_FILENO,F_SETFL,O_NONBLOCK);
  write(STDOUT_FILENO,"Please enter the message: ",26*sizeof(char));
  while(1){
    if(receivemessage(newsockfd)==2)break;
    if(sendmessage(newsockfd)==2)break;}
  write(STDOUT_FILENO,"\nfinish conversation\n",21*sizeof(char));
  close(newsockfd);
  close(sockfd);
  return 0;
}
