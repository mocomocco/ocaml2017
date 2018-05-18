#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
  //make process
  int i;
  pid_t pid = fork();
  if(pid==0){//child
    printf("A\n");
    for(i=0;i<500000000;i++){
      int j=0;j++;
    }    return 0;
  }
  int status;
  wait(&status);
  printf("B\n");

  return 0;
}
