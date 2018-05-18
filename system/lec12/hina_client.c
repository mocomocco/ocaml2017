#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
void error(char *msg) {//エラー表示して終了
  perror(msg);
  exit(0);
}

int setclientsocket(int argc,char *argv[]){
  int sockfd;
  if (argc < 3) {//引数が少なければエラー
    fprintf(stderr,"usage %s hostname port\n", argv[0]);
    exit(0); }
  //printf("getsockfd\n");
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  //sockfdは新しいソケット (IPv4 インターネットプロトコルを用い、順序性と信頼性があり、双方向の、
  //接続された バイトストリーム (byte stream) を提供)のファイルディスクリプター
  if (sockfd < 0)//取得できなければエラー
    error("ERROR opening socket");
  return sockfd;
}

void setserv_addr(char *argv[],struct sockaddr_in *serv_addr){
  int portno;
  struct hostent *server;
  portno = atoi(argv[2]);//ポートナンバーを取得
  //argvで表されたホスト仕様の hostent 構造体を返す。
  //127.0.0.1は自分自身のことを指す特別なIPアドレス
  server = gethostbyname(argv[1]);
  //printf("check servererror\n");
  if (server == NULL) {//もしサーバがなければエラー
    fprintf(stderr,"ERROR, no such host¥n");
    exit(0); }
  //server->h_addr(ホストのアドレス)をserv_addr.sin_addr.s_addr(IPアドレス)に登録
  bcopy((char *)server->h_addr,
	(char *)&serv_addr->sin_addr.s_addr,
	server->h_length);//
  serv_addr->sin_port = htons(portno);//ポート番号を登録
}

int sendmessage(int sockfd){
  int n;
  char buffer[256];
  memset(buffer, '\0', 256);
  n=read(STDIN_FILENO,buffer,255);
  //if (n < 0)error("ERROR writing to socket");
  if(n>0){
    write(sockfd,buffer,255);
    if(strcmp(buffer,"quit\n")==0)return 2;
    write(STDOUT_FILENO,"\nPlease enter the message: ",26*sizeof(char));
  }
  return 1;
}

int receivemessage(int sockfd){
  int n;
  char buffer[256];
  n = read(sockfd,buffer,255);
  //if (n < 0) error("ERROR reading from socket");
  if(n>0){
    if(strcmp(buffer,"quit\n")==0)return 2;
    write(STDOUT_FILENO,"\nHere is the message:",21*sizeof(char));
    write(STDOUT_FILENO,buffer,sizeof(buffer));
    write(STDOUT_FILENO,"\nPlease enter the message: ",26*sizeof(char));
  }
  return 1;
}

int main(int argc, char *argv[]) {
  int sockfd;
  struct sockaddr_in serv_addr;

  sockfd=setclientsocket(argc,argv);
  setserv_addr(argv,&serv_addr);
  //sockfd が参照しているソケットを addr で指定されたアドレスに接続する。
  if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0){//指定されたポートのホストに繋ぐ
    error("ERROR connecting");
  }
  write(STDOUT_FILENO,"send quit to stop\n",18*sizeof(char));
  fcntl(sockfd,F_SETFL,O_NONBLOCK);
  fcntl(STDIN_FILENO,F_SETFL,O_NONBLOCK);
  write(STDOUT_FILENO,"Please enter the message: ",26*sizeof(char));
  while(1){
    if(sendmessage(sockfd)==2)break;
    if(receivemessage(sockfd)==2)break;}
  write(STDOUT_FILENO,"\nfinish conversation\n",21*sizeof(char));
  close(sockfd);
  return 0;
}
