#include <stdio.h>

struct SET {
	char w[3];
	char m[3];
} set;
int i;
FILE *fp;
int main() {
  fgets(set.w,sizeof(set.w),stdin);
  for(i=0;i<5;i++)
    printf("w[%d] %c\n",i,set.w[i]);
  for(i=0;i<5;i++)
    printf("m[%d] %c\n",i,set.m[i]);
  fgets(set.m,sizeof(set.m),stdin);
  printf("\n");
  for(i=0;i<5;i++)
    printf("w[%d] %c\n",i,set.w[i]);
  for(i=0;i<5;i++)
    printf("m[%d] %c\n",i,set.m[i]);
  printf("w %s\n", set.w);
  printf("m %s\n", set.m);

}
