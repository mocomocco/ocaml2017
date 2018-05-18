#include <stdio.h>    //printf使うから
#include <sys/types.h>  //fork関数使うから
#include <unistd.h>//pidt変数使うから
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sysexits.h>



  int main(){
    pid_t  A = 0, B= 0;
    char tmp[256];
    int pipefd1[2];
    int pipefd2[2];
    int i;
    int c;
    char buf[10];
    
    pipe(pipefd1);  //パイプ開く
    pipe(pipefd2);
    A = fork();
      /* fcntl(pipefd1, F_SETFL, O_NONBLOCK);
       fcntl(pipefd2, F_SETFL, O_NONBLOCK); */

      if(A != 0){
          B = fork();
      }
      
    if(A != 0 && B != 0){  //親プロセス
        FILE *fp;
        fp = fopen("string.txt","r");
        
        /*wait(&A);*/
        
        while(fgets(tmp, sizeof(tmp), fp) != NULL){
            write(pipefd1[1], tmp, 10);
        }
        
        read(pipefd2[0], buf, 3);
        
        if(buf[0] == 'c'){
            exit;
        }
        
        fclose(fp);
    }
     if(A == 0){   //子プロセスA */
       while(0 < read(pipefd1[0], tmp, 1)){ 
          
          sleep(1); 
           printf("child : %s\n",tmp); 
       } 
         read(pipefd2[0], buf, 3); 
         if(buf[0] == 'c'){ 
	   exit(0); 
         } 
        return 0;
    }

    if(B == 0){   //子プロセスB
      while(strcmp(buf, "c\n") != 0){
	buf[0] = '\0';
	buf[1] = '\0';
	buf[2] = '\0';
	read(STDIN_FILENO, buf, sizeof(char) * 3);
	printf("%s",buf);
	write(pipefd2[1], buf, 3);
      }
    }
	}








