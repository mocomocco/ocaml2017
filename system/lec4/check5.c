#include<stdio.h>
#include<stdlib.h>

int gl;

int main(){
  static int st;
  int lo;
  int stack[5],stack2[5];
  int lo2;
  int *heap = malloc(sizeof(char)*5);

  printf("mainのアドレス   ：%p\n\n",&main);
  printf("glのアドレス   　：%p\n",&gl);
  printf("stのアドレス 　　：%p\n",&st);
  printf("\n");
  printf("loのアドレス     ：%p\n",&lo);
  printf("lo2のアドレス　　：%p\n",&lo2);
  printf("stackのアドレス  ：%p\n",&stack);
  printf("stack2のアドレス ：%p\n",&stack2);
  printf("\n");
  printf("heapのアドレス ：%p\n",heap);
  printf("\n");
}
