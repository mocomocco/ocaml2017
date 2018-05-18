#include<stdio.h>

void f(char *s);

int main(int argc, char* argv[]){
  f(argv[1]);
  return 0;
}

void f(char *s){
    printf("%s\n",s);
}
