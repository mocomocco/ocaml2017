#include <stdio.h>

struct SET {
	char w[2];
	char m[2];
} set;
int i;
FILE *fp;
int main() {
  fp=fopen("sentence.c","r");
  fscanf(fp,"%s",set.m);
  fscanf(fp,"%s",set.w);
  printf("\n");
 printf("w %s\n", set.w);
  printf("m %s\n", set.m);
  fclose(fp);
}
