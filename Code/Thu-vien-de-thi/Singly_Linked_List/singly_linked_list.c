#include "singly_linked_list.h"

void MSG(char* pString)
{
  printf("%s\n", pString);
}

boolean sizeIsTrue(int nSize)
{
  if(nSize >=1)
    {
      return true;
    }
  MSG("sizeIsTrue(int nSize): Cảnh báo: kích thước nSize không hợp lí!");
  return false;
}
boolean sizeIsFalse(int nSize)
{
  if(true == sizeIsTrue(nSize))
    {
      return false;
    }
  MSG("sizeIsFalse(int nSize): Cảnh báo: kích thước nSize không hợp lí!");
  return true;
}

boolean pointIsNull(void* p)
{
  if(p != NULL)
    {
      return false;
    }
  MSG("pointIsNull(void* p): Cảnh báo: p NULL!");
  return true;
}
boolean pointNotNull(void* p)
{
  if(p == NULL)
    {
      MSG("pointNotNull(void* p): Cảnh báo: p Null!");
      return false;
    }
  return true;
}

void* newBlocks(int nSizeBlocks)
{
  if(true == sizeIsFalse(nSizeBlocks))
    {
      MSG("newBlocks(int nSizeBlocks): Cảnh báo: kích thước nSizeBlocks không hợp lệ!");
    }
  void* pNewBlocksTemp;
  pNewBlocksTemp=malloc(sizeof(char)*nSizeBlocks);
  if(pNewBlocksTemp == NULL)
    {
      MSG("newBlocks(int nSizeBlocks): Cảnh báo: không thể cấp phát bộ nhớ động được!");
      exit(1);
    }
  return pNewBlocksTemp;
}
void* newQuickContainer()
{
  void* pNewContainerTemp;
  pNewContainerTemp=newBlocks(sizeof(TContainer));
  return pNewContainerTemp;
}
void* newQuickNode()
{
  void* pNewNodeTemp;
  pNewNodeTemp=newBlocks(sizeof(TNode));
  return pNewNodeTemp;
}

void* newFullContainer(int nSizeOfData)
{
  if(true ==sizeIsFalse(nSizeOfData))
    {
      MSG("newFullContainer(int nSizeOfData): Cảnh báo: kích thước nSizeOfData không hợp lệ!");
      exit(1);
    }
  void* pBlocksDataTemp;
  pBlocksDataTemp=newBlocks(nSizeOfData);
  void* pNewContainerTemp;
  pNewContainerTemp=newQuickContainer();
  ((TContainer*)pNewContainerTemp)->pBlocksData=pBlocksDataTemp;
  ((TContainer*)pNewContainerTemp)->nSizeOfData=nSizeOfData;
  return pNewContainerTemp;
}
void* newFullNode(int nSizeOfData)
{
  if(true == sizeIsFalse(nSizeOfData))
    {
      MSG("newFullNode(int nSizeOfData): Cảnh báo: nSizeOfData không hợp lệ!!");
      exit(1);
    }
  void* pBlocksDataTemp;
  pBlocksDataTemp=newBlocks(nSizeOfData);
  void* pNewNodeTemp;
  pNewNodeTemp=newQuickNode();
  (((TNode*)pNewNodeTemp)->memberData).pBlocksData=pBlocksDataTemp;
  (((TNode*)pNewNodeTemp)->memberData).nSizeOfData=nSizeOfData;
  ((TNode*)pNewNodeTemp)->pNext=NULL;
  return pNewNodeTemp;
}

void deleteQuickContainer(void** pContainerDelete)
{
  if(true == pointIsNull(pContainerDelete))
    {
      MSG("deleteQuickContainer(void** pContainerDelete): Cảnh báo: pContainer = NULL!");
      exit(1);
    }
  if(true == pointIsNull(*pContainerDelete))
    {
      MSG("deleteQuickContainer(void** pContainerDelete): Cảnh báo: *pContainer = NULL!");
      exit(1);
    }
  free(*pContainerDelete);
  *pContainerDelete=NULL;
}
void deleteQuickNode(void** pNodeDelete)
{
  if(true == pointIsNull(pNodeDelete))
    {
      MSG("deleteQuickNode(void** pNodeDelete): Cảnh báo: pNodeDelete = NULL!");
      exit(1);
    }
  if(true == pointIsNull(*pNodeDelete))
    {
      MSG("deleteQuickNode(void** pNodeDelete): Cảnh báo: *pNodeDelete = NULL!");
      exit(1);
    }
  free(*pNodeDelete);
  *pNodeDelete=NULL;
}

