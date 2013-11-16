#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// 1-Cau truc du lieu;
typedef struct
{
  void* pBlocksData;
  int nSizeOfData;
}TContainer;

typedef struct
{
  void* pNext;
  TContainer data;
}TNode;

typedef struct
{
  int nNumberOfNode;
  void* firts;
  void* end;
}TSLinkedList;

enum {false, true};
typedef char boolean;


// 2-Cac toan tu;

//++++ 2-1 void* new
//-------- 2-1-1 void* newquick
boolean sizeIsTrue(int nSize); // できます
boolean sizeIsFalse(int nSize);

boolean pointIsNull(void* p); // できます
boolean pointNotNull(void* p);

void* newBlocks(int nSizeBlocks); // できます
void* newQuickContainer(); // できます
void* newQuickNode(); // できます

//-------- 2-1-2 void* newfull
void* newFullContainer(int nSizeOfData); // できます
void* newFullNode(int); // できます



//++++ 2-2 void delete

//-------- 2-2-1 void deletequick
void deleteQuickContainer(void** pContainer); // できます
void deleteQuickNode(void*** pNode); // できます

//-------- 2-2-2 void deletefull
void deleteFullContainer(void** pContainer); // できます
void deleteFullNode(void** pNode); // できます

//++++ 2-3 boolean check


// 3-Cac ham;
//++++ 3-0 Cac ham so cap

boolean containerIsReady(void* pContainer); // できます
boolean containerNotReady(void* pContainer); //　できます

boolean nodeIsReady(void* node); //　できます
boolean nodeNotReady(void* node); //　できます

boolean containerIsSyncNode(void* container, void* node); // できます
boolean containerNotSyncNode(void* container, void node); //　できます

boolean nodeIsSyncNode(void* node1, void* node2); // できます
boolean nodeNotSyncNode(void* node1, void* node2); //　できます

boolean nodeIsSyncSLinkedList(void* node, TSLinkedList sll); // できます
boolean nodeNotSyncSLinkedList(void* node, TSLinkedList sll); //　できます

boolean containerIsSyncSLinkedList(void* container, TSLinkedList sll); // できます
boolean containerNotSyncSLinkedList(void* container, TSLinkedList sll); //　できます

boolean containerIsSyncContainer(void* container1, void* container2); // できます
boolean containerNotSyncContainer(void* container1, void* container2); // できます
void cpyBlocksToBlocks(void* blocks1, void* blocks2, int nSizeOfBlocks); // できます
void syncNodeToNode(void* node1, void* node2); // できます
void syncContainerToContainer(void* container1, void* container2); // できます
void syncContainerToNode(void* pContainer, void* pNode); // できます
void syncNodeToContainer(void* pNode, void* pContainer); // できます
void linkedNodeToNode(void* pNode1, void* pNode2); // できます
void* elementi(int i, TSLinkedList pSll); //　できます
void* prewCurr(void* pCurr, TSLinkedList sll); // できます
void* nextCurr(void* pCurr, TSLinkedList sll); // できます
void* newFullNodeForAdd(void* pContainerAdd); // できます



//++++ 3-1 void newSLinkedList
void newSLinkedList(int nSizeOfData, TSLinkedList* pSll); // できます

//++++ 3-2 void add
void addFirtsSLinkedList(void* pContainerAdd, TSLinkedList* pSll); // できます
void addEndSLinkedList(void* pContainerAdd, TSLinkedList* pSll); // できます
void addNextCurrSLinkedList(void* pContainerAdd, void* pCurr, TSLinkedList* pSll); // できます
void addPrewCurrSLinkedList(void* containerAdd, void* curr, TSLinkedList* a); // できます

//++++ 3-3 void delete

//-------- 3-3-1 void deletequick
//-------- 3-3-2 void deletefull
void deleteFullFirtsSLinkedList(TSLinkedList* pSll); // できます
void deleteFullEndSLinkedList(TSLinkedList* pSll); // できます
void deleteFullCurr(void* pCurr, TSLinkedList* pSll); // できます
void deleteFullPrewCurr(void* pCurr, TSLinkedList* pSll); //　できます
void deleteFullNextCurr(void* pCurr, TSLinkedList* pSll); // できます
void deleteFullSLinkedList(TSLinkedList* pSll); //　できます
//++++ 3-4 void sortSLinkedList
