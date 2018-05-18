#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>

int main(){
   char buf[2];
 
  fcntl(STDIN_FILENO,F_SETFL,O_NONBLOCK);
  while(1){
    buf[0]='\0';
    buf[1]='\0';
    read(STDIN_FILENO,buf,sizeof(char)*2);
    printf("%s",buf);}
}
