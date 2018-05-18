#include <stdio.h>
#include <string.h>

struct SET {
	char m[2];
	char w[2];
} set;

void my_strcpy(char *a,char *b,int n){
  for(int i = 0; i<n;i++){
    a[i]=b[i];
  }
  return;
}
int main() {
  my_strcpy(set.w, "w",2);
  my_strcpy(set.m, "abcde",2);

	printf("m %s\n", set.m);
	printf("w %s\n", set.w);

	printf("%08x\n", set.m);
	printf("%08x\n", set.w);

	return 0;
}
