//http://www.c-lang.net/semctl/index.html
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/stat.h>
#include<sys/sem.h>

#define LOCK -1
#define UNLOCK 1
#define WAIT 0

void MySemop(int semid,int semnum,int op)
{
  struct sembuf sops[1];

  sops[0].sem_num = semnum;          /* セマフォ番号 */
  sops[0].sem_op = op;               /* セマフォ操作 */
  sops[0].sem_flg = 0;                 /* 操作フラグ */

  semop(semid,sops,1);
  //semid 操作するセマフォ集合のセマフォID sops セマフォ操作の内容　nsops sopsの要素数
  
  return;
}

int main(int argc,char *filename[]){
  char *tmpmemory;
  key_t key = IPC_PRIVATE;
  size_t size = 1024;
  int shmflg = IPC_CREAT | S_IRWXU,tmpmemory_id;
  pid_t cid0=1,cid1=1;

  if(argc==1){
    printf("No commandline option!\n");
    return 0;
  }
  tmpmemory=(char*)malloc(2048);
  tmpmemory_id = shmget(key, size, shmflg);
  tmpmemory=(char*)shmat(tmpmemory_id,0,0);
  //key->IRC_PRIVATE size->確保サイズ　shmflg->IPC_CREAT|アクセス権
  //共有メモリの確保->tmpmemory
   

  union semun seminit;
  struct sembuf semlock;
  struct shmid_ds sembuf;
  int tmpmemory_s_id;
  unsigned short vals[2]={UNLOCK,WAIT};
  tmpmemory_s_id = semget(tmpmemory_id,2,shmflg);
  //key->IRC_PRIVATE,nsems->セマフォの数 shmflg->IRC_CREATE|アクセス権
  seminit.array = vals;
  semctl(tmpmemory_s_id,0,SETALL,seminit);
  //2つあるセマフォのvalの初期値を設定
  
  cid0 = fork();//Aを作る
  if (cid0 != 0){cid1=fork();}//Bを作る(ここでif文にしないと子プロセスが全体で3個できてしまう)

  if(cid0 != 0 && cid1 != 0){//親だったら
    FILE *fp;
    fp=fopen(filename[1],"r");
    if(fp==NULL){
      printf("cannot find :%s\n",filename[1]);
      return 0;
    }
    //引数として与えられたファイルを開いた

    while(1){//ファイルが終わるまで
      MySemop(tmpmemory_s_id,0,LOCK);
      if(fgets(tmpmemory,sizeof(char)*2048,fp)==NULL){
	break;
      }
      MySemop(tmpmemory_s_id,1,UNLOCK);
      usleep(1); 
    }
    tmpmemory[0]='\0';
    fclose(fp);
    shmdt(tmpmemory);
    //IDとメモリを切り離し
    shmctl(tmpmemory_id,IPC_RMID,0);
    //メモリ解放
    semctl(tmpmemory_s_id,IPC_RMID,0);
    //セマフォ解放
  }


  if(cid0 == 0 && cid1 ==1){//Aだったら
    while(1){//親の入力がある間
      MySemop(tmpmemory_s_id,1,LOCK);
      if(tmpmemory[0]=='\0')break;
      printf("%s",tmpmemory);
      MySemop(tmpmemory_s_id,0,UNLOCK);
      usleep(1);
    }
  }
  return 0;
}
