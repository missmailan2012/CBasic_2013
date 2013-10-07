#include "singly-linked-list.h"


void singly_linked_list_bus_init(singly_linked_list_bus* a, int sizeofdata)
{
  // Khoi tao mot bus du lieu.
  a->sizeofdata=sizeofdata;
  a->sizeofbus=0;
  a->firts.adress=NULL;
  a->firts.size=sizeofdata+sizeof(blocks);
  a->end.adress=NULL;
  a->end.size=sizeofdata+sizeof(blocks);
}

status_t copy_blocks_to_blocks(blocks a, blocks b)
{
  if(a.size != b.size)
    {
      printf("Co loi khi sao chep blocks to blocks! Size cua 2 blocks khong trung nhau!\n");
      exit(1);
    }
  status_t stt;
  stt.stt=1;
  // Sao chep tu a vao b;
  while(a.size--)
    {
      *((char*)b.adress)=*((char*)a.adress);
      a.adress++;
      b.adress++;
    }
  // Tra ve stt=0 neu khong co loi.
  stt.stt=0;
  return stt;
}

status_t singly_linked_list_element_next(blocks current, blocks* next)
{
  status_t stt;
  stt.stt=1;
  // Di chuyen con tro current den blocks void* next;
  void* temp;
  temp=current.adress;
  temp+=(current.size-sizeof(blocks));
  *next=*((blocks*)temp);
  // Tra ve stt=0 neu khong co loi nao.
  stt.stt=0;
  return stt;
}

status_t singly_linked_list_bus_add_end(singly_linked_list_bus* a, blocks add)
{
  if(add.adress == NULL)
    {
      printf("Error! Blocks input!\n");
    }
  if( a->sizeofdata != ( add.size - sizeof(blocks)) )
    {
      printf("Co loi khi them phan tu vao cuoi bus data! Kich co data blocks can them khong giong nhu kich co data trong bus!\n");
      exit(1);
    }
  status_t stt;
  stt.stt=1;
  blocks new;
  void* temp;
  // Cap phat mot phan tu moi;
  temp=malloc(a->sizeofdata+sizeof(blocks));
  new.adress=temp;
  new.size=a->sizeofdata+sizeof(blocks);

  // Hoan chinh phan tu;
  copy_blocks_to_blocks(add,new);
  temp+=a->sizeofdata;
  ((blocks*)temp)->adress=NULL;
  ((blocks*)temp)->size=a->sizeofdata+sizeof(blocks);
  if(a->firts.adress == NULL)
    {
      a->firts.adress=new.adress;
      a->end.adress=new.adress;
      a->sizeofbus++;
      // Tra ve stt =0 neu khong co loi;
      stt.stt=0;
      return stt;
    }
  // Xac dinh blocks next cua end;
  temp=a->end.adress;
  temp+=a->sizeofdata;
  (*((blocks*)temp)).adress=new.adress;
  (*((blocks*)temp)).size=a->sizeofdata + sizeof(blocks);
  // Cap nhat lai bus;
  a->end.adress=new.adress;
  a->sizeofbus++;
  // Tra ve stt =0 neu khong co loi nao.
  stt.stt=0;
  return stt;
}

status_t singly_linked_list_element(singly_linked_list_bus a, int chiso, blocks* bl)
{
  if(chiso < 0 || chiso > (a.sizeofbus-1) )
    {
      printf("Khong ton tai phan tu co chi so nhu yeu cau!\n");
      exit(1);
    }
  status_t stt;
  stt.stt=1;
  *bl=a.firts;
  if(chiso == 0)
    {
      stt.stt=0;
      return stt;
    }
  blocks curr;
  curr=*bl;
  while(chiso -- )
    {
      singly_linked_list_element_next(curr,bl);
      curr=*bl;
    }
  // Tra ve stt=0 neu khong co loi.
  stt.stt=0;
  return stt;
}

status_t singly_linked_list_offset_of_element(singly_linked_list_bus a, blocks bl, int* offset)
{
  if( bl.adress == NULL)
    {
      printf("Warring!!!!\nWarring!!!!\nWarring!!!!\nWarring!!!!\nElement ptr == NULL\n");
      exit(1);
    }
  if((bl.size-sizeof(blocks)) != a.sizeofdata)
    {
      printf("Warring! Size in blocks != Sizeofdata!\n");
      exit(1);
    }
  status_t stt;
  stt.stt=1;
  // Cu gan cho current=current->next, den khi nao current == elemtn thi dung lai.
  *offset=0;
  blocks temp;
  void* point;
  temp=a.firts;
  if( temp.adress == bl.adress )
    {
      stt.stt=0;
      return stt;
    }
  while(temp.adress != bl.adress)
    {
      point=temp.adress;
      point+=(temp.size-sizeof(blocks));
      temp=*((blocks*)point);
      *offset+=1;
    }
  // Tra ve stt=0 neu khong co loi;
  stt.stt=0;
  return stt;
}


status_t singly_linked_list_seek(singly_linked_list_bus a, blocks *current, char huong, int number_element)
{
  if(huong != '<' && huong!= '>')
    {
      printf("Warring!!!!\nWarring!!!!\nWarring!!!!\nWarring!!!!\nHuong so voi offset bi sai!\n");
      exit(1);
    }
  if(current->adress == NULL)
    {
      printf("Warring!!!!\nWarring!!!!\nWarring!!!!\nWarring!!!!\nThe offset current == NULL\n");
      exit(1);
    }
  status_t stt;
  stt.stt=1;
  int sothutu;
  singly_linked_list_offset_of_element(a, *current, &sothutu);
  printf("Offset hien tai la: %d\n", sothutu);
  if(huong == '<')
    {
      if( (sothutu-number_element) < 0)
	{
	  printf("Warring!!!!\nWarring!!!!\nWarring!!!!\nWarring!!!!\nOut control the bus data!\n");
	  exit(1);
	}
      sothutu-=number_element;
      singly_linked_list_element(a,sothutu,current);
      // Tra ve stt=0 neu khong co loi;
      stt.stt=0;
      return stt;
    }
  if(huong == '>')
    {
      if( (sothutu + number_element) >= a.sizeofdata)
	{
	  printf("Warring!!!!!\nWarring!!!!\nWarring!!!!\nWarring!!!!\nOut control the bus data!\n");
	  exit(1);
	}
      sothutu+=number_element;
      singly_linked_list_element(a,sothutu,current);
      // Tra ve stt =0 neu khong co loi;
      stt.stt=0;
      return stt;
    }
  // Tra ve stt=0 neu khong co loi;
  stt.stt=0;
  return stt;
}
