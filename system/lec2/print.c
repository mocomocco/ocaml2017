#include<fcntl.h>
#include<unistd.h>

int main(){
  int desA = open("aaa",O_RDONLY);
  int desB = open("bbb",O_WRONLY);
  for(int i=0;i<5;i++){
    char str[2];
    read(desA,str,sizeof(char)*2);
    write(desB,str,sizeof(char)*2);
  }
  close(desB);
  close(desA);
  return 0;
}
