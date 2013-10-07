#include<stdio.h>
#include<stdlib.h>

int main(void)
{
  int i, n, *p;
  printf("How many numbers do you want to enter?\n");
  scanf("%d", &n);
  while( getchar() != '\n');
  p=(int*)malloc(n*sizeof(int));
  if( p == NULL)
    {
      printf("Memory allocation failed!\n");
      return 1;
    }
  for( i=0;i<n;i++)
    {
      printf("Ban hay nhap vao mot so: ");
      scanf("%d",p);
      p++;
    }
  for(i=0;i<n;i++)
    {
      p--;
    }
  for( i=0; i<n;i++)
    {
      printf("%d\n",*p++);
    }
  for( i=0;i<n;i++)
    {
      p--;
    }
  free(p);
  return 0;
}
