#include<stdio.h>
#include<stdlib.h>

typedef struct
{
  char string[25];
}data;

int main()
{
  data a, *b;
  gets(a.string);
  b=(data*)malloc(sizeof(data));
  *b=a;
  printf("%s",b->string);
  return 0;
}
