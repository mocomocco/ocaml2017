#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

int *matrix,*A,*B,NUM;


double get_time()
{
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return tv.tv_sec + tv.tv_usec * 1e-6;
}

void printanswer(){
  for(int i=0;i<NUM;i++){
    for(int j=0;j<NUM;j++){
      printf("%d ",A[i*NUM+j]);
    }
    printf("  ");
    if(i==NUM*NUM/2){printf("×  ");}
    else printf("  ");
    for(int j=0;j<NUM;j++){
      printf("%d ",B[i*NUM+j]);
    }
    printf("  ");
    if(i==NUM*NUM/2){printf("=  ");}
    else printf("  ");
    for(int j=0;j<NUM;j++){
      printf("%d ",matrix[i*NUM+j]);
    }
    printf("\n");
  }
}


void* func(void* arg){
  int i = *((int*)arg);
  int p,q;
  p=-1;
  int h=i;
  while(h>=0){
    p++;
    h=h-NUM;
  }

  q=i-NUM*p;
  for(int j=0;j<NUM;j++){
    matrix[i] +=A[p*NUM+j]*B[j*NUM+q];
  }

  pthread_exit(NULL);
}

void getmatrix(){
  printf("正方行列の計算をします。行数を設定してください。\n");
  scanf("%d",&NUM);
  A=(int*)malloc(sizeof(int)*NUM*NUM);
  B=(int*)malloc(sizeof(int)*NUM*NUM);
  matrix=(int*)malloc(sizeof(int)*NUM*NUM);

}

void setmatrix(){
  printf("NUM=%d\n",NUM);
  for(int i=0;i<NUM*NUM;i++){
    A[i]=i+1;
    B[i]=i+1;
    matrix[i]=0;
  }
}


int main(){
  int i;
  void* result;//
  getmatrix();
  //A,Bを得る
  setmatrix();
  int n=NUM*NUM;
  double begin = get_time();
  pthread_t t[n];//threadのための箱

  int id[n];
  for(i=0;i<n;i++){
    id[i]=i; }

  for(i=0;i<n;i++){
    if(pthread_create(&(t[i]),NULL,func,&id[i])){
      //スレッド化したい関数のポインタ、関数の引数
      printf("error\n");
    }
  }

  for(i=0;i<n;i++){
    pthread_join(t[i],&result);
  }
  double end = get_time();
  printf("time: %.6lf sec\n", end - begin);

  //printanswer();
  free(A);
  free(B);
  free(matrix);
  return 0;
}
