#include "singly_linked_list.h"


//-------- 2-1-1 void* newquick
boolean checkSizeIsTrue(int nSize)
{
  if(nSize >=1)
    {
      return 1;
    }
  MSG("checkSize: Kíc thước Size không hợp lí!");
  return 0;
}

boolean checkPointIsNull(void* p)
{
  if(p != NULL)
    {
      return 0;
    }
  MSG("checkPointIsNull: Con trỏ NULL!");
  return 1;
}

void* newblocks(int nSizeBlocks)
{
  if(!checkSizeIsTrue(nSizeBlocks))
    {
      MSG("newblocks: Kích thước blocks không hợp lệ!");
    }
  void* newblocks;
  newblocks=malloc(sizeof(char)*nSizeBlocks);
  if(newblocks == NULL)
    {
      MSG("newblocks: Không thể cấp phát bộ nhớ động được!");
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
  if(!checkSizeIsTrue(nSizeOfData))
    {
      MSG("newfullContainer: Kích thước data không hợp lệ!");
      exit(1);
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
  if(!checkSizeIsTrue(nSizeOfData))
    {
      MSG("newfullNode: Kich thuoc Data khong hop le!");
      exit(1);
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
  if(checkPointIsNull(pContainer))
    {
      MSG("deletequickContainer: Đầu vào void** pContainer: pContainer = NULL!");
      exit(1);
    }
  if(checkPointIsNull(*pContiner))
    {
      MSG("deletequickContainer: Đầu vào void** pContainer: *pContainer = NULL!");
      exit(1);
    }
  free(*pContainer);
  *pContainer=NULL;
}

void deletequickNode(void** pNode)
{
  if(checkPointIsNull(pNode))
    {
      MSG("deletequickNode: Đầu vào void** pNode: pNode = NULL!");
      exit(1);
    }
  if(checkPointIsNull(*pNode))
    {
      MSG("deletequickNode: Đầu vào void** pNode: *pNode = NULL!");
      exit(1);
    }
  free(*pNode);
  *pNode=NULL;
}

void deletefullContainer(void** pContainer)
{
  if(checkPointIsNull(pContainer))
    {
      MSG("deletefullContainer: Đầu vào void** pContainer: pContainer = NULL!");
      exit(1);
    }
  if(checkPointIsNull(*pContiner))
    {
      MSG("deletefullContainer: Đầu vào void** pContainer: *pContainer = NULL!");
      exit(1);
    }
  free((*pContainer)->pBlocksData);
  deletequick(pContainer);
}

void deletefullNode(void** pNode)
{
  if(checkPointIsNull(pNode))
    {
      MSG("deletefullNode: Đầu vào void** pNode: pNode = NULL!");
      exit(1);
    }
  if(checkPointIsNull(*pNode))
    {
      MSG("deletefullNode: Đầu vào void** pNode: *pNode = NULL!");
      exit(1);
    }
  free(((*pNode)->data).pBlocksData);
  deletquickNode(pNode);
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