void deleteFullContainer(void** pContainerDelete)
{
  if(true == pointIsNull(pContainerDelete))
    {
      MSG("deleteFullContainer(void** pContainerDelete): Cảnh báo: pContainerDelete = NULL!");
      exit(1);
    }
  if(true == pointIsNull(*pContainerDelete))
    {
      MSG("deleteFullContainer(void** pContainerDelete): Cảnh báo: *pContainerDelete = NULL!");
      exit(1);
    }
  free(((TContainer*)(*pContainerDelete))->pBlocksData);
  deleteQuickContainer(pContainerDelete);
}
void deleteFullNode(void** pNodeDelete)
{
  if(true == pointIsNull(pNodeDelete))
    {
      MSG("deleteFullNode(void** pNodeDelete): Cảnh báo: pNodeDelete = NULL!");
      exit(1);
    }
  if(true == pointIsNull(*pNodeDelete))
    {
      MSG("deleteFullNode(void** pNodeDelete): Cảnh báo: *pNode = NULL!");
      exit(1);
    }
  free((((TNode*)(*pNodeDelete))->memberData).pBlocksData);
  deleteQuickNode(pNodeDelete);
}

boolean containerIsReady(void* pContainer)
{
  if(true == pointIsNull(pContainer))
    {
      MSG("checkContainerReady(void* pContainer): Cảnh báo: pContainer Null!");
      return false;
    }
if(true == pointIsNull( ((TContainer*)pContainer)->pBlocksData ))
    {
      MSG("checkContainerReady(void* pContainer): Cảnh báo: pContainer->pBlocksData Null!");
      return false;
    }
  return true;
}
boolean containerNotReady(void* pContainer)
{
  if(true == containerIsReady(pContainer))
    {
      return false;
    }
  MSG("containerNotReady(void* pContainer): Cảnh báo: pContainer chưa sẵn sàng!");
  return true;
}

boolean nodeIsReady(void* pNode)
{
  if(true == pointIsNull(pNode))
    {
      MSG("nodeIsReady(void* pNode): Cảnh báo: pNode Null!");
      return false;
    }
  if(true == containerNotReady( &( ((TNode*)pNode)->memberData ) ) )
    {
      MSG("nodeIsReady(void* pNode): pNode->memberData chưa sẵn sàng!");
      return false;
    }
  return true;
}
boolean nodeNotReady(void* pNode)
{
  if(true == nodeIsReady(pNode))
    {
      return false;
    }
  MSG("nodeNotReady(void* pNode): Cảnh báo: node chưa sẵn sàng!");
  return true;
}

boolean containerIsSyncNode(void* pContainer, void* pNode)
{
  if(true == containerNotReady(pContainer))
    {
      MSG("containerIsSyncNode(void* pContainer, void* pNode): Cảnh báo: pContainer chưa sẵn sàng!");
      return false;
    }
  if(true == nodeNotReady(pNode))
    {
      MSG("containerIsSyncNode(void* pContainer, void* pNode): Cảnh báo: pNode chưa sẵn sàng!");
      return false;
    }
  if( (((TContainer*)pContainer)->nSizeOfData) != ((((TNode*)pNode)->memberData).nSizeOfData) )
    {
      MSG("containerIsSyncNode(void* pContainer, void* pNode): Cảnh báo: nSizeOfData trong pContainer và nSizeOfData trong pNode không khớp!");
      return false;
    }
  return true;
}
boolean containerNotSyncNode(void* pContainer, void* pNode)
{
  if(true == containerIsSyncNode(pContainer, pNode))
    {
      return false;
    }
  MSG("containerNotSyncNode(void* pContainer, void* pNode): Cảnh báo: pContainer không tương thích với pNnode!");
  return true;
}

