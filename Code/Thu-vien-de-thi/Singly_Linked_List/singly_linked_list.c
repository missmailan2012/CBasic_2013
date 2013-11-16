#include "singly_linked_list.h"


//-------- 2-1-1 void* newQuick
boolean sizeIsTrue(int nSize)
{
  if(nSize >=1)
    {
      return true;
    }
  MSG("checkSize: Kíc thước Size không hợp lí!");
  return false;
}

boolean sizeIsFalse(int nSize)
{
  if(true == sizeIsTrue(nSize))
    {
      return false;
    }
  MSG("sizeIsFalse(int nSize): Cảnh báo: Kích thước nSize không hợp lí!");
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
  if(!checkSizeIsTrue(nSizeBlocks))
    {
      MSG("newBlocks: Kích thước blocks không hợp lệ!");
    }
  void* newblocks;
  newblocks=malloc(sizeof(char)*nSizeBlocks);
  if(newblocks == NULL)
    {
      MSG("newBlocks(int nSizeBlocks): Cảnh báo: không thể cấp phát bộ nhớ động được!");
      exit(1);
    }
  return newblocks;
}

void* newQuickContainer()
{
  void* newContainer;
  newContainer=newBlocks(sizeof(TContainer));
  return newContainer;
}

void* newQuickNode()
{
  void* newNode;
  newNode=newBlocks(sizeof(TNode));
  return newNode;
}

//-------- 2-1-2 void* newFull

void* newFullContainer(int nSizeOfData)
{
  if(!checkSizeIsTrue(nSizeOfData))
    {
      MSG("newFullContainer: Kích thước data không hợp lệ!");
      exit(1);
    }
  void* blocksData;
  blocksData=newBlocks(nSizeOfData);
  void* newContainer;
  newContainer=newQuickContainer();
  ((TContainer*)newContainer)->pBlocksData=blocksData;
  ((TContainer*)newContainer)->nSizeOfData=nSizeOfData;
  return newContainer;
}

void* newFullNode(int nSizeOfData)
{
  if(!checkSizeIsTrue(nSizeOfData))
    {
      MSG("newFullNode: Kich thuoc Data khong hop le!");
      exit(1);
    }
  void* blocksData;
  blocksData=newBlocks(nSizeOfData);
  void* newNode;
  newNode=newQuickNode();
  (((TNode*)newNode)->data).pBlocksData=blocksData;
  (((TNode*)newNode)->data).nSizeOfData=nSizeOfData;
  ((TNode*)newNode)->pNext=NULL;
  return newNode;
}

void deleteQuickContainer(void** pContainer)
{
  if(checkPointIsNull(pContainer))
    {
      MSG("deleteQuickContainer: Đầu vào void** pContainer: pContainer = NULL!");
      exit(1);
    }
  if(checkPointIsNull(*pContainer))
    {
      MSG("deleteQuickContainer: Đầu vào void** pContainer: *pContainer = NULL!");
      exit(1);
    }
  free(*pContainer);
  *pContainer=NULL;
}

void deleteQuickNode(void** pNode)
{
  if(checkPointIsNull(pNode))
    {
      MSG("deleteQuickNode: Đầu vào void** pNode: pNode = NULL!");
      exit(1);
    }
  if(checkPointIsNull(*pNode))
    {
      MSG("deleteQuickNode: Đầu vào void** pNode: *pNode = NULL!");
      exit(1);
    }
  free(*pNode);
  *pNode=NULL;
}

void deleteFullContainer(void** pContainer)
{
  if(checkPointIsNull(pContainer))
    {
      MSG("deleteFullContainer: Đầu vào void** pContainer: pContainer = NULL!");
      exit(1);
    }
  if(checkPointIsNull(*pContiner))
    {
      MSG("deleteFullContainer: Đầu vào void** pContainer: *pContainer = NULL!");
      exit(1);
    }
  free((*pContainer)->pBlocksData);
  deleteQuick(pContainer);
}

