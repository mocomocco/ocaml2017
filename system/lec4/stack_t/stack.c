#include <stdio.h>

void func(int x) {
  static int i;
  printf("%d\n",i++);
  int m[1000000];
  x=i;
  printf("%d %08x\n",x, func);
  if (x > 210) {
    return;
  }
  func(x);
}

int main() {
  int i=1;
  func(0);
	/*return 0;*/
}
