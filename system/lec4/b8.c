#include <stdio.h>
#include <string.h>

struct SET {
  char w[3];
  char m[3];
  char x[3];
} set;

int i;
FILE *fp;
int main() {
  strcpy(set.x,"ab");
  fgets(set.w,5*sizeof(char),stdin);
  printf("w %s\n", set.w);
  printf("m %s\n", set.m);
  printf("x %s\n",set.x);
  printf("\n");
  fgets(set.m,5*sizeof(char),stdin);
  printf("w %s\n", set.w);
  printf("m %s\n", set.m);
 printf("x %s\n",set.x);
}
