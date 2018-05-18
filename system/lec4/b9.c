#include <stdio.h>


struct SET {
  char w[3];
  int m;
} set;

char str[20];

int main() {
  set.m=1;
  scanf("%s",str);
  sscanf(str,"%s ",set.w);
  printf("w %s\n", set.w);
  printf("m %d\n", set.m);

}
