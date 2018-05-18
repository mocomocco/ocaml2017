#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>//threadの一種の書き方
int *matrix,*A,*B;

int pmax,qmax;

void* func(void* arg){
  int i = *((int*)arg);
  int p,q;
  matrix[i]=0;

  p=-1;
  int h=i;
  while(h>=0){
    p++;
    h=h-pmax;
  }

  q=i-pmax*p;
  //printf("i:%d p:%d,q:%d\n",i,p,q);
  for(int j=0;j<qmax;j++){
    matrix[i] +=A[p*pmax+j]*B[j*pmax+q];
    //    printf("matrix[%d]=%d\n",i,matrix[i]);
  }

  //printf("answer[%d]=%d\n",i,matrix[i]);
  pthread_exit(NULL);
}

void getmatrix(int *new,int pmax,int qmax){
  printf("%d行%d列の行列について",pmax,qmax);
  printf("数字ごとに行替えしてください。\n");
  for(int i=0;i<qmax;i++){
    printf("%d列め:\n",i);
    for(int h=0;h<pmax;h++){
      scanf("%d",&new[pmax*i+h]);
      /*   printf("new[%d]=%d\n",pmax*i+h,new[pmax*i+h]);*/
    }
  }
}

int main(){
  int i;//ループのための変数

  void* result;//
  printf("ABを求めます。\nAは何行？：");
  scanf("%d",&pmax);
  printf("Aは何列?:");
  scanf("%d",&qmax);
  A=(int*)malloc(sizeof(int)*qmax*pmax);
  B=(int*)malloc(sizeof(int)*pmax*qmax);
  int n=pmax*pmax;
  matrix=(int*)malloc(sizeof(int)*n);
  printf("Aの情報を入力してください\n");
  getmatrix(A,pmax,qmax);
  printf("Bの情報を入力してください\n");
  getmatrix(B,qmax,pmax);
  //A,Bを得る
  for(i=0;i<qmax;i++){
    for(int j=0;j<pmax;j++){
      printf("%d ",A[i*pmax+j]);
    }
    printf("\n");
  }
  for(i=0;i<pmax;i++){
    for(int j=0;j<qmax;j++){
      printf("%d ",B[i*qmax+j]);
    }
    printf("\n");
  }


  pthread_t t[n];//threadのための箱
  //1. id (consider here)
  int id[n];
  for(i=0;i<n;i++){
    id[i]=i; }

  //2. thread
  for(i=0;i<n;i++){
    //printf("p:%d\n",i);
    if(pthread_create(&(t[i]),NULL,func,&id[i])){//スレッド化したい関数のポインタ、関数の引数
      printf("error\n");
    }
  }
  //3. wait
  for(i=0;i<n;i++){
    pthread_join(t[i],&result);
  }
  //4. check
  for(i=0;i<n;i++){
    printf("c: %d\n",matrix[i]);
  }
  //5. free
	printanswer();
	free(A);
	free(B);
  free(matrix);
  return 0; }
