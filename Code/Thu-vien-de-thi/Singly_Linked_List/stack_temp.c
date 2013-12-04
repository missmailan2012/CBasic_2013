#include "stack.h"

int main()
{
  TStack stack;
  char count;
  char* ch;

  newStack(sizeof(char), &stack);
  void* pContainerTemp;
  pContainerTemp = newFullContainer(sizeof(char));
  ch = (char*)addBlocksDataOfContainer(pContainerTemp);
  for(count = 0; count < 6; count++)
    {
      MSG("Ban hay nhap vao mot so: ");
      scanf("%c", ch);
      while( getchar() != '\n');
      pushStack(pContainerTemp, &stack);
    }
  for(count = 0; count < 6; count++)
    {
      printf("So phan tu cua stack: %d\n", stack.memberCore.nNumberOfNode);
      popStack(pContainerTemp, &stack);
      printf("%c----\n", *ch);
    }
  getchar();
  return 0;
}
