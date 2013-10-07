#include<stdio.h>

int main()
{
  char c; c=0;
  for(c=1; c<=126; c++)
    printf("So: %d |%c|.\n", c, c);
  return 0;
}
