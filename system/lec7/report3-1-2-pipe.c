#include <stdio.h>
#include <unistd.h>

int main(int argc,char *filename[]){
  pid_t cid0=0,cid1=1;
  char tmp[260],waita[3];
  int fdp[2],fda[2];

  if(argc==1){
    printf("No commandline option!\n");
    return 0;
  }
  pipe(fdp);//パイプ開通
  pipe(fda);
   
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

    while(fgets(tmp,sizeof(tmp),fp)!=NULL){//ファイルが終わるまで
      printf("P:%s",tmp);
      write(fdp[1], tmp,260);
      read(fda[0],waita,260);//Aを待つ
    }
    fclose(fp);
    return 0;
  }
  if(cid0 == 0 && cid1 ==1){//Aだったら
    while(read(fdp[0],tmp,260)>0){//親の入力がある間
     printf("A:%s",tmp);
      write(fda[1],"g",3);//出力が終わったことを親に伝える。
      sleep(1);//1秒待つ
    }
    return 0;
  }
 }