boolean nodeIsSyncNode(void* pNode1, void* pNode2)
{
  if(true == nodeNotReady(pNode1))
    {
      MSG("nodeIsSyncNode(void* pNode1, void* pNode2): Cảnh báo: pNode1 chưa sẵn sàng!");
      return false;
    }
  if(true == nodeNotReady(pNode2))
    {
      MSG("nodeIsSyncNode(void* pNode1, void* pNode2): Cảnh báo: pNode2 chưa sẵn sàng!");
      return false;
    }
  if( ((((TNode*)pNode1)->memberData).nSizeOfData) != ((((TNode*)pNode2)->memberData).nSizeOfData) )
    {
      MSG("nodeIsSyncNode(void* pNode1, void* pNode2): Cảnh báo: kích thước nSizeOfData pNode1 và nSizeOfData trong pNode2 không khớp nhau!");
      return false;
    }
  return true;
}
boolean nodeNotSyncNode(void* pNode1, void* pNode2)
{
  if(true == nodeIsSyncNode(pNode1, pNode2))
    {
      return false;
    }
  MSG("nodeNotSyncNode(void* node1, void* node2): Cảnh báo: node1 không tương thích với node2!");
  return true;
}

boolean nodeIsSyncSLinkedList(void* pNode, TSLinkedList sll)
{
  if(true == nodeNotReady(pNode))
    {
      MSG("nodeIsSyncSLinkedList(void* pNode, TSLinkedList sll): Cảnh báo: pNode chưa sẵn sàng!");
      return false;
    }
  if( ((((TNode*)pNode)->memberData).nSizeOfData) != sll.nSizeOfData)
    {
      MSG("nodeIsSyncSLinkedList(void* pNode, TSLinkedList ssl): Cảnh báo: nSizeOfData trong pNode không khớp với nSizeOfData trong sll!");
      return false;
    }
  return true;
}
boolean nodeNotSyncSLinkedList(void* pNode, TSLinkedList sll)
{
  if(true == nodeIsSyncSLinkedList(pNode, sll))
    {
      return false;
    }
  MSG("nodeNotSyncSLinkedList(void* pNode, TSLinkedList sll): Cảnh báo: pNode không tương thích với SLinkedList!");
  return true;
}

boolean containerIsSyncSLinkedList(void* pContainer, TSLinkedList sll)
{
  if(true == containerNotReady(pContainer))
    {
      MSG("containerIsSyncSLinkedList(void* pContainer, TSLinkedList sll): Cảnh báo: pContainer chưa sẵn sàng!");
      return false;
    }
  if( (((TContainer*)pContainer)->nSizeOfData) != sll.nSizeOfData)
    {
      MSG("containerIsSyncSLinkedList(void* pContainer, TSLinkedList sll): Cảnh báo: kích cỡ nSizeOfData trong pContainer không khớp với nSizeOfData trong sll!");
      return false;
    }
  return true;
}
boolean containerNotSyncSLinkedList(void* pContainer, TSLinkedList sll)
{
  if(true == containerIsSyncSLinkedList(pContainer, sll))
    {
      return false;
    }
  MSG("containerNotSyncSLinkedList(void* pContainer, TSLinked sll): Cảnh báo: pContainer không tương thích với sll!");
  return true;
}

boolean containerIsSyncContainer(void* pContainer1, void* pContainer2)
{
  if(true == containerNotReady(pContainer1))
    {
      MSG("containerIsSyncContainer(void* pContainer1, void* pContainer2): Cảnh báo: pContainer1 chưa sẵn sàng!");
      return false;
    }
  if(true == containerNotReady(pContainer2))
    {
      MSG("containerIsSyncContainer(void* pContainer1, void* pContainer2): Cảnh báo: pContainer2 chưa sẵn sàng!");
      return false;
    }
  if( (((TContainer*)pContainer1)->nSizeOfData) != (((TContainer*)pContainer2)->nSizeOfData))
    {
      MSG("containerIsSyncContainer(void* pContainer1, void* pContainer2): Cảnh báo: kích thước nSizeOfData trong pContainer1 không khớp với nSizeOfData trong pContainer2!");
      return false;
    }
  return true;
}
boolean containerNotSyncContainer(void* pContainer1, void* pContainer2)
{
  if(true == containerIsSyncContainer(pContainer1, pContainer2))
    {
      return false;
    }
  MSG("containerNotSyncContainer(void* pContainer1, void* pContainer2): Cảnh báo: pContainer1 không tương thích với pContainer2!");
  return true;
}

