#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

FILE *openfile(char *filename[]){
  FILE *fp;
    fp=fopen(filename[1],"r");
    if(fp==NULL){
      printf("cannot find :%s\n",filename[1]);
      return 0;
    }
    //引数として与えられたファイルを開いた

    return fp;
}

int main(int argc,char *filename[]){


  if(argc==1){
    printf("No commandline option!\n");
    return 0;
  }

  pid_t cid0=0,cid1=1;
  char tmp[260],waita[3],buf[3],waitp[3];
  int fdp[2],fda[2],fdb[2],fdba[2],signal=1,fdab[2];
  pipe(fdp);//パイプ開通
  pipe(fda);
  pipe(fdb);
  pipe(fdba);
  pipe(fdab);

  fcntl(fdb[0],F_SETFL,O_NONBLOCK);
  fcntl(fdb[1],F_SETFL,O_NONBLOCK);
  fcntl(fdba[0],F_SETFL,O_NONBLOCK);
  //  fcntl(fdba[1],F_SETFL,O_NONBLOCK);


  cid0 = fork();//Aを作る
  if (cid0 != 0){cid1=fork();}//Bを作る(ここでif文にしないと子プロセスが全体で3個できてしまう)

  if(cid0 != 0 && cid1 != 0){//親だったら
    FILE *fp=openfile(filename);
      while(1){//ファイルが終わるまで
	if(signal==1){
	if(fgets(tmp,sizeof(tmp),fp)==NULL)break;
	}
     if(read(fdba[0],buf,sizeof(char)*3)>0){
       //printf("Pa:%s",buf);
	if(strcmp(buf,"a\n")==0)signal=0;
	if(strcmp(buf,"b\n")==0)signal=1;
	if(strcmp(buf,"c\n")==0){printf("stopp\n");return 0;}
	// write(fdab[1],buf,sizeof(char)*3);
     }

     /* printf("P:%s",tmp);*/ //チェック用
       write(fdp[1], tmp,260);
      read(fda[0],waita,260);//Aを待つ
      }

    fclose(fp);
    return 0;
  }
  if(cid0 == 0 && cid1 ==1){//Aだったら
    while(1){//親の入力がある間
      if(read(fdp[0],tmp,260)<=0)break;
      if(signal==1)printf("%s",tmp);

      sleep(1);//1秒待つ
      write(fda[1],"g",3);//出力が終わったことを親に伝える。
      if(read(fdb[0],buf,sizeof(char)*3)>0){
      //	read(fdab[0],waitp,sizeof(char)*3);
 	write(fdba[1],buf,sizeof(char)*3);
       	//printf("A:%s",buf);
	if(strcmp(buf,"a\n")==0)signal=0;
	if(strcmp(buf,"b\n")==0)signal=1;
	if(strcmp(buf,"c\n")==0){printf("stopA\n");return 0;}
      }

    }
    return 0;
  }
  if(cid0 != 0 && cid1 ==0){//Bだったら

 while(strcmp(buf,"c\n")!=0){
      buf[0]='\0';
      buf[1]='\0';
      buf[2]='\0';
      if(read(STDIN_FILENO,buf,sizeof(char)*3)!=-1){
	//printf("C:%s",buf);
      write(fdb[1], buf,3);
      if(strcmp(buf,"c\n")==0){printf("stopc\n");return 0;}
      }
 }

}
}
