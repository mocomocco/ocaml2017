#include <stdio.h>

struct SET {
	char w[2];
	char m[2];
} set;
int i;
int main() {
  scanf("%s",set.w);
  scanf("%s",set.m);
  printf("\n");
 printf("w %s\n", set.w);
  printf("m %s\n", set.m);
}
