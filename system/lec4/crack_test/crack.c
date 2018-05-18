#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
char cmd[5];
char tmp[3];

  strcpy(cmd,"ls");
 
  scanf("%s",tmp);

   system(cmd);
}
