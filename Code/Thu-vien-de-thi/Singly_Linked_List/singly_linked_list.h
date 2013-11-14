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

// 2-Cac toan tu;

//++++ 2-1 void* new

//-------- 2-1-1 void* newquick
void* newquickContainer();
void* newquickNode();

//-------- 2-1-2 void* newfull
void* newfullContainer(int);
void* newfullNode(int);

//-------- 2-1-3 void* newblocks
void* newblocks(int);

//++++ 2-2 void delete

//-------- 2-2-1 void deletequick
void deletequickContainer(void** pContainer);
void deletequickNode(void*** pNode);

//-------- 2-2-2 void deletefull
void deletefullContainer(void** pContainer);
void deletefullNode(void** pNode);

//++++ 2-3 boolean check
boolean checkSizeOfData(int nSizeOfData);
boolean checkPointIsNull(void* p);

// 3-Cac ham;
//++++ 3-0 Cac ham so cap
void syncNodeToNode(void* node1, void* node2);
void syncContainerToContainer(void* container1, void* container2);
void syncContainerToNode(void* container, void* node);
void syncNodeToContainer(void* node, void* container);
void linkedNodeToNode(void* node1, void* node2);
void cpyBlocksToBlocks(void* blocks1, void* blocks2, int nSizeOfBlocks);
void* elementi(TSLinkedList a, int i);
void* prewcurr(TSLinkedList a, void* curr);
void* nextcurr(TSLinkedList a, void* curr);
boolean checkContainerReady(void* container);
boolean checkNodeReady(void* node);
boolean checkContainerIsSyncNode(void* container, void* node);
boolean checkNodeIsSyncNode(void* node1, void* node2);
boolean checkNodeIsSyncSLinkedList(void* node, TSLinkedList a);
boolean checkContainerIsSyncSLinkedList(void* container, TSLinkedList a);
boolean checkContainerIsSyncContainer(void* container1, void* container2);
void* newfullNodeForAdd(void* containerAdd);



//++++ 3-1 void newSLinkedList
void newSLinkedList(TSLinkedList* a, int nSizeOfData);

//++++ 3-2 void add
void addFirtsSLinkedList(void* containerAdd, TSLinkedList* a);
void addEndSLinkedList(void* containerAdd, TSLinkedList* a);
void addNextCurrSLinkedList(void* containerAdd, void* curr, TSLinkedList* a);
void addPrewCurrSLinkedList(void* containerAdd, void* curr, TSLinkedList* a);

//++++ 3-3 void delete

//-------- 3-3-1 void deletequick
//-------- 3-3-2 void deletefull
void deletefullFirtsSLinkedList(TSLinkedList* a);
void deletefullEndSLinkedList(TSLinkedList* a);
void deletefullCurr(void* curr, TSLinkedList* a );
void deletefullPrewCurr(void* curr, TSLinkedList* a);
void deletefullNextCurr(void* curr, TSLinkedList* a);
voide deletefullSLinkedList(TSLinkedList* a);
//++++ 3-4 void sortSLinkedList
