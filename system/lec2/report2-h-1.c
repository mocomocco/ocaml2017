#include<stdio.h>
#include<errno.h>

int main(int argc,char* argv[]){
  FILE* fp;
  int num=1;/*numを宣言した理由とnum=1とした理由については後述*/
  char a[num];/*変数を宣言*/

  fp=fopen(argv[1],"r");/*引数として与えられた文字列と一致するファイルを開く*/

  if(fp==NULL)
    fwrite ("Missing filename",sizeof(char),16,stderr);
  /*もしファイルがなかったら"Missing filename"と返す(moreでMissing filename ("less --help" for help)と帰ってくるのに準拠した)*/

  while(!errno){/*エラーがなければ*/
    /*※1*/

    fread(a,sizeof(char),num,fp);
    /*fpの今いる場所(最初の読み込みの時は一番最初)からchar型の文字をnum文字分aに読み込む*/
    /*※2*/

    if(feof(fp))break;
    /*aを読んでいる途中でファイル末尾にたどり着いたときループから出る。*/
    /*※3*/
    /*※2*/
    fwrite(a,sizeof(char),num,stdout);
    /*char型の文字列aを標準出力する*/
  }
  fwrite("\n",sizeof(char),1,stdout);
  /*moreコマンドではファイルの内容を出力した後行替えも出力されているのでここで行替えを出力した。*/
  fclose(fp);
}
