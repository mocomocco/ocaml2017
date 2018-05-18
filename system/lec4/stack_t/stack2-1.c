#include<stdio.h>

int i;
void funca();
void funcb();

int main(){
  printf("main\n");
 printf("%p\n",funca);
  funca();
 printf("%p\n",funca);
 printf("%p\n",funcb);
  funcb();
 printf("%p\n",funca);
 printf("%p\n",funcb);
  funca();
 printf("%p\n",funca);
 printf("%p\n",funcb);
  funcb();
}

void funca(){
  i++;
  printf("a\n");
  printf("%p\n",funcb);
  /*  funcb();
  printf("return\n");
 printf("%p\n",funcb);
  funcb();
  printf("return\n");*/
}

void funcb(){
  printf("b\n");
  printf("%p\n",funca);
  /*  funca();*/
}
