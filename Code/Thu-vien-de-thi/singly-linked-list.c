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
  if(temp == NULL)
    {
      printf("Co loi khi cap phat bo nho!\n");
      exit(1);
    }
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

status_t singly_linked_list_linked_blocks_and_blocks(blocks nhat, blocks nhi)
{
  if(nhat.size != nhi.size)
    {
      printf("Size cua block thu nhat khac size cua blocks thu 2!!!!\n");
      printf("Khong the gan blocks thu 2 vao sau blocks thu nhat duoc!!!!\n");
      exit(1);
    }
  if(nhat.adress == NULL)
    {
      printf("Blocks thu nhat co adress = NULL!\n");
      exit(1);
    }
  if(nhi.adress == NULL)
    {
      printf("Blocks thu hai co adress = NULL!\n");
      exit(1);
    }
  status_t stt;
  stt.stt=1;
  void* t;
  t=nhat.adress;
  t+=(nhat.size - sizeof(blocks));
  ((blocks*)t)->adress=nhi.adress;
  stt.stt=0;
  return stt;
}

status_t singly_linked_lits_delete_current_blocks(singly_linked_list_bus* a, blocks* curr)
{
  if(curr->adress == NULL)
    {
      printf("Blocks current co adress = NULL!\n");
      exit(1);
    }
  if(a->sizeofdata != (curr->size - sizeof(blocks)))
    {
      printf("Size data khai bao trong Bus khong khop voi size data trong current!\n");
      exit(1);
    }
  status_t stt;
  stt.stt =1;
  blocks t;
  t.adress = curr->adress;
  t.size = curr->size;
  if(t.adress == (a->firts).adress)
    {
      singly_linked_list_seek( *a,&(a->firts), '>', 1);
      free(curr->adress);
      curr->adress=NULL;
      // Update bus
      a->sizeofbus-=1;
      stt.stt =0;
      return stt;
    }
  if(t.adress == (a->end).adress)
    {
      singly_linked_list_seek(*a,&(a->end),'<',1);
      free(curr->adress);
      curr->adress = NULL;
      // Update bus;
      a->sizeofbus-=1;
      stt.stt=0;
      return stt;
    }
  void* t3;
  t3=t.adress;
  singly_linked_list_seek(*a, curr,'<',1);
  singly_linkes_list_seek(*a, &t, '>',1);
  singly_linked_list_linked_blocks_and_blocks(*curr, t);
  free(t3);
  // Update bus;
  a->sizeofbus-=1;
  stt.stt=0;
  return stt;
}

status_t sinly_linked_list_insert_prew_current_blocks(singly_linked_list_bus* a, blocks curr, blocks add)
{
  int tt;
  if(curr.adress == NULL)
    {
      printf("Blocks current co adress = NULL!\n");
      exit(1);
    } 
  if(add.adress == NULL)
    {
      printf("Blocks can them vao co adress = NULL!\n");
      exit(1);
    }
  if(curr.size != (a->sizeofdata +sizeof(blocks)))
    {
      printf("Kich thuoc du lieu blocks current khong tuong thich voi bus du lieu!\n");
      exit(1);
    }
  if(add.size != (a->sizeofdata + sizeof(blocks)) )
    {
      printf("Blocks can insert co kich thuoc du lieu khong tuong thich voi bus du lieu!\n");
      exit(1);
    }
  status_t stt;
  stt.stt =1;
  singly_linked_list_offset_of_element(*a, curr, &tt);
  blocks bl;
  bl.size=curr.size;
  bl.adress=malloc(curr.size);
  if(bl.adress == NULL)
    {
      printf("Co loi khi cap phat!\n");
      exit(1);
    }
  copy_blocks_to_blocks(add,bl);
  bl.adress+=(curr.size - sizeof(blocks));
  ((blocks*)(bl.adress))->size=curr.size;
  ((blocks*)(bl.adress))->adress=NULL;
  bl.adress-=(curr.size - sizeof(blocks));
  if(tt ==0)
    {
      singly_linked_list_linked_blocks_and_blocks(bl,curr);
      (a->firts).adress=bl.adress;
      // Update bus;
      a->sizeofbus+=1;
      stt.stt =0;
      return stt;
    }
  singly_linked_list_linked_blocks_and_blocks(bl,curr);
  singly_linked_list_seek(*a, &curr, '<', 1);
  singly_linked_list_linked_blocks_and_blocks(curr,bl);
  // Update bus;
  a->sizeofbus++;
  stt.stt=0;
  return stt;
}

status_t singly_linked_list_insert_next_current_blocks(singly_linked_list_bus* a, blocks curr, blocks add)
{
  if(curr.adress == NULL)
    {
      printf("Blocks hien tai co adress = NULL!\n");
      exit(1);
    }
  if(add.adress == NULL)
    {
      printf("Blocks can chen co adress = NULL!\n");
      exit(1);
    }
  if(curr.size != (a->sizeofdata + sizeof(blocks)))
    {
      printf("Kich co dang ki trong blocks hien tai khong khop voi kich co da dang ki trong bus!\n");
      exit(1);
    }
  if(curr.size != add.size)
    {
      printf("Kich co du lieu blocks hien tai va blocks can chen khong tuong thich!\n");
      exit(1);
    }
  status_t stt;
  stt.stt=1;
  blocks bl;
  bl.adress=malloc(curr.size);
  if(bl.adress == NULL)
    {
      printf("Khong the cap phat bo nho dong duoc!\n");
      exit(1);
    }
  bl.size=add.size;
  copy_blocks_to_blocks(add,bl);
  bl.adress+=(bl.size-sizeof(blocks));
  ((blocks*)(bl.adress))->adress=NULL;
  ((blocks*)(bl.adress))->size=add.size;
  if(curr.adress == (a->end).adress)
    {
      singly_linked_list_linked_blocks_and_blocks(a->end,bl);
      (a->end).adress=bl.adress;
      // Update bus;
      a->sizeofbus++;
      stt.stt=0;
      return stt;
    }
  singly_linked_list_linked_blocks_and_blocks(curr,bl);
  singly_linked_list_seek(*a, &curr, '>', 1);
  singly_linked_list_linked_blocks_and_blocks(bl,curr);
  // Update bus;
  a->sizeofbus++;
  stt.stt=0;
  return stt;
}


