#include<stdio.h>
#include<stdlib.h>

int main()
{
  int a, b;; a=5;
  void *ptr1, *ptr2;
  ptr1=&a;
  ptr2=&b;
  char temp;
  temp=sizeof(int);
  printf("Char: %d\n", sizeof(char));
  while(temp--)
    {
      *((char*)ptr2)=*((char*)ptr1);
      ptr1++;
      ptr2++;
    }
  printf("So do la %d:",b);
  return 0;
}
