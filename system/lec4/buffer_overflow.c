#include <stdio.h>
#include <string.h>

struct SET {
	char w[2];
	char m[2];
} set;

int main() {
	strcpy(set.w, "mmmm");
	strcpy(set.m, "wwww");

	printf("m %s\n", set.m);
	printf("w %s\n", set.w);

	printf("%08x\n", set.m);
	printf("%08x\n", set.w);

	return 0;
}
