#include "stack.h"

void newStack(int nSizeOfData, TStack* pStack)
{
  if(true == pointIsNull(pStack))
    {
      MSG("newStack(int nSizeOfData, TStack* pStack): Canh bao: pStack Null!");
      exit(1);
    }
  newSLinkedList(nSizeOfData, pCoreOfStack(*pStack));
  return;
}

void makeEmptyStack(TStack* pStack)
{
  if(true == pointIsNull(pStack))
    {
      MSG("makeEmptyStack(TStack* pStack): Canh bao: pStack Null!");
      exit(1);
    }
  if(true == stackIsEmpty(*pStack))
    {
      MSG("makeEmptyStack(TStack* pStack): Canh bao: pStack da Empty, khong the tien hanh makeEmpty duoc!");
      return;
    }
  deleteFullSLinkedList(pCoreOfStack(*pStack));
  return;
}

void pushStack(void* pContainer, TStack* pStack)
{
  if(true == containerNotReady(pContainer))
    {
      MSG("pushStack(void* pContainer, TStack* pStack): Canh bao: pContainer chua san sang!");
      exit(1);
    }
  if(true == pointIsNull(pStack))
    {
      MSG("pushStack(void* pContainer, TStack* pStack): Canh bao: pStack Null!");
      exit(1);
    }
  if(true == containerNotSyncStack(pContainer, *pStack))
    {
      MSG("pushStack(void* pContainer, TStack* pStack): Canh bao: pContainer vaf pStack khong tuong thich!");
      exit(1);
    }
  addFirtsSLinkedList(pContainer, pCoreOfStack(*pStack));
  return;
}


