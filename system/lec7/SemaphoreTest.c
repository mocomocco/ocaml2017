#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <stdlib.h>
/*
union semun{
  int val;
  struct semid_ds *buf;
  unsigned short int *array;
  struct seminfo *__buf;
};
*/
int main(){
  //create shared memory
  key_t key = IPC_PRIVATE;

  size_t size = 1024;
  int shmflg = IPC_CREAT | S_IRWXU;
  int id;
  id = shmget(key, size, shmflg);

  //init semaphore
  union semun seminit;
  struct sembuf semlock;
  struct shmid_ds sembuf;
  int sid;
  sid = semget(id,1,shmflg);
  seminit.val = 1;
  semctl(sid,0,SETVAL,seminit);
  semlock.sem_num = 0;
  semlock.sem_op=0;
  semlock.sem_flg=0;

  //attach
  int *num;
  num = (int*)shmat(id,0,0);
  *num = 0;

  //make process
  int i;
  pid_t pid = fork();
  if(pid==0){//child
    num = (int*)shmat(id,0,0);
    int i;
    for(i=0;i<20;i++){
      semlock.sem_op=-1;
      semop(sid,&semlock,1);//lock
      int temp = *num;
      usleep(5000);
      temp += 2;
      *num = temp;
      semlock.sem_op=1;
      semop(sid,&semlock,1);//unlock
      printf("c:%d\n",*num);
    }
    _Exit(0);
  }

  for(i=0;i<20;i++){
    semlock.sem_op=-1;
    semop(sid,&semlock,1);//lock
    int temp = *num;
    usleep(5000);
    temp += 1;
    *num = temp;
    semlock.sem_op=1;
    semop(sid,&semlock,1);//unlock
    printf("p:%d\n",*num);
  }

  //detach
  shmdt(num);
  //destroy
  shmctl(id,IPC_RMID,0);
  //delete sempho
  semctl(sid,IPC_RMID,0);
  return 0;
}
