#include<stdio.h>
#include<string.h>

int main()
{
  char chuoi[20];
  gets(chuoi);
  printf("do dai cua mang la: %d", strlen(chuoi));
  printf("Do la ki tu: %c", chuoi[strlen(chuoi)-1]);
  return 0;
}
