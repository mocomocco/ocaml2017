#include<stdio.h>

int glo=0;

void a(){
  static int sta=0;
  int loc=0;
  glo++;
  sta++;
  loc++;
  
  printf("関数aの中で\n\tsta=%d loc=%d glo=%d\n\n"
	 ,sta,loc,glo);
}

int main(){
  int i;
  glo++;
  printf("main関数の中で1を足した後glo=%d\n\n",glo);
 
    for(i=1;i<=5;i++){
      printf("%d回目の呼び出し\n",i);
      a();}

}

