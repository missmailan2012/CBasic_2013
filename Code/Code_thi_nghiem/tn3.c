#include<stdio.h>
#include<stdlib.h>

int main()
{
  void* a;
  void* b;
  a = malloc(4*sizeof(char));
  b = a;
  free(b);
  printf("SS\n");
  getchar();
  return 0;
}
