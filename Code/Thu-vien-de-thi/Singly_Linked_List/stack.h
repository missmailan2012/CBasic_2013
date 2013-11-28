#include "singly_linked_list.h"

typedef struct
{

}

void newStack(int nSizeOfData, TStack* pStack);
void makeEmptyStack(TStack* pStack);
void pushStack(void* pContainer, TStack* pStack);
void* popStack(void* pNodeOut, TStack* pStack);
void* viewTopStack(void* pNodeView, TStack stack);
boolean stackIsEmpty(TStack stack);
TSlinkedList coreOfStack();
