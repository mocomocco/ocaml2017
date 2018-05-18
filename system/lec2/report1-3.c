#include<stdio.h>

int main(){
  FILE* fp;
  int X,Y,i;
  char a[10];
  fp = fopen("report_sup","r");
  /*report_supを開く*/
  
  fseek(fp,-1*sizeof(char),SEEK_END); /*report_supの一番最後の文字を読みたいので、最後の「文字が始まる前」のところに移動*/
  fread(&X,sizeof(char),1,fp);  /*ファイルに書き込まれている数字はchar型として書き込まれているのでそれをint型に変換したい。  
itoaコマンドを使っても良いが、1~9の範囲内ならX=X-48("0"=48だから)とすれば成り立ったので、そうする*/
  X=X-48;

  fwrite("数字を入力してください\n",sizeof(char),34,stdout);
  scanf("%d",&Y);/*入力された数字をYとする。*/
 
  for(i=0;i<X;i++){  /*X回繰り返す*/
    fseek(fp,-1*(Y+1)*sizeof(char),SEEK_CUR);   /*Y [char長]だけ前に戻った時の、「文字が始まる前」のところに移動*/
    fread(a,sizeof(char),1,fp);   /*char型のの文字を一文字読む*/
    fwrite(a,sizeof(char),1,stdout);
    fwrite("\n",sizeof(char),1,stdout);   /*読み込んだ文字と改行を標準出力*/
  }
   
  fclose(fp);  /*fpを閉じる*/
}
