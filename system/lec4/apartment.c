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
  printf("\nchar型のマンションについて\n\n");
  for(i=0;i<3;i++){
    printf("\tapartmentの%d家族めの住所は %16p\n", i+1,&apartment_c[i]);
    printf("\n");
 }

    printf("\nint型のマンションについて\n\n");
  for(i=0;i<3;i++){
    printf("\tapartmentの%d家族めの住所は %16p\n", i+1,&apartment_i[i]);
    printf("\n");
 }

   printf("\nlong int型のマンションについて\n\n");
  for(i=0;i<3;i++){
    printf("\tapartmentの%d家族めの住所は %16p\n", i+1,&apartment_il[i]);
    printf("\n");
 }
   printf("\ndouble型のマンションについて\n\n");
  for(i=0;i<3;i++){
    printf("\tapartmentの%d家族めの住所は %16p\n", i+1,&apartment_d[i]);
    printf("\n");
 }

  printf("\nlong double型のマンションについて\n\n");
  for(i=0;i<3;i++){
    printf("\tapartmentの%d家族めの住所は %16p\n", i+1,&apartment_dl[i]);
    printf("\n");
 }

   printf("\nshort型のマンションについて\n\n");
  for(i=0;i<3;i++){
    printf("\tapartmentの%d家族めの住所は %16p\n", i+1,&apartment_s[i]);
    printf("\n");
 }

    printf("\nfloat型のマンションについて\n\n");
  for(i=0;i<3;i++){
    printf("\tapartmentの%d家族めの住所は %16p\n", i+1,&apartment_f[i]);
    printf("\n");
 }

   printf("\nunsigned型のマンションについて\n\n");
  for(i=0;i<3;i++){
    printf("\tapartmentの%d家族めの住所は %16p\n", i+1,&apartment_u[i]);
    printf("\n");
 }

}
