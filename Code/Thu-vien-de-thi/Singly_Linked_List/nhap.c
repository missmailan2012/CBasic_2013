#include<stdio.h>
#include<string.h>

int main()
{
  char s1[100];
  char s2[100];
  printf("Nhap s1: ");
  gets(s1);
  printf("Nhap s2: ");
  gets(s2);
  printf("s1: %s\ns2: %s\nstrcmp: %d\n", s1, s2, strcmp(s1, s2));
  getchar();
  return 0;
}
