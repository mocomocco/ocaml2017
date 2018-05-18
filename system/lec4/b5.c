#include <stdio.h>

struct SET {
	char w[2];
	char m[2];
} set;
int i;
int h=0;

int main() {
  while((i=getchar())!= EOF){
    set.w[h++]=i;
  }

 printf("\nw %s\n", set.w);
  printf("m %s\n", set.m);
  
}
