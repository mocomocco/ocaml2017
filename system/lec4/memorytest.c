#include<stdio.h>

int main(){
  char a=1;
  printf("%d\n",a);/*00000001*/
  printf("%d\n",a=a<<1);/*00000010*/
  printf("%d\n",a=a<<1);/*00000100*/
  printf("%d\n",a=a<<1);/*00001000*/
  return 0; 

}