void deleteFullNode(void** pNode)
{
  if(checkPointIsNull(pNode))
    {
      MSG("deleteFullNode: Đầu vào void** pNode: pNode = NULL!");
      exit(1);
    }
  if(checkPointIsNull(*pNode))
    {
      MSG("deleteFullNode: Đầu vào void** pNode: *pNode = NULL!");
      exit(1);
    }
  free(((*pNode)->data).pBlocksData);
  deleteQuickNode(pNode);
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
boolean containerIsReady(void* pContainer)
{
  if(pointIsNull(pContainer))
    {
      MSG("checkContainerReady(void* pContainer): container Null!");
      return false;
    }
  if(pointIsNull(pContainer->pBlocksData))
    {
      MSG("checkContainerReady(void* pContainer): pContainer->pBlocksData Null!");
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


boolean nodeIsReady(void* node)
{
  if(true == pointIsNull(node))
    {
      MSG("nodeIsReady(void* node): node Null!");
      return false;
    }
  if(true == containerNotReady(&(node->data)))
    {
      MSG("nodeIsReady(void* node): node->data chưa sẵn sàng!");
      return false;
    }
  return true;
}
boolean nodeNotReady(void* node)
{
  if(true == nodeIsReady(node))
    {
      return false;
    }
  MSG("nodeNotReady(void* node): Cảnh báo: node chưa sẵn sàng!");
  return true;
}

boolean containerIsSyncNode(void* container, void* node)
{
  if(true == containerNotReady(container))
    {
      MSG("containerIsSyncNode(void* container, void* node): Cảnh báo: container chưa sẵn sàng!");
      return false;
    }
  if(true == nodeNotReady(node))
    {
      MSG("containerIsSyncNode(void* container, void* node): Cảnh báo: node chưa sẵn sàng!");
      return false;
    }
  if(container.nSizeOfData != (node->data).nSizeOfData )
    {
      MSG("containerIsSyncNode(void* container, void* node): Cảnh báo: nSizeOfData không khớp!");
      return false;
    }
  return true;
}
boolean containerNotSyncNode(void* container, void* node)
{
  if(true == containerIsSyncNode(container, node))
    {
      return false;
    }
  MSG("containerNotSyncNode(void* container, void* node): Cảnh báo: container không tương thích với node!");
  return true;
}

boolean nodeIsSyncNode(void* node1, void* node2)
{
  if(true == nodeNotReady(node1))
    {
      MSG("nodeIsSyncNode(void* node1, void* node2): Cảnh báo: node1 chưa sẵn sàng!");
      return false;
    }
  if(true == nodeNotReady(node2))
    {
      MSG("nodeIsSyncNode(void* node1, void* node2): Cảnh báo: node2 chưa sẵn sàng!");
      return false;
    }
  if((node1->data).nSizeOfData != (node2->data).nSizeOfData)
    {
      MSG("nodeIsSyncNode(void* node1, void* node2): Cảnh báo: kích thước nSizeOfData 2 node không khớp nhau!");
      return false;
    }
  return true;
}
boolean nodeNotSyncNode(void* node1, void* node2)
{
  if(true == nodeIsSyncNode(node1, node2))
    {
      return false;
    }
  MSG("nodeNotSyncNode(void* node1, void* node2): Cảnh báo: node1 không tương thích với node2!");
  return true;
}

boolean nodeIsSyncSLinkedList(void* node, TSLinkedList sll)
{
  if(true == nodeNotReady)
    {
      MSG("nodeIsSyncSLinkedList(void* node, TSLinkedList sll): Cảnh báo: node chưa sẵn sàng!");
      return false;
    }
  if((node->data).nSizeOfData != ssl.nSizeOfData)
    {
      MSG("nodeIsSyncSLinkedList(void* node, TSLinkedList ssl): Cảnh báo: nSizeOfData trong node không khớp với nSizeOfData trong sll!");
      return false;
    }
  return true;
}
boolean nodeNotSyncSLinkedList(void* node, TSLinkedList sll)
{
  if(true == nodeIsSyncSLinkedList(node, sll))
    {
      return false;
    }
  MSG("nodeNotSyncSLinkedList(void* ndoe, TSLinkedList ssl): Cảnh báo: node không tương thích với SLinkedList!");
  return true;
}

boolean containerIsSyncSLinkedList(void* container, TSLinkedList sll)
{
  if(true == containerNotReady(container))
    {
      MSG("containerIsSyncSLinkedList(void* container, TSLinkedList sll): Cảnh báo: container chưa sẵn sàng!");
      return false;
    }
  if(container->nSizeOfData != ssl.nSizeOfData)
    {
      MSG("containerIsSyncSLinkedList(void* container, TSLinkedList sll): Cảnh báo: kích cỡ nSizeOfData trong container không khớp với nSizeOfData trong sll!");
      return false;
    }
  return true;
}
boolean containerNotSyncSLinkedList(void* container, TSLinkedList sll)
{
  if(true == containerIsSyncSLinkedList(container, ssl))
    {
      return false;
    }
  MSG("containerNotSyncSLinkedList(void* container, TSLinked sll): Cảnh báo: container không tương thích với sll!");
  return true;
}

boolean containerIsSyncContainer(void* container1, void* container2)
{
  if(true == containerNotReady(container1))
    {
      MSG("containerIsSyncContainer(void* container1, void* container2): Cảnh báo: container1 chưa sẵn sàng!");
      return false;
    }
  if(true == containerNotReady(container2))
    {
      MSG("containerIsSyncContainer(void* container1, void* container2): Cảnh báo: container2 chưa sẵn sàng!");
      return false;
    }
  if()
    {
      MSG("containerIsSyncContainer(void* container1, void* container2): Cảnh báo: kích thước nSizeOfData trong container1 không khớp với nSizeOfData trong container2!");
      return false;
    }
  return true;
}
boolean containerNotSyncContainer(void* container1, void* container2)
{
  if(true == containerIsSyncContainer(container1, container2))
    {
      return false;
    }
  MSG("containerNotSyncContainer(void* container1, void* container2): Cảnh báo: container1 không tương thích với container2!");
  return true;
}

void cpyBlocksToBlocks(void* blocks1, void* blocks2, int nSizeOfBlocks)
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
      ((char*)pBlocks1)++;
      ((char*)pBlocks2)++;
    }
}

void syncNodeToNode(void* pNode1, void* pNode2)
{
  if(true == nodeNotSyncNode(pNode1, pNode2))
    {
      MSG("syncNodeToNode(void* pNode1, void* pNode2): Cảnh báo: node1 chưa tương thích với node2!");
      exit(1);
    }
  cpyBlocksToBlocks( (pNode1->data).pBlocksData, (pNode2->data).pBlocksData, (pNode1->data).nSizeOfData);
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
      MSG("syncContainerToContainer(void* pContainer1, pContainer2): Cảnh báo: pContainer2 chưa sẵn sàng!");
      exit(1);
    }
  cpyBlocksToBlocks(pContainer1->pBlocksData, pContainer2->pBlocksData);
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
  cpyBlocksToBlocks(pContainer->pBlocksData, (pNode->data).pBlocksData, (pNode->data).nSizeOfData);
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
  cpyBlocksToBlocks((pNode->data).pBlocksData, pContainer->pBlocksData, (pNode->data).nSizeOfData);
}

