#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
  void* pBlocksData;
  int nSizeOfData;
}TContainer;

typedef struct
{
  void* pNext;
  TContainer memberData;
}TNode;

typedef struct
{
  int nNumberOfNode;
  int nSizeOfData;
  void* pFirts;
  void* pEnd;
}TSLinkedList;

enum {false, true};
typedef char boolean;

typedef struct
{
  void* pNodeResult;
  int iLocation;
}TSearchResult;

void MSG(char* pString);

boolean sizeIsTrue(int nSize); //
boolean sizeIsFalse(int nSize); //

boolean pointIsNull(void* p); // 
boolean pointNotNull(void* p); //

void* newBlocks(int nSizeBlocks); // 
void* newQuickContainer(); //
void* newQuickNode(); // 

void* newFullContainer(int nSizeOfData); // 
void* newFullNode(int nSizeOfData); // 

void deleteQuickContainer(void** pContainer); // 
void deleteQuickNode(void** pNodeDelete); // 

void deleteFullContainer(void** pContainer); // 
void deleteFullNode(void** pNodeDelete); // 

boolean containerIsReady(void* pContainer); //
boolean containerNotReady(void* pContainer); //

boolean nodeIsReady(void* pNode); //
boolean nodeNotReady(void* pNode); //　

boolean containerIsSyncNode(void* pContainer, void* pNode); // 
boolean containerNotSyncNode(void* pContainer, void* pNode); //　

boolean nodeIsSyncNode(void* pNode1, void* pNode2); // 
boolean nodeNotSyncNode(void* pNode1, void* pNode2); //

boolean nodeIsSyncSLinkedList(void* pNode, TSLinkedList sll); // 
boolean nodeNotSyncSLinkedList(void* pNode, TSLinkedList sll); //　

boolean containerIsSyncSLinkedList(void* pContainer, TSLinkedList sll); // 
boolean containerNotSyncSLinkedList(void* pContainer, TSLinkedList sll); //　

boolean containerIsSyncContainer(void* pContainer1, void* pContainer2); // 
boolean containerNotSyncContainer(void* pContainer1, void* pContainer2); // 

void cpyBlocksToBlocks(void* pBlocks1, void* pBlocks2, int nSizeOfBlocks); //

void syncNodeToNode(void* pNode1, void* pNode2); // 
void syncContainerToContainer(void* pContainer1, void* pContainer2); // 
void syncContainerToNode(void* pContainer, void* pNode); // 
void syncNodeToContainer(void* pNode, void* pContainer); //

void linkedNodeToNode(void* pNode1, void* pNode2); //

void* elementi(int i, TSLinkedList sll); //　
void* prewCurr(void* pCurr, TSLinkedList sll); // 
void* nextCurr(void* pCurr, TSLinkedList sll); //
void* addBlocksDataOfContainer(void* pContainer);
void* addBlocksDataOfNode(void* pNode);
void* containerOfNode(void* pNode);

void* newFullNodeForAdd(void* pContainerAdd); // 

void newSLinkedList(int nSizeOfData, TSLinkedList* pSll); // 

void addFirtsSLinkedList(void* pContainerAdd, TSLinkedList* pSll); // 
void addEndSLinkedList(void* pContainerAdd, TSLinkedList* pSll); // 
void addNextCurrSLinkedList(void* pContainerAdd, void* pCurr, TSLinkedList* pSll); // 
void addPrewCurrSLinkedList(void* containerAdd, void* curr, TSLinkedList* a); // 

void deleteFullFirtsSLinkedList(TSLinkedList* pSll); // 
void deleteFullEndSLinkedList(TSLinkedList* pSll); // 
void deleteFullCurr(void** pCurr, TSLinkedList* pSll); // 
void deleteFullPrewCurr(void* pCurr, TSLinkedList* pSll); //　
void deleteFullNextCurr(void* pCurr, TSLinkedList* pSll); // 
void deleteFullSLinkedList(TSLinkedList* pSll); //　

void swapDataOfContainerAndContainer(void* pContainerA, void* pContainerB); //
void swapDataOfNodeAndNode(void* pNodeA, void* pNodeB); //
void swapDataOfContainerAndNode(void* pContainer, void* pNode); //

void displayInfoOfContainer(void* pContainer, void displayInfo(void* pBlocksData)); //
void displayInfoOfNode(void* pNode, void displayInfo(void* pBlocksData)); //
void showSLinkedList(int nNumberElementDisplay, void displayInfo(void* pBlocksData), TSLinkedList sll);

TSearchResult sequentialSearch(void* pContainer, int compareContainerAndContainer(void* pContainerA, void* pContainerB), TSLinkedList sll);
TSearchResult sequentialSentinelSearch(void* pContainer, int compareContainerAndContainer(void* pContainerA, void* pContainerB), TSLinkedList sll);
TSearchResult binarySearch(void* pContainer, int compareContainerAndContainer(void* pContainerA, void* pContainerB), TSLinkedList sll);

void respawnSLinkedList(TSLinkedList* pSll);
