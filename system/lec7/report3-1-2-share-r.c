//http://www.c-lang.net/semctl/index.html
/*#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include<sys/stat.h>
#include<sys/sem.h>

#define LOCK -1
#define UNLOCK 1
#define WAIT 0*/

/* セマフォ操作（ロック/アンロック） */
/*void MySemop(int semid,int semnum,int op)
{
  struct sembuf sops;

  sops.sem_num = semnum;    */      /* セマフォ番号 */
//sops.sem_op = op;               /* セマフォ操作 */
//sops.sem_flg = 0;                 /* 操作フラグ */

//  semop(semid,&sops,1);
  //semid 操作するセマフォ集合のセマフォID sops セマフォ操作の内容　nsops sopsの要素数
  
// return;
//}

/*int main(int argc,char *filename[]){
  char tmp[260],waita[3],*tmpmemory,*signalmemory;
  key_t key = IPC_PRIVATE;
  size_t size = 1024;
  int shmflg = IPC_CREAT | S_IRWXU,tmpmemory_id,signalmemory_id;
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
  tmpmemory_s_id = semget(tmpmemory_id,1,shmflg);
  //key->IRC_PRIVATE,nsems->セマフォの数 shmflg->IRC_CREATE|アクセス権
  seminit.val = 1;
  //セマフォに初期値を設定
  semctl(tmpmemory_s_id,0,SETVAL,seminit);
  //semidに操作するセマフォのid semnum操作するセマフォの番号、 cmdには操作の種類
  semlock.sem_num = 0;
  //セマフォ番号
  semlock.sem_op=0;
  //セマフォ操作
  semlock.sem_flg=0;
  //操作フラグ

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
      //     semlock.sem_op=-1;
      //semop(tmpmemory_s_id,&semlock,1);
      if(fgets(tmpmemory,sizeof(char)*2048,fp)==NULL){
	MySemop(tmpmemory_s_id,0,LOCK);
	break;
      }
      MySemop(tmpmemory_s_id,0,UNLOCK);
      //semlock.sem_op=1;
      //semop(tmpmemory_s_id,&semlock,1);
      printf("P:%s",tmpmemory);
      usleep(460);
    }
    fclose(fp);
    exit(1);
  }



  int i=30;
  if(cid0 == 0 && cid1 ==1){//Aだったら
    usleep(600);
    while(i){//親の入力がある間
      MySemop(tmpmemory_s_id,0,LOCK);
      //semlock.sem_op=-1;
      //semop(tmpmemory_s_id,&semlock,1);
      usleep(460);
      //sleep(1);//1秒待つ
      i--;
      MySemop(tmpmemory_s_id,0,UNLOCK);
      //semlock.sem_op=1;
      //semop(tmpmemory_s_id,&semlock,1);
      printf("A:%s",tmpmemory);
    }
    exit(1);
  }

  shmdt(tmpmemory);
  //IDとメモリを切り離し
  shmctl(tmpmemory_id,IPC_RMID,0);
  //メモリ解放
  semctl(tmpmemory_s_id,IPC_RMID,0);
  //セマフォ解放
  return 0;
}
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/sem.h>
#define LOCK -1
#define UNLOCK 1
/* セマフォ操作（ロック/アンロック） */
void MySemop(int SemId,int SemNum,int SemOp);

int main()
{
  FILE               *fp;
  int                semid;
  union semun {
    int              val;     /* SETVAL の値 */
    struct semid_ds  *buf;    /* IPC_STAT， IPC_SET 用のバッファ */
    unsigned short   *array;  /* GETALL， SETALL 用の配列 */
  } ctl_arg;
unsigned short     vals[2] = {0,0};  /* セマフォの初期値 */
  char               *file = "writeme.txt";
  int                child_cnt;
  int                line_cnt;

  /* ２つのセマフォを持つセマフォ集合を新規作成 */
semid = semget(IPC_PRIVATE,2,0600);

  /* 全てのセマフォに初期値（0）を設定 */
  ctl_arg.array = vals;
semctl(semid,0,SETALL,ctl_arg);
  /* １つ目の子プロセスを生成 */
  if (fork() == 0) {
    /* 子プロセス */
    printf("子プロセス１開始\n");
/*
fp = fopen(file,"w");
    for (line_cnt = 1;line_cnt <= 5; ++line_cnt) {
fprintf(fp,"子プロセス１のメッセージ%d\n",line_cnt);
      sleep(1);
    }
    fclose(fp);*/
     FILE *fp;
    fp=fopen(filename[1],"r");
    if(fp==NULL){
      printf("cannot find :%s\n",filename[1]);
      return 0;
    }
while(1){
      if(fgets(tmpmemory,sizeof(char)*2048,fp)==NULL){
	break;
      }

    /* 待ち合わせ */
MySemop(semid,1,UNLOCK);    /* 子プロセス２をアンロック */
MySemop(semid,0,LOCK);      /* 自プロセスをロック */
}

    printf("子プロセス１終了\n");
    exit(EXIT_SUCCESS);
  }

  /* ２つ目の子プロセスを生成 */
  if (fork() == 0) {
    /* 子プロセス */
    char      buff[1024];

    printf("子プロセス２開始\n");

    /* 待ち合わせ */
MySemop(semid,1,LOCK);      /* 自プロセスをロック */
MySemop(semid,0,UNLOCK);    /* 子プロセス１をアンロック */

 if ((fp = fopen(file,"r")) == NULL) {
      perror("子プロセス２ ");
      exit(EXIT_FAILURE);
    }
    printf("子プロセス２：ファイルの内容を表示します\n");
    while (fgets(buff,1024,fp) != NULL) {
      printf("%s",buff);
    }
    fclose(fp);

    printf("子プロセス２終了\n");
    exit(EXIT_SUCCESS);
  }

  /* 親プロセス。子プロセスの終了を待つ */
  for (child_cnt = 0; child_cnt < 2; ++child_cnt) {
    wait(NULL);
  }

  /* セマフォを削除 */
semctl(semid,0,IPC_RMID,ctl_arg) ;

  printf("親プロセス終了\n");
  return EXIT_SUCCESS;
}

/* セマフォ操作（ロック/アンロック） */
void MySemop(int p_semid,int p_semnum,int p_op)
{
  struct sembuf sops[1];

  sops[0].sem_num = p_semnum;          /* セマフォ番号 */
  sops[0].sem_op = p_op;               /* セマフォ操作 */
  sops[0].sem_flg = 0;                 /* 操作フラグ */

semop(p_semid,sops,1);

}
