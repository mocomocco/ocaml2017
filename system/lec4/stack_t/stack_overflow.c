#include <stdio.h>

void func(int x) {
	x += 1;
	int m[2000000];
	printf("%d %08x\n",x, func);
	if (x > 210) {
		return;
	}
	func(x);
}

int main() {
	func(0);
	return 0;
}
