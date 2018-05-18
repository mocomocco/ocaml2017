#include <stdio.h>

struct SET {
  char w[3];
  char m[3];
  char x[3];
} set;

int i;
FILE *fp;
int main() {
  fgets(set.w,sizeof(set.w),stdin);
    printf("w %s\n",set.w);
    printf("m %s\n",set.m);
    printf("x %s\n",set.x);

  fgets(set.m,sizeof(set.m),stdin);
  printf("\n");
  printf("w %s\n",set.w);
  printf("m %s\n",set.m);
  printf("x %s\n",set.x);

}
