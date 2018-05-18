#include <stdio.h>

int main(){
  char apartment_c[3];
  int apartment_i[3];
  long int apartment_il[3];
  double apartment_d[3];
  long double apartment_dl[3];
  short apartment_s[3];
  float apartment_f[3];
  unsigned apartment_u[3];
  
  int i;
  int num;
  printf("\nchar型のマンションについて\n\n");
  num = (int)&apartment_c[2] - (int)&apartment_c[1];
    printf("\tこのマンションに住めるのは%d人家族\n",num);

    printf("\nint型のマンションについて\n\n");
    num = (int)&apartment_i[2] - (int)&apartment_i[1];
    printf("\tこのマンションに住めるのは%d人家族\n",num);
 
   printf("\nlong int型のマンションについて\n\n");  
   num = (int)&apartment_il[2] - (int)&apartment_il[1];
    printf("\tこのマンションに住めるのは%d人家族\n",num);
  
   printf("\ndouble型のマンションについて\n\n");
   num = (int)&apartment_d[2] - (int)&apartment_d[1];
    printf("\tこのマンションに住めるのは%d人家族\n",num);


  printf("\nlong double型のマンションについて\n\n");
  num = (int)&apartment_dl[2] - (int)&apartment_dl[1];
    printf("\tこのマンションに住めるのは%d人家族\n",num);
 

   printf("\nshort型のマンションについて\n\n");
   num = (int)&apartment_s[2] - (int)&apartment_s[1];
    printf("\tこのマンションに住めるのは%d人家族\n",num);

    printf("\nfloat型のマンションについて\n\n");
    num = (int)&apartment_f[2] - (int)&apartment_f[1];
    printf("\tこのマンションに住めるのは%d人家族\n",num);
  

   printf("\nunsigned型のマンションについて\n\n");
   num = (int)&apartment_u[2] - (int)&apartment_u[1];
    printf("\tこのマンションに住めるのは%d人家族\n",num);
  

}
