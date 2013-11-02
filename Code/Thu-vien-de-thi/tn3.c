#include "stack.h"

int main()
{
  stack a;
  Init_stack(&a,sizeof(int));
  blocks buff;
  int i, b;
  buff.adress=&b;
  buff.size=sizeof(int)+sizeof(blocks);
  for(i=0; i<5; i++)
    {
      printf("Ban hay nhap vao mot so nao do: ");
      scanf("%d", &b);
      while(getchar()!= '\n');
      Push(buff,&a);
    }
  for(i=0; i<=6; i++)
    {
      printf("Pop!\n");
      Pop(&buff,&a);
      printf("So: %d\n", *(int*)(buff.adress));
    }
  return 0;
}