void cpyBlocksToBlocks(void* pBlocks1, void* pBlocks2, int nSizeOfBlocks)
{
  if(true == pointIsNull(pBlocks1))
    {
      MSG("cpyBlocksToBlocks(void* pBlocks1, void* pBlocks2, int nSizeOfBlocks): Cảnh báo: pBlocks1 Null!");
      exit(1);
    }
  if(true == pointIsNull(pBlocks2))
    {
      MSG("cpyBlocksToBlocks(void* pBlocks1, void* pBlocks2, int nSizeOfBlocks): Cảnh báo: pBlocks2 Null!");
      exit(1);
    }
  if(true == sizeIsFalse(nSizeOfBlocks))
    {
      MSG("cpyBlocksToBlocks(void* pBlocks1, void* pBlocks2, int nSizeOfBlocks): Cảnh báo: kích thước nSizeOfBlocks không hợp lí!");
      exit(1);
    }
  while(nSizeOfBlocks-- >0)
    {
      *((char*)pBlocks2)=*((char*)pBlocks1);
      pBlocks1+=1;
      pBlocks2+=1;
    }
}

void syncNodeToNode(void* pNode1, void* pNode2)
{
  if(true == nodeNotSyncNode(pNode1, pNode2))
    {
      MSG("syncNodeToNode(void* pNode1, void* pNode2): Cảnh báo: pNode1 chưa tương thích với pNode2!");
      exit(1);
    }
  cpyBlocksToBlocks( (((TNode*)pNode1)->memberData).pBlocksData, (((TNode*)pNode2)->memberData).pBlocksData, (((TNode*)pNode1)->memberData).nSizeOfData);
}

void syncContainerToContainer(void* pContainer1, void* pContainer2)
{
  if(true == containerNotReady(pContainer1))
    {
      MSG("syncContainerToContainer(void* pContainer1, void* pContainer2): Cảnh báo: pContainer1 chưa sẵn sàng!");
      exit(1);
    }
  if(true == containerNotReady(pContainer2))
    {
      MSG("syncContainerToContainer(void* pContainer1, void* pContainer2): Cảnh báo: pContainer2 chưa sẵn sàng!");
      exit(1);
    }
  cpyBlocksToBlocks(((TContainer*)pContainer1)->pBlocksData, ((TContainer*)pContainer2)->pBlocksData, ((TContainer*)pContainer2)->nSizeOfData);
}

void syncContainerToNode(void* pContainer, void* pNode)
{
  if(true == containerNotReady(pContainer))
    {
      MSG("syncContainerToNode(void* pContainer, void* pNode): Cảnh báo: pContainer chưa sẵn sàng!");
      exit(1);
    }
  if(true == nodeNotReady(pNode))
    {
      MSG("syncContainerToNode(void* pContainer, void* pNode): Cảnh báo: pNode chưa sẵn sàng!");
      exit(1);
    }
  if(true == containerNotSyncNode(pContainer, pNode))
    {
      MSG("syncContainerToNode(void* pContainer, void* pNode): Cảnh báo: pContainer không tương thích với pNode!");
      exit(1);
    }
  cpyBlocksToBlocks(((TContainer*)pContainer)->pBlocksData, (((TNode*)pNode)->memberData).pBlocksData, (((TNode*)pNode)->memberData).nSizeOfData);
}

void syncNodeToContainer(void* pNode, void* pContainer)
{
  if(true == nodeNotReady(pNode))
    {
      MSG("syncNodeToContainer(void* pNode, void* pContainer): Cảnh báo: pNode chưa sẵn sàng!");
      exit(1);
    }
  if(true == containerNotReady(pContainer))
    {
      MSG("syncNodeToContainer(void* pNode, void* pContainer): Cảnh báo: pContainer chưa sẵn sàng!");
      exit(1);
    }
  if(true == containerNotSyncNode(pContainer, pNode))
    {
      MSG("syncNodeToContainer(void* pNode, void* pContainer): Cảnh báo: pContainer không tương thích với pNode!");
      exit(1);
    }
  cpyBlocksToBlocks((((TNode*)pNode)->memberData).pBlocksData, ((TContainer*)pContainer)->pBlocksData, (((TNode*)pNode)->memberData).nSizeOfData);
}

void linkedNodeToNode(void* pNode1, void* pNode2)
{
  if(true == nodeNotSyncNode(pNode1, pNode2))
    {
      MSG("linkedNodeToNode(void* pNode1, void* pNode2): Cảnh báo: pNode1 không tương thích với pNode2!");
      exit(1);
    }
  ((TNode*)pNode2)->pNext=pNode1;
}

