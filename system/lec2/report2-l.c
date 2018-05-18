#include<errno.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc,char* argv[]){
  int num=1,x;
  int fp;
  char a[num];/*変数を宣言*/

  fp=open(argv[1],O_RDONLY);/*引数として与えられた文字列と一致するファイルを読み込み専用で開く*/

  if(fp < 0)
    write (STDERR_FILENO,"Missing Filename",16*sizeof(char));
    /*もしファイルがなかったら"Missing Filename"と返す(moreでMissing Filename("less --help" for help)とかえってくるのに準拠した。*/
  
  while(!errno){/*エラーがなければ*/
    /*※１*/
    x=read(fp,a,num);/*ファイルの今いる場所(最初の読み込みの時は一番最初)からnum文字分aに格納*/
    /*※2*/

    if(!x)break;
    /*読み込む文字列がなくなったらループから出る。*/
    /*※3*/
    /*※2*/
    write(STDOUT_FILENO,a,num);
    /*文字列aを標準出力*/
  }
   write (STDOUT_FILENO,"\n",1*sizeof(char));
   /*moreコマンドではファイルの内容を出力した後行替えされているのでここで行替えを出力した*/
   close(fp);
}
