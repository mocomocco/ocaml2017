#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
  //make process
  int i;
  pid_t pid = fork();
  if(pid==0){//child
    printf("A\n");
  }
  printf("B\n");

  return 0;
}
