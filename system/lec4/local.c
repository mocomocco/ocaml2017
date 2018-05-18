#include<stdio.h>

void change();
int l_val;
int main(){
  static int l_val=123;

  printf("l_cal %d\n",l_val);
  l_val=1;
  printf("l_val %d \n",l_val);
  change();
  change();
}
void change(){
   int l_val;
  l_val += 100;
  printf("l_val %d\n",l_val);
}
