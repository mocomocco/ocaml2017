#include<stdio.h>
#include<stdlib.h>

int gl;

int main(){
  int lo;
  static int st;
  int stack[5];
  int *heap = malloc(sizeof(char)*5);

  printf("mainのアドレス    :%p\n\n",&main);
  printf("glのアドレス   　：%p\n",&gl);
  printf("stのアドレス 　　：%p\n",&st);
  printf("\n");
  printf("loのアドレス     ：%p\n",&lo);
  for(lo=0;lo<5;lo++)
    printf("stack[%d]のアドレス  ：%p\n",lo,&stack[lo]);
  printf("\n");
  printf("heapのアドレス ：%p\n",heap);
  printf("\n");
}
