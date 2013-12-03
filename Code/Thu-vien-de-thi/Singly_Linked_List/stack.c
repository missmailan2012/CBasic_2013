#include "stack.h"

TSLinkedList coreOfStack(TStack stack)
{
  TSLinkedList sLinkedListTemp;
  newSLinkedList( stack.memberCore.nSizeOfData , &sLinkedListTemp);
  sLinkedListTemp.pFirts = stack.memberCore.pFirts;
  sLinkedListTemp.pEnd = stack.memberCore.pEnd;
  return sLinkedListTemp;
}
TSLinkedList* pCoreOfStack(TStack stack)
{
  TSLinkedList* pMemberCoreTemp;
  pMemberCoreTemp = &(stack.memberCore);
  return pMemberCoreTemp;
}

boolean stackIsEmpty(TStack stack)
{
  if(0 != (coreOfStack(stack)).nNumberOfNode )
    {
      return false;
    }
  return true;
}
boolean stackNotEmpty(TStack stack)
{
  if(0 == (coreOfStack(stack)).nNumberOfNode )
    {
      return false;
    }
  return true;
}
boolean containerNotSyncStack(void* pContainer, TStack stack)
{
  if(true == containerNotSyncSLinkedList(pContainer, coreOfStack(stack)))
    {
      MSG("boolean containerNotSyncStack(void* pContainer, TStack stack): Cảnh báo: pContainer không tương thích với stack!");
      return true;
    }
  return false;
}
boolean containerIsSyncStack(void* pContainer, TStack stack)
{
  if(true == containerNotSyncStack(pContainer,stack))
    {
      MSG("boolean containerIsSyncStack(void* pContainer, TStack stack): Cảnh báo: pContainer không tương thích với stack!");
      return false;
    }
  return true;
}

void newStack(int nSizeOfData, TStack* pStack)
{
  if(true == pointIsNull(pStack))
    {
      MSG("void newStack(int nSizeOfData, TStack* pStack): Cảnh báo: pStack Null!");
      exit(1);
    }
  newSLinkedList(nSizeOfData, pCoreOfStack(*pStack));
  return;
}

void makeEmptyStack(TStack* pStack)
{
  if(true == pointIsNull(pStack))
    {
      MSG("void makeEmptyStack(TStack* pStack): Cảnh báo: pStack Null!");
      exit(1);
    }
  if(true == stackIsEmpty(*pStack))
    {
      MSG("void makeEmptyStack(TStack* pStack): Cảnh báo: pStack đã Empty, không thể tiến hành makeEmpty được!");
      return;
    }
  deleteFullSLinkedList(pCoreOfStack(*pStack));
  return;
}

void pushStack(void* pContainer, TStack* pStack)
{
  if(true == containerNotReady(pContainer))
    {
      MSG("void pushStack(void* pContainer, TStack* pStack): Cảnh báo: pContainer chưa sẵn sàng!");
      exit(1);
    }
  if(true == pointIsNull(pStack))
    {
      MSG("void pushStack(void* pContainer, TStack* pStack): Cảnh báo: pStack Null!");
      exit(1);
    }
  if(true == containerNotSyncStack(pContainer, *pStack))
    {
      MSG("void pushStack(void* pContainer, TStack* pStack): Cảnh báo: pContainer và pStack không tương thích!");
      exit(1);
    }
  addFirtsSLinkedList(pContainer, pCoreOfStack(*pStack));
  return;
}
void* popStack(void* pContainerOut, TStack* pStack)
{
  if(true == pointIsNull(pStack))
    {
      MSG("void* popStack(void* pContainerOut, TStack* pStack): Cảnh báo: pStack Null!");
      pContainerOut = NULL;
      return pContainerOut;
    }
  if(true == stackIsEmpty(*pStack))
    {
      MSG("void* popStack(void* pContainerOut, TStack* pStack): Cảnh báo: pStack đã rỗng, không thể tiến hành popStack được!");
      pContainerOut = NULL;
      return pContainerOut;
    }
  if(true == pointIsNull(pContainerOut))
    {
      MSG("void* popStack(void* pContainerOut, TStack* pStack): Cảnh báo: pContainerOut Null, dữ liệu sẽ được tải về bởi return hàm!");
      void* pContainerOutTemp;
      pContainerOutTemp = newFullContainer((pStack->memberCore).nSizeOfData );
      syncContainerToContainer(containerOfNode((pStack->memberCore).pFirts), pContainerOut);
      deleteFullFirtsSLinkedList(pCoreOfStack(*pStack));
      return pContainerOutTemp;
    }
  syncContainerToContainer(containerOfNode((pStack->memberCore).pFirts), pContainerOut);
  deleteFullFirtsSLinkedList(pCoreOfStack(*pStack));
  return pContainerOut;
}
void viewTopStack(void* pContainerView, TStack stack)
{
  if(true == stackIsEmpty(stack))
    {
      MSG("void viewTopStack(void* pContainerView, TStack stack): Cảnh báo: stack đã rỗng, không thể tiến hành viewTopStack được!");
      return;
    }
  if(true == pointIsNull(pContainerView))
    {
      MSG("void viewTopStack(void* pContainerView, TStack stack): Cảnh báo: pContainerView Null!");
      return;
    }
  syncContainerToContainer(containerOfNode((stack.memberCore).pFirts), pContainerView);
  return;
}