void linkedNodeToNode(void* pNode1, void* pNode2)
{
  if(true == nodeNotSyncNode(node1, node2))
    {
      MSG("linkedNodeToNode(void* pNode1, void* pNode2): Cảnh báo:pNode1 không tương thích với pNode2!");
      exit(1);
    }
  pNode2->next=pNode1;
}

void* elementi(TSLinkedList ssl, int i)
{
  if( (i < 0) || (i >= ssl.nNumberOfNode))
    {
      MSG("elementi(TSLinkedList ssl, int i): Cảnh báo: không tồn tại vị trí i!");
      exit(1);
    }
  void* element;
  element=ssl.firts;
  while(i>0)
    {
      element=((TNode*)element)->next;
      i--;
    }
  return element;
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
  if(pCurr == sll.firts)
    {
      MSG("prewCurr(void* pCurr, TSLinkedList sll): Cảnh báo: Curr trỏ tới sll.firts, không có phần tử prew!");
      exit(1);
    }
  if(1 == sll.nNumberOfNode)
    {
      MSG("prewCurr(void* pCurr, TSLinkedList sll): Cảnh báo: Con trỏ pCurr không trỏ tới phần tử nào của SLinkedList!");
      exit(1);
    }
  void* pPrew;
  void* pRun;
  run=sll.firts;
  while(pRun != pPrew)
    {
      pPrew=pRun;
      pRun=((TNode*)pPrew)->next;
      if(pRun=pCurr)
	{
	  return pPrew;
	}
      if(pRun=sll.end)
	{
	  MSG("prewCurr(void* pCurr, TSLinkedList sll): Cảnh báo: Con trỏ pCurr không trỏ tới phần tử nào của SLinkedList!");
	  exit(1);
	}
    }
  return pPrew;
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
  if(pCurr == sll.end)
    {
      MSG("nextCurr(void* pCurr, TSLinkedList sll): Cảnh báo: pCurr trỏ đến sll.end, không có phần tử next!");
      exit(1);
    }
  if(1 == sll.nNumberOfNode)
    {
      MSG("nextCurr(void* pCurr, TSLinkedList sll): Cảnh báo: pCurr không trỏ đến phần tử nào của SLinkedList!");
      exit(1);
    }
  void* pNext;
  void* pRun;
  pRun=sll.firts;
  pNext=((TNode*)pRun)->next;
  while(pRun!= pCurr)
    {
      pRun=pNext;
      pNext=((TNode*)pRun)->next;
      if(pRun == pCurr)
	{
	  return pNext;
	}
      if(pNext == sll.end)
	{
	  MSG("nextCurr(void* pCurr, TSLinkedList sll): Cảnh báo: pCurr không trỏ đến phần tử nào của SLinkedList!");
	  exit(1);
	}
    }
  return pNext;
}