void* elementi(int i, TSLinkedList sll)
{
  if( (i < 0) || (i >= sll.nNumberOfNode))
    {
      MSG("elementi(int i, TSLinkedList sll): Cảnh báo: không tồn tại vị trí i!");
      exit(1);
    }
  void* pElementTemp;
  pElementTemp=sll.pFirts;
  while(i > 0)
    {
      pElementTemp=((TNode*)pElementTemp)->pNext;
      i--;
    }
  return pElementTemp;
}

void* prewCurr(void* pCurr, TSLinkedList sll)
{
  if(0 == sll.nNumberOfNode)
    {
      MSG("prewCurr(void* pCurr, TSLinkedList sll): Cảnh báo: SLinkedList rỗng, chưa có phần tử nào!");
      exit(1);
    }
  if(true == pointIsNull(pCurr))
    {
      MSG("prewCurr(TSLinkedList sll, void* pCurr): Cảnh báo: pCurr Null!");
      exit(1);
    }
  if(pCurr == sll.pFirts)
    {
      MSG("prewCurr(void* pCurr, TSLinkedList sll): Cảnh báo: Curr trỏ tới sll.pFirts, không có phần tử prew!");
      exit(1);
    }
  if(1 == sll.nNumberOfNode)
    {
      MSG("prewCurr(void* pCurr, TSLinkedList sll): Cảnh báo: Con trỏ pCurr không trỏ tới phần tử nào của SLinkedList!");
      exit(1);
    }
  void* pPrewTemp;
  void* pRunTemp;
  pRunTemp=sll.pFirts;
  while(pRunTemp != pPrewTemp)
    {
      pPrewTemp=pRunTemp;
      pRunTemp=((TNode*)pPrewTemp)->pNext;
      if(pRunTemp == pCurr)
	{
	  return pPrewTemp;
	}
      if(pRunTemp == sll.pEnd)
	{
	  MSG("prewCurr(void* pCurr, TSLinkedList sll): Cảnh báo: Con trỏ pCurr không trỏ tới phần tử nào của SLinkedList!");
	  exit(1);
	}
    }
}

void* nextCurr(void* pCurr, TSLinkedList sll)
{
  if(0 == sll.nNumberOfNode)
    {
      MSG("nextCurr(void* pCurr, TSLinkedList sll): Cảnh báo: SLinkedList rỗng chưa có phần tử nào!");
      exit(1);
    }
  if(true == pointIsNull(pCurr))
    {
      MSG("nextCurr(void* pCurr, TSLinkedList sll): Cảnh báo: pCurr Null!");
      exit(1);
    }
  if(pCurr == sll.pEnd)
    {
      MSG("nextCurr(void* pCurr, TSLinkedList sll): Cảnh báo: pCurr trỏ đến sll.pEnd, không có phần tử next!");
      exit(1);
    }
  if(1 == sll.nNumberOfNode)
    {
      MSG("nextCurr(void* pCurr, TSLinkedList sll): Cảnh báo: pCurr không trỏ đến phần tử nào của SLinkedList!");
      exit(1);
    }
  void* pNextTemp;
  void* pRunTemp;
  pRunTemp=sll.pFirts;
  pNextTemp=((TNode*)pRunTemp)->pNext;
  while(pRunTemp != pCurr)
    {
      pRunTemp=pNextTemp;
      pNextTemp=((TNode*)pRunTemp)->pNext;
      if(pRunTemp == pCurr)
	{
	  return pNextTemp;
	}
      if(pNextTemp == sll.pEnd)
	{
	  MSG("nextCurr(void* pCurr, TSLinkedList sll): Cảnh báo: pCurr không trỏ đến phần tử nào của SLinkedList!");
	  exit(1);
	}
    }
  return pNextTemp;
}

void* newFullNodeToAdd(void* pContainerAdd)
{
  if(true == containerNotReady(pContainerAdd))
    {
      MSG("newFullNodeToAdd(void* pContainerAdd): Cảnh báo: pContainerAdd chưa sẵn sàng!");
      exit(1);
    }
  void* pNewNodeTemp;
  pNewNodeTemp=newFullNode(((TContainer*)pContainerAdd)->nSizeOfData);
  syncContainerToNode(pContainerAdd, pNewNodeTemp);
  return pNewNodeTemp;
}

