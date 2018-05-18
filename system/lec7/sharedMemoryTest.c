#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
  //create
  key_t key = IPC_PRIVATE;
  size_t size = 1024;
  int shmflg = IPC_CREAT | S_IRWXU;
  int id;
    int st;
  id = shmget(key, size, shmflg);
  //key->IRC_PRIVATE size->確保サイズ　shmflg->IPC_CREAT|アクセス権
  //共有メモリの確保

  //make process
  pid_t pid = fork();
  if(pid==0){//child
    int *num;
    num = (int*)shmat(id,0,0);
    //システムが選択したメモリを参照
    //共有メモリ領域のID取得
    int i;
    for(i=0;i<60;i++){
      num[i] = i;
    }
    /*      shmdt(num);
	 shmctl(id,IPC_RMID,0);
	 return 0;*/
  }
  else{
    if(WIFEXITED(st))
    waitpid(pid,&st,WNOHANG);
  //stに状態情報を格納
  }
  //attach
  int *num;
  num = (int*)shmat(id,0,0);
   //共有メモリ領域のID取得
  int i;
  for(i=0;i<60;i++){
    printf("%d ",num[i]);
  }
  printf("\n");
  //detach
  shmdt(num);
  //numの示す番地のIDとメモリを切り離す
  //destroy
  shmctl(id,IPC_RMID,0);
  //メモリ開放
  return 0;
}
