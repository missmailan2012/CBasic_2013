typedef struct
{
  void* pBlocksData;
  int nSizeOfData;
}TContainer;

boolean container_Ready(void* pContainer); //
boolean container_NotReady(void* pContainer); //

boolean container_TwoContainerIsSync(void* pContainerA, void* pContainerB);
boolean container_TwoContainerNotSync(void* pContainerA, void* pContainerB);

TContainer* container_NewFull(int nSizeOfData);
//TContainer* container_NewQuick(int nSizeOfData);

void container_DeleteFull(void* pContainer);
//void container_DeleteQuick(void* pContainer);

void* container_PointOfBlocksData(void* pContainer);

void container_SyncDataTwoContainer(void* pContainerSrc, void* pContainerDst);

void container_SwapDataTwoContainer(void* pContainerA, void* pContainerB);