void newSLinkedList(int nSizeOfData, TSLinkedList* pSll)
{
  if(true == pointIsNull(pSll))
    {
      MSG("newSLinkedList(int nSizeOfData, TSLinkedList* pSll): Cảnh báo: pSll Null!");
      exit(1);
    }
  if(true == sizeIsFalse(nSizeOfData))
    {
      MSG("newSLinkedList(int nSizeOfData, TSLinkedList* pSll): Cảnh báo: nSizeOfData không hợp lệ!");
      exit(1);
    }
  pSll->pFirts = pSll->pEnd = NULL;
  pSll->nSizeOfData=nSizeOfData;
  pSll->nNumberOfNode =0;
}

void addFirtsSLinkedList(void* pContainerAdd, TSLinkedList* pSll)
{
  if(true == containerNotReady(pContainerAdd))
    {
      MSG("addFirtsSLinkedList(void* pContainerAdd, TSLinkedList* pSll): Cảnh báo: pContainerAdd chưa sẵn sàng!");
      exit(1);
    }
  if(true == pointIsNull(pSll))
    {
      MSG("addFirtsSLinkedList(void* pContainerAdd, TSlinkedList* pSll): Cảnh báo: pSll null!");
      exit(1);
    }
  if(true == containerNotSyncSLinkedList(pContainerAdd, *pSll))
    {
      MSG("addFirtsSLinkedList(void* pContainerAdd, TSLinkedList* pSll): Cảnh báo: pContainer và pSll không tương thích nhau!");
      exit(1);
    }
  void* pNewNodeTemp;
  pNewNodeTemp=newFullNodeToAdd(pContainerAdd);
  if(0 == pSll->nNumberOfNode)
    {
      pSll->pFirts = pSll->pEnd=pNewNodeTemp;
      pSll->nNumberOfNode++;
      return;
    }
  linkedNodeToNode(pSll->pFirts, pNewNodeTemp);
  pSll->pFirts=pNewNodeTemp;
  pSll->nNumberOfNode++;
}

void addEndSLinkedList(void* pContainerAdd, TSLinkedList* pSll)
{
  if(true == containerNotReady(pContainerAdd))
    {
      MSG("addEndSLinkedList(void* pContainerAdd, TSLinkedList* pSll): Cảnh báo: pContainerAdd chưa sẵn sàng!");
      exit(1);
    }
  if(true == pointIsNull(pSll))
    {
      MSG("addEndSLinkedList(void* pContainerAdd, TSLinkedList* pSll): Cảnh báo: pSll Null!");
      exit(1);
    }
  if(true == containerNotSyncSLinkedList(pContainerAdd, *pSll))
    {
      MSG("addEndSLinkedList(void* pContainerAdd, TSLinkeList* pSll): Cảnh báo: pContainerAdd và pSll không tương thích nhau!");
      exit(1);
    }
  void* pNewNodeTemp;
  pNewNodeTemp=newFullNodeToAdd(pContainerAdd);
  if(0 == pSll->nNumberOfNode)
    {
      pSll->pFirts = pSll->pEnd = pNewNodeTemp;
      pSll->nNumberOfNode++;
      return;
    }
  linkedNodeToNode(pNewNodeTemp, pSll->pEnd);
  pSll->pEnd= pNewNodeTemp;
  pSll->nNumberOfNode++;
}