void* newFullNodeToAdd(void* pContainerAdd)
{
  if(true == containerNotReady(pContainerAdd))
    {
      MSG("newFullNodeToAdd(void* pContainerAdd): Cảnh báo: pContainer chưa sẵn sàng!");
      exit(1);
    }
  void* newNodeTemp;
  newNodeTemp=newFullNode(pContainerAdd->nSizeOfData);
  syncContainerToNode(pContainerAdd, newNodeTemp);
  return newNodeTemp;
}

void newSLinkedList(TSLinkedList* sll, int nSizeOfData)
{
  if(true == pointIsNull(sll))
    {
      MSG("newSLinkedList(TSLinkedList* sll, int nSizeOfData): Cảnh báo: sll Null!");
      exit(1);
    }
  if(true == sizeIsFalse(nSizeOfData))
    {
      MSG("newSLinkedList(TSLinkedList* sll, int nSizeOfData): Cảnh báo: nSizeOfData không hợp lệ!");
      exit(1);
    }
  sll->firts = sll->end = NULL;
  sll->nSizeOfData=nSizeOfData;
  sll->nNumberOfNode =0;
}

void addFirtsSLinkedList(void* pContainerAdd, TSLinkedList* pSll)
{
  if(true == containerNotReady(pContainerAdd))
    {
      MSG("addFirtsSLinkedList(void* pContainerAdd, TSLinkedList* pSll): Cảnh báo: pContainer chưa sẵn sàng!");
      exit(1);
    }
  if(true == pointIsFull(pSll))
    {
      MSG("addFirtsSLinkedList(void* pContainerAdd, TSlinkedList* pSll): Cảnh báo: pSll null!");
      exit(1);
    }
  if(true == containerNotSyncSLinkedList(pContainer, pSll))
    {
      MSG("addFirtsSLinkedList(void* pContainerAdd, TSLinkedList* pSll): Cảnh báo: pContainer và pSll không tương thích nhau!");
      exit(1);
    }
  void* newNodeTemp;
  newNodeTemp=newFullNodeToAdd(pContainerAdd);
  if(0 == pSll->nNumberOfNode)
    {
      pSll->firts=pSll->end=newNodeTemp;
      pSll->nNumberOfNode++;
      return;
    }
  linkedNodeToNode(pSll->firts, newNodeTemp);
  pSll->firts=newNodeTemp;
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
  if(true == containerNotSyncSLinkedList(pContainerAdd, pSll))
    {
      MSG("addEndSLinkedList(void* pContainerAdd, TSLinkeList* pSll): Cảnh báo: pContainerAdd và pSll không tương thích nhau!");
      exit(1);
    }
  void* newNodeTemp;
  newNodeTemp=newFullNodeToAdd(pContainerAdd);
  if(0 == pSll->nNumberOfNode)
    {
      pSll->firts = pSll->end = newNodeTemp;
      pSll->nNumberOfNode++;
      return;
    }
  linkedNodeToNode(newNodeTemp, pSll->end);
  pSll->end= newNodeTemp;
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
  if(pCurr == pSll->end)
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
  void* newNodeTemp;
  newNodeTemp=newFullNodeToAdd(pContainerAdd);
  linkedNodeToNode(nextCurr(*pSll,pCurr), newNodeTemp);
  linkedNodeToNode(newNodeTemp, pCurr);
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
      MSG("addPrewCurrSLinkedList(void* pContainerAdd, void* pCurr, TSLinkedList* pSll: Cảnh báo: pCur Null!)");
      exit(1);
    }
  if(pCurr == pSll->firts)
    {
      addFirtsSLinkedList(pContainerAdd, pSll);
      return;
    }
  if(true == containerNotReady(pContainerAdd))
    {
      MSG("addPrewCurrSLinkedList(void* pContainerAdd, void* pCutt, TSLinkedList* pSll): Cảnh báo: pContainer chưa sẵn sàng!");
      exit(1);
    }
  if(true == containerNotSyncSLinkedList(pContainerAdd, *pSll))
    {
      MSG("addPrewCurrSLinkedList(void* pContainer, void* pCurr, TSLinkedList* pSll): Cảnh báo: pContainerAdd và pSll không tương thích nhau!");
      exit(1);
    }
  void* newNodeTemp;
  newNodeTemp=newFullNodeToAdd(pContainerAdd);
  linkedNodeToNode(pCurr, newNodeTemp);
  linkedNodeToNode(newNodeTemp, prewCurr(pCurr, *pSll));
  pSll->nNumberOfNode++;
}

