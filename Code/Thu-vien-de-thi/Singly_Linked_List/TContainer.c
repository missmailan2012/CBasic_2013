#include "TContainer.h"

boolean container_Ready(void* pContainer)
{
  if(true == pointIsNull(pContainer))
    {
      msg("boolean container_Ready(void* pContainer): Canh bao: pContainer Null!");
      msg("pContainer not ready to use!");
      msg("");
      return false;
    }
  if(true == pointIsNull(pContainer->pBlocksData))
    {
      msg("boolean container_Ready(void* pContainer): Canh bao: pContainer->pBlocksData Null!");
      msg("member Data of container error!");
      msg("pContainer not ready to use!")
      msg("");
      return false;
    }
  return true;
}
boolean container_NotReady(void* pContainer)
{
  if(true == pointIsNull(pContainer))
    {
      msg("boolean container_NotReady(void* pContainer): Canh bao: pContainer Null!");
      msg("pContainer not ready to use!");
      msg("");
      return true;
    }
  if(true == pointIsNull(pContainer->pBlocksData))
    {
      msg("boolean container_NotReady(void* pContainer): Canh bao: pContainer->pBlocksData Null!");
      msg("member Data Of container error!");
      msg("pContainer not ready to use!");
      msg("");
      return true;
    }
  return false;
}


boolean container_TowContainerIsSync(void* pContainerA, void* pContainerB)
{

}
