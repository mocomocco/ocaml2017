#include <stdio.h>

void func(int x) {
	x += 1;
	int m;
	printf("%d %p %p\n",x, &m,func);
	if (x > 3) {
		return;
	}
	func(x);
}

int main() {
  int m;
  printf("%p\n",&m);
	func(0);
	return 0;
}
