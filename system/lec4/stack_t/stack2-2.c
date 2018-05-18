#include<stdio.h>

int i;
void funca();
void funcb();

int main(){
  printf("main\n");
  funca();
}

void funca(){
  i++;
  printf("a\n");
  printf("%p\n",funcb);
  if(i<131026)funcb();
}

void funcb(){
  printf("b\n");
  printf("%p\n",funca);
  funca();
}
