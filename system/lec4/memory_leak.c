#include <stdio.h>
#include <stdlib.h>


int main() {
	int i = 0;
	while (1) {
		printf("%d\n",i++);
		int *m = (int*)malloc(sizeof(int) * 200000000);
	}
	return 0;
}