void deleteFullFirtsSLinkedList(TSLinkedList* pSll)
{
  if(true == pointIstNull(pSll))
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
  pNodeTemp=pSll->firts;
  if(1 == pSll->nNumberOfNode)
    {
      pSll->firts = pSll->end = NULL;
      pSll->nNumberOfNode--;
      deleteFullNode(pNodeTemp);
      return;
    }
  pSll->firts=nextCurr(pNodeTemp, *pSll);
  deleteFullNode(pNodeTemp);
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
      pNodeTemp= pSll->end;
      pSll->firts = pSll->end = NULL;
      pSll->nNumberOfNode--;
      deleteFullNode(pNodeTemp);
      return;
    }
  pNodeTemp=prewCurr(pSll->end, *pSll);
  ((TNode*)pNodeTemp)->pNext = NULL;
  deleteFullNode(pSll->end);
  pSll->end= pNodeTemp;
  pSll->nNumberOfNode--;
}

void deleteFullCurr(void* pCurr, TSLinkedList* pSll)
{
  if(true == pointIsNull(pSll))
    {
      MSG("deleteFullCurr(void* pCurr, TSLinkedList* pSll): Cảnh báo: pSll Null!");
      exit(1);
    }
  if(0 == pSll->nNumberOfNode)
    {
      MSG("deleteFullCurr(void* pCurr, TSLinkedList* pSll): Cảnh báo: SLinkedList đã rỗng, không còn phần tử nào để xóa -> pCurr trỏ đến không phải là phần tử của SLinkedList!");
      exit(1);
    }
  if(pCurr == NULL)
    {
      MSG("deleteFullCurr(void* pCurr, TSLinkedList* pSll): Cảnh báo: pCurr Null!");
      exit(1);
    }
  if(pCurr == pSll->firts)
    {
      deleteFullFirtsSLinkedList(pSll);
      exit(1);
    }
  if(pCurr == pSll->end)
    {
      deleteFullEndSLinkedList(pSll);
      exit(1);
    }
  if(1 == pSll->nNumberOfNode)
    {
      MSG("deleteFullCurr(void* pCurr, TSLinkedList* pSll): Cảnh báo: pCurr không trỏ đến phần tử nào của SLinkedList!");
      exit(1);
    }
  linkedNodeToNode(nextCurr(pCurr, *pSll), prewCurr(pCurr, *pSll));
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
