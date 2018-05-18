#include<stdio.h>

int main(){
  double lo;
  int lo2;
  int stack[5],stack2[5];
   
  printf("loのアドレス     ：%p\n",&lo);
  printf("lo2のアドレス    ：%p\n",&lo2);

  lo=5;
  if (lo==5)printf("stackのアドレス  ：%p\n",&stack);
  printf("stack2のアドレス  ：%p\n",&stack2);
  printf("\n");

}
