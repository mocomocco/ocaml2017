#include<stdio.h>

int main(){
  short lo,lo2;
  int stack[5];

  printf("loのアドレス     ：%p\n",&lo);
  printf("lo2のアドレス　　：%p\n",&lo2);
  lo=5;
  lo2=5;
  if (lo==1)printf("stackのアドレス  ：%p\n",&stack);
 if (lo2==5)printf("stackのアドレス  ：%p\n",&stack);

  printf("\n");

}
