#include "singly-linked-list.h"
typedef struct
{
  char name[50];
  char phone[15];
  char email[50];
}contact_t;

int ks(FILE *f);

int main(int argc, char* argv[])
{
  FILE *f;
  contact_t *abc;
  f=fopen(argv[1],"rb");
  if(f == NULL)
    {
      printf("Error file!\n");
      exit(1);
    }
  singly_linked_list_bus a;
  singly_linked_list_bus_init(&a,sizeof(contact_t));
  int socontact, socontact_temp;
  socontact=ks(f);
  blocks te;
  te.size=sizeof(contact_t)+sizeof(blocks);
  te.adress=malloc(sizeof(contact_t)+sizeof(blocks));
  abc=(contact_t*)te.adress;
  socontact_temp=socontact;
  for(socontact_temp=0;socontact_temp<socontact;socontact_temp++)
    {
      fread(te.adress,sizeof(contact_t),1,f);
      singly_linked_list_bus_add_end(&a,te);
      abc=te.adress;
    }
  socontact_temp=socontact;
  printf("In ra màn hình những phần tử có trong linked list!\n");
  singly_linked_list_element(a,0,&te);
  abc=te.adress;
  printf("-------\nName: %s\nPhone: %s\nEmail: %s\n",abc->name, abc->phone, abc->email);
  for(socontact_temp=1;socontact_temp<socontact; socontact_temp++)
    {
      singly_linked_list_seek(a,&te,'>',1);
      abc=te.adress;
      printf("-------\nName: %s\nPhone: %s\nEmail: %s\n",abc->name, abc->phone, abc->email);
    }
  int d;
  printf("\n\n\n\nBạn muốn chèn phần tử thứ mấy: ");
  scanf("%d", &d);
  while(getchar()!= '\n');
  singly_linked_list_element(a,d,&te);
  contact_t tmp;
  printf("Nhập tên: ");
  gets(tmp.name);
  printf("Nhập phone: ");
  gets(tmp.phone);
  printf("Nhập email: ");
  gets(tmp.email);
  blocks te2;
  te2.adress=&tmp;
  abc=&tmp;
  printf("\nThông tin VCard:\nTên: %s\nSố phone: %s\nEmail: %s\n", abc->name, abc->phone, abc->email);
  te2.size=sizeof(contact_t)+sizeof(blocks);
  d=0;
  while(d != 't' && d != 'T' && d != 's' && d != 'S')
    {
      printf("\nBạn muốn chèn trước hay chèn sau phần tử hiện tại(T/S): ");
      scanf("%c", &d);
      while(getchar()!= '\n');
    }
  if(d == 's' || d == 'S')
    {
      singly_linked_list_insert_next_current_blocks(&a,te,te2);
    }
  if(d == 't' || d == 'T')
    {
      singly_linked_list_insert_prew_current_blocks(&a, te, te2);
    }
  printf("Sau khi thêm:\n");
  singly_linked_list_element(a,0,&te);
  printf("BR");
  abc=te.adress;
  printf("So thu tu: 1\n");
  printf("-----\nName: %s\nPhone: %s\nEmail: %s\n", abc->name, abc->phone, abc->email);
  for(socontact_temp=1;socontact_temp < a.sizeofbus; socontact_temp++)
    {
      printf("So thu tu: %d\n", socontact_temp+1);
      singly_linked_list_seek(a,&te, '>', 1);
      abc=te.adress;
      printf("----\nName: %s\nPhone: %s\nEmail: %s\n", abc->name, abc->phone, abc->email);
    }
  fcloseall();
  singly_linked_list_destroi_all_bus(&a);
  return 0;
}

int ks(FILE *f)
{
  int bl;
  bl=0;
  contact_t *ptr;
  ptr=(contact_t*)malloc(sizeof(contact_t));
  while(!feof(f))
    {
      if(fread(ptr,sizeof(contact_t), 1,f))
	{
	  bl++;
	}
    }
  printf("Có tổng cộng %d liên lạc trong phone book!\n", bl);
  rewind(f);
  return bl;
}
