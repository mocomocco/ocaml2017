#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

bool recfork(int c, const int m) {//引数として変数のcと定数のmを受け取った。
	if (c == m) return true;
	/*	printf("スタート:c=%d\n",c);*/
	/*	pid_t cid=fork();*/
	printf("%d %d %d\n", c, fork(),getpid());
	//親プロセスには子プロセスのPIDが、子プロセスのは0が返される。
	recfork(c+1,m);
	return false;
}

int main() {
	recfork(0, 5);
	return 0;
}
