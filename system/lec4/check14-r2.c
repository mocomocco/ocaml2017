#include<stdio.h>

int main(){
  int lo,lo2;
  int stack[5];

  printf("loのアドレス     ：%p\n",&lo);
  printf("lo2のアドレス　　：%p\n",&lo2);
  lo=5;
  for(lo2=0;lo2<10;lo2++){
  if (lo==lo2)printf("stackのアドレス  ：%p\n",&stack);
  }

  printf("\n");

}
