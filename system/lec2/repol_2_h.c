//moreを高水準と低水準で実装するのサンプル
//more 高水準での実装例

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define TN 4
int main(int argc, char* argv[]) {
	FILE* fp = fopen(argv[1], "r");
	do {
		char temp[TN];
		fread(temp, sizeof(char), TN, fp);
		if (feof(fp)) break;
		fwrite(temp, sizeof(char), TN, stdout);
	}while (0 == errno);
	fclose(fp);
	return EXIT_SUCCESS;
}
