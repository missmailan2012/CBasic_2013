#include "singly_linked_list.h"

typedef struct
{
  TSLinkedList memberCore;
}TStack;

TSLinkedList coreOfStack(TStack stack);
void* pCoreOfStack(TStack* pStack);

boolean stackIsEmpty(TStack stack);
boolean stackNotEmpty(TStack stack);
boolean containerIsSyncStack(void* pContainer, TStack stack);
boolean containerNotSyncStack(void* pContainer, TStack stack);

void newStack(int nSizeOfData, TStack* pStack);
void makeEmptyStack(TStack* pStack);
void pushStack(void* pContainer, TStack* pStack);
void* popStack(void* pContainerOut, TStack* pStack);
void viewTopStack(void* pContainerView, TStack stack);


