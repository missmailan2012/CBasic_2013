#include "singly_linked_list.h"
typedef struct
{
  char name[50];
  char phone[15];
  char email[50];
}contact_t;

void HienThi(void* pContainer)
{
  contact_t* pContactTemp;
  pContactTemp = addBlocksDataOfContainer(pContainer);
 printf("\nName: %s\nPhone: %s\nEmail: %s\n", pContactTemp->name, pContactTemp->phone, pContactTemp->email);
 return;
}

int main(int argc, char* argv[])
{
  FILE *f;
  contact_t* pContactTemp;
  f=fopen(argv[1],"rb");
  if(f == NULL)
    {
      printf("Error file!\n");
      exit(1);
    }
  TSLinkedList sll;
  newSLinkedList(sizeof(contact_t), &sll);
  int socontact, socontact_temp;
  socontact=5;
  void *pContainerTemp_A, *pContainerTemp_B;
  pContainerTemp_A = newFullContainer(sizeof(contact_t));
  pContactTemp=(contact_t*)addBlocksDataOfContainer(pContainerTemp_A);
  for(socontact_temp=0;socontact_temp<socontact;socontact_temp++)
    {
      fread(pContactTemp,sizeof(contact_t),1,f);
      addEndSLinkedList(pContainerTemp_A, &sll);
    }
  socontact_temp=socontact;
  printf("Contatc da load duoc la:\n");
  showSLinkedList(0, HienThi, sll);
  printf("So phan tu cua SLL: %d\n\n", sll.nNumberOfNode);
  int d;
  MSG("Ban muon chen phan tu thu may: ");
  scanf("%d", &d);
  while(getchar()!= '\n');
  void* pNodeTemp;
  pNodeTemp=elementi(d, sll);
  pContactTemp=(contact_t*)addBlocksDataOfNode(pNodeTemp);
  printf("Thong tin chua trong Node hien tai la:\n");
  HienThi(containerOfNode(pNodeTemp));
  pContainerTemp_B=newFullContainer(sizeof(contact_t));
  pContactTemp=(contact_t*)addBlocksDataOfContainer(pContainerTemp_B);
  printf("\n\nNhap ten: ");
  gets(pContactTemp->name);
  printf("Phone: ");
  gets(pContactTemp->phone);
  printf("Email: ");
  gets(pContactTemp->email);
  addPrewCurrSLinkedList(pContainerTemp_B, pNodeTemp, &sll);
  printf("Sau khi them:\n");
  printf("So Node SLL la: %d\n", sll.nNumberOfNode);
  showSLinkedList(0, HienThi, sll);
  respawnSLinkedList(&sll);
  MSG("Sau khi respawn:\n");
  printf("So Node SLL la: %d\n", sll.nNumberOfNode);
  showSLinkedList(0, HienThi, sll);
  deleteFullSLinkedList(&sll);
  printf("So phan tu hien tai cua SLL: %d\n", sll.nNumberOfNode);
  return 0;
}
