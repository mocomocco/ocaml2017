#include<stdio.h>

int main(){
  FILE* fp;
  char a[10];
  fp=fopen("aaa","r");
  /*読み込んでるのは最初*/
  fseek(fp,20*sizeof(char),SEEK_SET);
  /*読み込みの位置が三番目になった*/
  fread(X,sizeof(char),1,fp);
  printf("%s\n",a);
  fseek(fp,0*sizeof(char),SEEK_END);
  fread(a,sizeof(char),1,fp);
  printf("%s\n",a);
  fclose(fp);
}
