#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int **ma,**mb,**mc;
int NUM;

double get_time()
{
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return tv.tv_sec + tv.tv_usec * 1e-6;
}

void printanswer(){
  int i,h;
  printf("NUM=%d\n",NUM);
  for(i=0;i<NUM;i++){
    for(h=0;h<NUM;h++){
      printf(" ");
      printf("%d",ma[i][h]) ;
    }
    if(i==NUM/2)printf(" * ");
    else  printf("   ");
    for(h=0;h<NUM;h++){
      printf(" ");
      printf("%d",mb[i][h]) ;
    }
    if(i==NUM/2)printf(" = ");
    else  printf("   ");
    for(h=0;h<NUM;h++){
      printf(" ");
      printf("%d",mc[i][h]) ;
    }

    printf("\n");
  }
}

void getmatrix(){
  printf("正方行列の計算をします。行数を設定してください。\n");
  scanf("%d",&NUM);
  ma=(int**)malloc(sizeof(int*)*NUM);
  mb=(int**)malloc(sizeof(int*)*NUM);
  mc=(int**)malloc(sizeof(int*)*NUM);
  for(int i=0;i<NUM;i++){
    ma[i]=(int*)malloc(sizeof(int)*NUM);
    mb[i]=(int*)malloc(sizeof(int)*NUM);
    mc[i]=(int*)malloc(sizeof(int)*NUM);
  }
}

void setmatrix(){
  for(int i=0;i<NUM;i++){
    for(int h=0;h<NUM;h++){
      ma[i][h]=i*NUM+h+1;
      mb[i][h]=ma[i][h];
      mc[i][h]=0;
    }
  }
}

int main(){
  int i,h,j;
  getmatrix();
  setmatrix();
  double begin = get_time();
  for(i=0;i<NUM;i++){
    for(j=0;j<NUM;j++){
      for(h=0;h<NUM;h++){
	mc[i][h]+=ma[i][j]*mb[j][h];
      }
    }
  }
  double end = get_time();
  //printanswer();
  printf("time: %.6lf sec\n", end - begin);

  free(ma);
  free(mb);
  free(mc);
  printf("finish\n");

}
