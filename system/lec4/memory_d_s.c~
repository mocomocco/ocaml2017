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
  char stack_list[10];
  unsigned *heap_list = malloc(sizeof(int)*10);
  /*   for(int i=0;i<10;i++){
    printf("stack list[%d] %16p\n", i,&stack_list[i]);
    printf("stack list[%d] %016x\n",i, &stack_list[i]);
    printf("\n");*/
    /*アドレスはiが一つ増えるたびに4ずつ増える(int型が4Byteだから)*/
    /*char型:1  int long:8 double:8 double long :16 short :2 float :4 unsigned:4 */
    /*実行のたびに得られるアドレスは違う*/
  /* }*/
   
  
  for(int i=0;i<10;i++){
    printf("heap list[%d] %16p\n", i,&(heap_list[i]));
    printf("heap list[%d] %016x\n", i,&(heap_list[i]));
    printf("\n");
    /*実行のたびに得られるアドレスは違う*/

  }

  /*printf("g_val0 %16p\n", &g_val0);
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
   */
}

int funcL(){
  return 1;
}
