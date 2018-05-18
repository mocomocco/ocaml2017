#include<stdio.h>

int main(){
  int lo,lo2;
  int stack[5];

  printf("loのアドレス     ：%p\n",&lo);
  printf("lo2のアドレス　　：%p\n",&lo2);

  lo=lo2;

  printf("stack[%d]のアドレス  ：%p\n",lo2,&stack[lo2]);
  printf("\n");

}
