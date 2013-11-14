#include "singly_linked_list.h"


//-------- 2-1-1 void* newquick
void* newblocks(int nSizeBlocks)
{
  if(!checkSizeOfData(nSizeBlocks))
    {
      MSG("newblocks: Kich thuoc blocks khong hop le!");
    }
  void* newblocks;
  newblocks=malloc(sizeof(char)*nSizeBlocks);
  if(newblocks == NULL)
    {
      MSG("newblocks: Khong the cap phat bo nho dong duoc!");
      exit(1);
    }
  return newblocks;
}

void* newquickContainer()
{
  void* newContainer;
  newContainer=newblocks(sizeof(TContainer));
  return newContainer;
}

void* newquickNode()
{
  void* newNode;
  newNode=newblocks(sizeof(TNode));
  return newNode;
}

//-------- 2-1-2 void* newfull

void* newfullContainer(int nSizeOfData)
{
  if(!checkSizeOfData(nSizeOfData))
    {
      MSG("newfullContainer: Kich thuoc data khong hop le!");

    }
  void* blocksData;
  blocksData=newblocks(nSizeOfData);
  void* newContainer;
  newContainer=newquickContainer();
  ((TContainer*)newContainer)->pBlocksData=blocksData;
  ((TContainer*)newContainer)->nSizeOfData=nSizeOfData;
  return newContainer;
}

void* newfullNode(int nSizeOfData)
{
  if(!checkSizeOfData(nSizeOfData))
    {
      MSG("newfullNode: Kich thuoc Data khong hop le!");
    }
  void* blocksData;
  blocksData=newblocks(nSizeOfData);
  void* newNode;
  newNode=newquickNode();
  (((TNode*)newNode)->data).pBlocksData=blocksData;
  (((TNode*)newNode)->data).nSizeOfData=nSizeOfData;
  ((TNode*)newNode)->pNext=NULL;
  return newNode;
}

void deletequickContainer(void** pContainer)
{
  if(pointIsNull(*pContainer))
    {
      MSG("deletequickContainer: Dau vao void** pContainer = NULL!");
      exi(1);
    }
  free(*pContainer);
  *pContainer=NULL;
}

void deletequickNode(void** pNode)
{
  if(pointIsNull())
}
