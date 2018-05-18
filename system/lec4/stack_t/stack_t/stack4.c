#include <stdio.h>
int a=0;
void func(int x) {
	int m[2000000];
	printf("%d %p\n",x, func);	
}

int main() {
  for(a=0;a<1000;a++){
    printf("before func :%p\n\n",func);
    func(a);
    printf("after func :%p\n\n",func);
}
}
