#include<stdio.h>

int main(){
  int lo,lo2;
  int stack[5];

  printf("loのアドレス     ：%p\n",&lo);
  printf("lo2のアドレス　　：%p\n",&lo2);
for(lo2=0;lo2<5;lo2++)
printf("stack[%d]のアドレス  ：%p\n",lo2,&stack[lo2]);
  printf("\n");

}