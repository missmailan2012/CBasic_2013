#include "singly-linked-list.h"
typedef struct
{
  char name[50];
  char phone[15];
  char email[50];
}contact_t;



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
  socontact=5;
  blocks te;
  te.size=sizeof(contact_t)+sizeof(blocks);
  te.adress=malloc(sizeof(contact_t)+sizeof(blocks));
  abc=(contact_t*)te.adress;
  socontact_temp=socontact;
  for(socontact_temp=0;socontact_temp<socontact;socontact_temp++)
    {
      printf("Read file!\n");
      fread(te.adress,sizeof(contact_t),1,f);
      printf("Read file SS!\n");
      singly_linked_list_bus_add_end(&a,te);
      printf("Add SUCCESS!\n");
      abc=te.adress;
      printf("-------\nName: %s\nPhone: %s\nEmail: %s\n",abc->name, abc->phone, abc->email);
      printf("Complete!\n");
    }
  socontact_temp=socontact;
  printf("IN RA MAN HINH !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
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
  printf("Ban muon chen phan tu thu may: ");
  scanf("%d", &d);
  while(getchar()!= '\n');
  singly_linked_list_element(a,d,&te);
  contact_t tmp;
  printf("Nhap ten: ");
  gets(tmp.name);
  printf("Phone: ");
  gets(tmp.phone);
  printf("Email: ");
  gets(tmp.email);
  blocks te2;
  te2.adress=&tmp;
  abc=&tmp;
  printf("%s %s %s", abc->name, abc->phone, abc->email);
  te2.size=sizeof(contact_t)+sizeof(blocks);
  singly_linked_list_insert_next_current_blocks(&a,te,te2);
  printf("Sau khi them:\n");
  singly_linked_list_element(a,0,&te);
  abc=te.adress;
  printf("-----\nName: %s\nPhone: %s\nEmail: %s\n", abc->name, abc->phone, abc->email);
  for(socontact_temp=1;socontact_temp < (socontact+1); socontact_temp++)
    {
      singly_linked_list_seek(a,&te, '>', 1);
      abc=te.adress;
      printf("----\nName: %s\nPhone: %s\nEmail: %s\n", abc->name, abc->phone, abc->email);
    }
  return 0;
}