void addNextCurrSLinkedList(void* pContainerAdd, void* pCurr, TSLinkedList* pSll)
{
  if(true == pointIsNull(pSll))
    {
      MSG("addNextCurrSLinkedList(void* pContainerAdd, void* pCurr, TSLinkedList* pSll): Cảnh báo: pSll Null!");
      exit(1);
    }
  if(0 == pSll->nNumberOfNode)
    {
      addEndSLinkedList(pContainerAdd, pSll);
      return;
    }
  if(pCurr == NULL)
    {
      MSG("AddNextCurrSLinkedList(void* pContainerAdd, void* pCurr, TSLinkedList* pSll): Cảnh báo: pCurr Null!");
      exit(1);
    }
  if(pCurr == pSll->pEnd)
    {
      addEndSLinkedList(pContainerAdd, pSll);
      return;
    }
  if(true == containerNotReady(pContainerAdd))
    {
      MSG("addNextCurrSLinkedList(void* pContainerAdd, void* pCurr, TSLinkedList* pSll): Cảnh báo: pContainerAdd chưa sẵn sàng!");
      exit(1);
    }
  if(true == containerNotSyncSLinkedList(pContainerAdd, *pSll))
    {
      MSG("addNextCurrSLinkedList(void* pContainerAdd, void* pCurr, TSLinkedList* pSll): Cảnh báo: pContainerAdd không  tươngthích với pSll!");
      exit(1);
    }
  void* pNewNodeTemp;
  pNewNodeTemp=newFullNodeToAdd(pContainerAdd);
  printf("Dia chi Curr: %0x\n", pCurr);
  printf("Dia chi nextCurr: %0x\n", nextCurr(pCurr,*pSll));
  linkedNodeToNode(nextCurr(pCurr,*pSll), pNewNodeTemp);
  linkedNodeToNode(pNewNodeTemp, pCurr);
  pSll->nNumberOfNode++;
}

void addPrewCurrSLinkedList(void* pContainerAdd, void* pCurr, TSLinkedList* pSll)
{
  if(true == pointIsNull(pSll))
    {
      MSG("addPrewCurrSLinkedList(void* pContainerAdd, void* pCurr, TSLinkedList* pSll): Cảnh báo: pSll Null!");
      exit(1);
    }
  if(0 == pSll->nNumberOfNode)
    {
      addFirtsSLinkedList(pContainerAdd, pSll);
      return;
    }
  if(pCurr == NULL)
    {
      MSG("addPrewCurrSLinkedList(void* pContainerAdd, void* pCurr, TSLinkedList* pSll): Cảnh báo: pCur Null!)");
      exit(1);
    }
  if(pCurr == pSll->pFirts)
    {
      addFirtsSLinkedList(pContainerAdd, pSll);
      return;
    }
  if(true == containerNotReady(pContainerAdd))
    {
      MSG("addPrewCurrSLinkedList(void* pContainerAdd, void* pCurr, TSLinkedList* pSll): Cảnh báo: pContainer chưa sẵn sàng!");
      exit(1);
    }
  if(true == containerNotSyncSLinkedList(pContainerAdd, *pSll))
    {
      MSG("addPrewCurrSLinkedList(void* pContainerAdd, void* pCurr, TSLinkedList* pSll): Cảnh báo: pContainerAdd và pSll không tương thích nhau!");
      exit(1);
    }
  void* pNewNodeTemp;
  pNewNodeTemp=newFullNodeToAdd(pContainerAdd);
  linkedNodeToNode(pCurr, pNewNodeTemp);
  linkedNodeToNode(pNewNodeTemp, prewCurr(pCurr, *pSll));
  pSll->nNumberOfNode++;
}

void deleteFullFirtsSLinkedList(TSLinkedList* pSll)
{
  if(true == pointIsNull(pSll))
    {
      MSG("deleteFullFirtsSLinkedList(TSLinkedList* pSll): Cảnh báo: pSll Null!");
      exit(1);
    }
  if(0 == pSll->nNumberOfNode)
    {
      MSG("deleteFullFirtsSLinkedList(TSLinkedList* pSll): Cảnh báo: SLinkedList đã rỗng, không còn phần tử để xóa!");
      exit(1);
    }
  void* pNodeTemp;
  pNodeTemp = pSll->pFirts;
  if(1 == pSll->nNumberOfNode)
    {
      pSll->pFirts = pSll->pEnd = NULL;
      pSll->nNumberOfNode--;
      deleteFullNode(&pNodeTemp);
      return;
    }
  pSll->pFirts  =nextCurr(pNodeTemp, *pSll);
  deleteFullNode(&pNodeTemp);
  pSll->nNumberOfNode--;
}

