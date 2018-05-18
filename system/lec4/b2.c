#include <stdio.h>

struct SET {
	char w[2];
	char m[2];
} set;
int i;
int main() {
  for(i=0;i<5;i++)printf("set.w[%d] : %p\n", i,&set.w[i]);
  for(i=0;i<5;i++)printf("set.m[%d] : %p\n", i,&set.m[i]);
}
