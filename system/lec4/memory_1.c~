#include <stdio.h>


int funcL();

void funcR(){
}

int g_val0;//global
int g_val1 = 123;//global

int main(){
  int l_val0;//local
  int l_val1 = 456;//local
  static int s_val0;//static
  static int s_val1 = 789;//static
  int stack_list[10];
  int *heap_list = malloc(sizeof(int)*10);
  for(int i=0;i<10;i++){
    printf("stack list %16p\n", &(stack_list[i]));
    printf("stack list %016x\n", &(stack_list[i]));
  }
  for(int i=0;i<10;i++){
    printf("heap list %16p\n", &(heap_list[i]));
    printf("heap list %016x\n", &(heap_list[i]));
  }
  printf("g_val0 %16p\n", &g_val0);
  printf("g_val0 %016x\n", &g_val0);
  printf("g_gal1 %16p\n", &g_val1);
  printf("g_gal1 %016x\n", &g_val1);
  printf("l_val0 %16p\n", &l_val0);
  printf("l_val0 %016x\n", &l_val0);
  printf("l_gal1 %16p\n", &l_val1);
  printf("l_gal1 %016x\n", &l_val1);
  printf("s_val0 %16p\n", &s_val0);
  printf("s_val0 %016x\n", &s_val0);
  printf("s_val1 %16p\n", &s_val1);
  printf("s_val1 %016x\n", &s_val1);
  printf("funcL %16p\n", funcL);
  printf("funcL %016x\n", funcL);
  printf("funcR %16p\n", funcR);
  printf("funcR %016x\n", funcR);
  printf("main %16p\n", main);
  printf("main %016x\n", main);
  printf("printf %16p\n", printf);
  printf("printf %016x\n", printf);
  return 0;
}

int funcL(){
  return 1;
}
