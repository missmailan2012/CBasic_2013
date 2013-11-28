#include "singly_linked_list.h"

typedef struct
{
  TSLinkedList memberCore;
}TStack;

boolean containerIsSyncStack(void* pContainer, TStack stack);
boolean containerNotSyncStack(void* pContainer, TStack stack);

void newStack(int nSizeOfData, TStack* pStack);
void makeEmptyStack(TStack* pStack);
void pushStack(void* pContainer, TStack* pStack);
void* popStack(void* pNodeOut, TStack* pStack);
void* viewTopStack(void* pNodeView, TStack stack);
boolean stackIsEmpty(TStack stack);
boolean stackNotEmpty(TStack stack);
TSLinkedList coreOfStack(TStack stack);
TSLinkedList* pCoreOfStack(TStack stack);
