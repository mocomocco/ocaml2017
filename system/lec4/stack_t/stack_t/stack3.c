#include <stdio.h>
int a=0;
void func(int x) {
	int m[100000];
	printf("%p\n",func);	
}

int main() {
  for(a=0;a<200;a++){
    func(a);
}
}
