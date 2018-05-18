#include<stdio.h>
#include<stdlib.h>

int gl;

void main3(){
  int lo3;
  printf("main3のアドレス　：%p\n",&main3);
  printf("lo3のアドレス　　：%p\n",&lo3);
}
void main2(){
  int lo2;
  printf("main2のアドレス　：%p\n",&main2);
  printf("lo2のアドレス　　：%p\n",&lo2);
  printf("\n");
  main3();
}

int main(){
  int lo;
  static int st;


  printf("mainのアドレス    :%p\n\n",&main);
  printf("glのアドレス   　：%p\n",&gl);
  printf("stのアドレス 　　：%p\n",&st);
  printf("\n");
  printf("loのアドレス     ：%p\n",&lo);
  printf("\n");

  main2();
}
