#include <stdio.h>
 
void main()
{
    int a; /* 普通の変数の宣言 */ 
    int *p;   /* ポインタ変数の宣言 */
    int b;
    int c;

    a = 3;
    printf("aのアドレスは，%p です\n", &a);  
   printf("ポインタ変数pの値（=aのアドレス）は，%p です\n", p); 
printf("bの値（=aのアドレス）は，%p です\n", &b); 
printf("cの値（=aのアドレス）は，%p です\n", &c); 

 b = a;
    printf("bの値（=aのアドレス）は，%p です\n", &b);  
    printf("bの指している値は，%d です\n", b);  
    &c = &a;
    printf("cの値（=aのアドレス）は，%p です\n", &c);  
    printf("cの指している値は，%d です\n", c);  

    p = &a;
    printf("ポインタ変数pの値（=aのアドレス）は，%p です\n", p);  
    printf("ポインタ変数pの指している値は，%d です\n", *p);  
}
