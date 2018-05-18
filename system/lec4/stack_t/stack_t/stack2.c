#include <stdio.h>

void func(int x) {
	int m[100000];
	printf("%p\n",func);
	if (x > 200) {
		return;
	}
	func(x);
}

int main() {
	func(0);
	return 0;
}
