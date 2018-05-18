#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(){
  const int num = 100;
  int status;
  int fd[2],fd2[2];

  pipe(fd);//pipe
  pipe(fd2);
  printf("pipe1:%d %d\n",fd[0],fd[1]);
  printf("pipe2:%d %d\n",fd2[0],fd2[1]);
  
  
	  pid_t cid0 = fork();//make child process
						 //printf("id: %d\n",cid[i]);
	  if (cid0 == 0) {//if this process childs
	    for(int i=0;i<num;i++){
	      char strS[300],strR[300];
		  sprintf(strS, "%d\n", i);
		  printf("sen: %s", strS);
		  write(fd[1], strS, strlen(strS) + 1);
		  read(fd2[0],strR,sizeof(strR));
		  printf("rec:%s",strR);}
		  return 0;
	  }
	  //if (cid1 == 0) {//if this process childs
		 // char string[300];
		 // sprintf(string, "%d\n", i);
		 // //printf("sen: %s", string);
		 // write(fd[1], string, strlen(string) + 1);
		 // return 0;
	  //}
  

  
    char buf[300];
    for(int i=0;i<num;i++){
    read(fd[0],buf,sizeof(buf));
    printf("buR:%s",buf);
    write(fd2[1],buf,sizeof(buf));
    printf("buS:%s",buf);    
  }

  //wait all id
    wait(&status);

  return 0;
}