void deleteFullEndSLinkedList(TSLinkedList* pSll)
{
  if(true == pointIsNull(pSll))
    {
      MSG("deleteFullEndSLinkedList(TSLinkedList* pSll): Cảnh báo: pSll Null!");
      exit(1);
    }
  if(0 == pSll->nNumberOfNode)
    {
      MSG("deleteFullEndSLinkedList(TSLinkedList* pSll): Cảnh báo: SLinkedList đã rỗng, không còn phần tử để xóa!");
      exit(1);
    }
  void* pNodeTemp;
  if(1 == pSll->nNumberOfNode)
    {
      pNodeTemp= pSll->pEnd;
      pSll->pFirts = pSll->pEnd = NULL;
      pSll->nNumberOfNode--;
      deleteFullNode(&pNodeTemp);
      return;
    }
  pNodeTemp=prewCurr(pSll->pEnd, *pSll);
  ((TNode*)pNodeTemp)->pNext = NULL;
  deleteFullNode(&(pSll->pEnd));
  pSll->pEnd= pNodeTemp;
  pSll->nNumberOfNode--;
}

void deleteFullCurr(void** pCurr, TSLinkedList* pSll)
{
  if(true == pointIsNull(pSll))
    {
      MSG("deleteFullCurr(void** pCurr, TSLinkedList* pSll): Cảnh báo: pSll Null!");
      exit(1);
    }
  if(0 == pSll->nNumberOfNode)
    {
      MSG("deleteFullCurr(void** pCurr, TSLinkedList* pSll): Cảnh báo: SLinkedList đã rỗng, không còn phần tử nào để xóa -> pCurr trỏ đến không phải là phần tử của SLinkedList!");
      exit(1);
    }
  if(pCurr == NULL)
    {
      MSG("deleteFullCurr(void** pCurr, TSLinkedList* pSll): Cảnh báo: pCurr Null!");
      exit(1);
    }
  if( (*pCurr) == NULL)
    {
      MSG("deleteFullCurr(void** pCurr, TSLinkedList* pSll): Cảnh báo: *pCurr Null!");
      exit(1);
    }
  if( (*pCurr) == pSll->pFirts)
    {
      deleteFullFirtsSLinkedList(pSll);
      exit(1);
    }
  if( (*pCurr) == pSll->pEnd)
    {
      deleteFullEndSLinkedList(pSll);
      exit(1);
    }
  if(1 == pSll->nNumberOfNode)
    {
      MSG("deleteFullCurr(void** pCurr, TSLinkedList* pSll): Cảnh báo: *pCurr không trỏ đến phần tử nào của SLinkedList!");
      exit(1);
    }
  linkedNodeToNode(nextCurr(*pCurr, *pSll), prewCurr(*pCurr, *pSll));
  deleteFullNode(pCurr);
  pSll->nNumberOfNode--;
}

void deleteFullPrewCurr(void* pCurr, TSLinkedList* pSll)
{
  if(true == pointIsNull(pSll))
    {
      MSG("deleteFullPrewCurr(void* pCurr, TSLinkedList* pSll): Cảnh báo: pSll Null!");
      exit(1);
    }
  if( NULL == pCurr)
    {
      MSG("deleteFullPrewCurr(void* pCurr, TSLinkedList* pSll): Cảnh báo: pCurr Null!");
      exit(1);
    }
  if(NULL == prewCurr(pCurr, *pSll))
    {
      MSG("deleteFullPrewCurr(void* pCurr, TSLinkedList* pSll): Cảnh báo: không tồn tại PrewCurr để xóa!");
      exit(1);
    }
  deleteFullCurr(prewCurr(pCurr, *pSll), pSll);
}

void deleteFullNextCurr(void* pCurr, TSLinkedList* pSll)
{
  if(true == pointIsNull(pSll))
    {
      MSG("deleteFullNextCurr(void* pCurr, TSLinkedList* pSll): Cảnh báo: pSll Null!");
      exit(1);
    }
  if(pCurr == NULL)
    {
      MSG("deleteFullNextCurr(void* pCurr, TSLinkedList* pSll): Cảnh báo: pCurr Null!");
      exit(1);
    }
  if(NULL == nextCurr(pCurr, *pSll))
    {
      MSG("deleteFullNextCurr(void* pCurr, TSLinkedList* pSll): Cảnh báo: không tồn tại nextCurr để xóa!");
      exit(1);
    }
  deleteFullCurr(nextCurr(pCurr, *pSll), pSll);
}

void deleteFullSLinkedList(TSLinkedList* pSll)
{
  if(true == pointIsNull(pSll))
    {
      MSG("deleteFullSLinkedList(TSLinkedList* pSll): Cảnh báo: pSll Null!");
      exit(1);
    }
  while(pSll->nNumberOfNode > 0)
    {
      deleteFullFirtsSLinkedList(pSll);
    }
}
