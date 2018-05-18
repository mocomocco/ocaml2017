#include<stdio.h>

int main(){
  int lo,lo2,lo3,lo4,lo5;
  int stack[5],stack2[5];
   
  printf("loのアドレス     ：%p\n",&lo);
  printf("lo2のアドレス    ：%p\n",&lo2);
  printf("lo3のアドレス    ：%p\n",&lo3);
  printf("lo4のアドレス    ：%p\n",&lo4);
  printf("lo5のアドレス    ：%p\n",&lo5);

  lo=5;
  if (lo==5)printf("stackのアドレス  ：%p\n",&stack);
  printf("stack2のアドレス  ：%p\n",&stack2);
  printf("\n");

}
