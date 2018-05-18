#include<stdio.h>

void a();
void b();

int main(){
  printf("main\n");
  a();
}

void a(){
  printf("a\n");
  b();
}

void b(){
  printf("b\n");
  a();
}
