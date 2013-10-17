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

status_t sinhly_linked_list_copy_blocks_to_blocks(blocks a, blocks b)
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

status_t singly_linked_list_swap_data_blocks_to_blocks(blocks a, blocks b)
{
  status_t stt;
  stt.stt =1;
  if( a.size != b.size)
  {
    printf("singly_linked_list_swap_blocks_to_blocks: Lỗi! Kích thước 2 blocks không tương thích.\n");
    exit(1);
  }
  a.size-=sizeof(blocks);
  b.size-=sizeof(blocks);
  blocks tmp;
  tmp.adress=malloc(a.size);
  if( tmp.adress == NULL)
  {
    printf("singly_linked_list_swap_data_blocks_to_blocks: Lỗi không thể cấp phát blocks động.\n");
    exit(1);
  }
  tmp.size=a.size;
  singly_linked_list_copy_blocks_to_blocks(a, tmp);
  singly_linked_list_copy_blocks_to_blocks(b,a);
  singly_linked_list_copy_blocks_to_blocks(tmp,b);
  free(tmp.adress);
  stt.stt=0;
  return stt;
}

status_t singly_linked_list_swap_blocks_of_blocks_to_blocks(blocks a, blocks b)
{
/*
  if( (a.size) != (b.size ) )
  {
    printf("singly_linked_list_swap_blocps_of_blocks_to_blocks: Lỗi! Kíc thước 2 blocks không tương thích.\n");
    exit(1);
  }
*/
  int size_tmp;
  status_t stt;
  stt.stt=1;
  size_tmp = a.size;
  size_tmp-=sizeof(blocks);
  a.size=sizeof(blocks);
  b.size=sizeof(blocks);
  a.adress+=size_tmp;
  b.adress+=size_tmp;
  blocks t;
  t.size=sizeof(blocks);
  t.adress=malloc(t.size);
  if(t.adress == NULL)
  {
    printf("singly_linked_list_swap_blocks_of_blocks_to_blocks: Lỗi! Không thể cấp phát blocks động.\n");
    exit(1);
  }
  singly_linked_list_copy_blocks_to_blocks(a,t);
  singly_linked_list_copy_blocks_to_blocks(b,a);
  singly_linked_list_copy_blocks_to_blocks(t,b);
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
  sinhly_linked_list_copy_blocks_to_blocks(add,new);
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

status_t singly_linked_list_delete_current_blocks(singly_linked_list_bus* a, blocks* curr)
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
  singly_linked_list_seek(*a, &t, '>',1);
  singly_linked_list_linked_blocks_and_blocks(*curr, t);
  free(t3);
  // Update bus;
  a->sizeofbus-=1;
  stt.stt=0;
  return stt;
}

status_t singly_linked_list_insert_prew_current_blocks(singly_linked_list_bus* a, blocks curr, blocks add)
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
  sinhly_linked_list_copy_blocks_to_blocks(add,bl);
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
  bl.size=curr.size;
  bl.adress=malloc(curr.size);
  if(bl.adress == NULL)
    {
      printf("Khong the cap phat bo nho dong duoc!\n");
      exit(1);
    }
  sinhly_linked_list_copy_blocks_to_blocks(add,bl);
  bl.adress+=(curr.size - sizeof(blocks));
  ((blocks*)(bl.adress))->adress=NULL;
  ((blocks*)(bl.adress))->size=curr.size;
  bl.adress-=(curr.size - sizeof(blocks));
  int tt;
  singly_linked_list_offset_of_element(*a,curr,&tt);
  if( tt == (a->sizeofbus -1))
    {
      singly_linked_list_linked_blocks_and_blocks(a->end,bl);
      (a->end).adress=bl.adress;
      // Update bus;
      a->sizeofbus++;
      stt.stt=0;
      return stt;
    }
  add.adress=curr.adress;
  add.size=curr.size;
  singly_linked_list_seek(*a, &add, '>', 1);
  singly_linked_list_linked_blocks_and_blocks(bl,add);
  singly_linked_list_linked_blocks_and_blocks(curr,bl);
  // Update bus;
  a->sizeofbus++;
  stt.stt=0;
  return stt;
}

status_t singly_linked_list_insert_auto_sort(singly_linked_list_bus* a, char hamsosanh(blocks lef, blocks rig), blocks add)
{
  if(a->sizeofdata != (add.size-sizeof(blocks)))
    {
      printf("Singly_linked_list_insert_auto_sort: Sizeof data != sizeofdata in blocks add.\n");
      exit(1);
    }
  status_t stt;
  stt.stt=1;
  if(a->sizeofbus == 0)
    {
      singly_linked_list_bus_add_end(a,add);
      stt.stt=0;
      return stt;
    }
  blocks trungchuyen1;
  int vitri1;
  int conchay1;
  char bingo;
  bingo=0;
  for(conchay1=0;conchay1 < a->sizeofbus;conchay1++)
  {
    singly_linked_list_element(*a,conchay1,&trungchuyen1);
    if(hamsosanh(add,trungchuyen1) == -1)
    {
      bingo=1;
      break;
    }
  }
  if(bingo ==0)
  {
    singly_linked_list_insert_next_current_blocks(a,trungchuyen1,add);
    stt.stt=0;
    return stt;
  }
  if(bingo == 1)
  {
    singly_linked_list_insert_prew_current_blocks(a,trungchuyen1,add);
    stt.stt=0;
    return stt;
  }
  stt.stt=0;
  return stt;
}


status_t singly_linked_list_selection_sort(singly_linked_list_bus* a, char hamsosanh(blocks lef, blocks rig), char huong)
{
  status_t stt;
  if(a == NULL)
  {
    printf("singly_linked_list_selection_sort: Lỗi! Con trỏ bus cần sắp xếp NULL.\n");
    exit(1);
  }
  if( a->sizeofbus == 1)
  {
    return stt;
  }
  blocks select, run, mark;
  int conchay1, conchay2;
  if( huong != '<' && huong != '>')
  {
    printf("singly_linked_list_selection_sort: Lỗi! Hướng không phù hợp.\n");
    exit(1);
  }
  if( huong == '<')
  {
    for(conchay1=0;conchay1 < (a->sizeofbus -1); conchay1++)
    {
      singly_linked_list_element(*a, conchay1, &select);
      mark=select;
      for(conchay2=conchay1+1; conchay2< a->sizeofbus; conchay2++)
      {
        singly_linked_list_element(*a, conchay2, &run);
        if(hamsosanh(mark,run) == 1)
        {
          mark=run;
        }
      }
      if(mark.adress != select.adress)
      {
        singly_linked_list_swap_data_blocks_to_blocks(select, mark);
      }
    }
    stt.stt=0;
    return stt;
  }
  for(conchay1=0; conchay1 < (a->sizeofbus -1); conchay1++)
  {
    singly_linked_list_element(*a, conchay1, &select);
    mark=select;
    for(conchay2=conchay1+1; conchay2 < a->sizeofbus; conchay2++)
    {
      singly_linked_list_element(*a, conchay2, &run);
      if(hamsososanh(mark,run) == -1)
      {
        mark=run;
      }
    }
    if(mark.adress!= select.adress)
    {
      singly_linked_list_swap_data_blocks_to_blocks(select, mark);
    }
  }  
  stt.stt=0;
  return stt;
}

status_t singly_linked_list_search(singly_linked_list_bus a, char hamsosanh(blocks original, blocks input), blocks* return_point)
{
  if(return_point == NULL)
  {
    printf("singly_linked_list_search: Lỗi! Con trỏ blocks cần tìm NULL.\n");
    exit(1);
  }
  if( (return_point->size - sizeof(blocks)) != a.sizeofdata )
  {
    printf("singly_linked_list_search: Lỗi! Giá trị size data khong tương đồng size data trong bus.\n");
    exit(1);
  }
  int conchay1;
  blocks trungchuyen1;
  status_t stt;
  stt.stt =-1;
  for(conchay1=0; conchay1 < a.sizeofbus; conchay1++)
  {
    singly_linked_list_element(a, conchay1, &trungchuyen1);
    if(!hamsosanh(*return_point, trungchuyen1))
    {
      *return_point=trungchuyen1;
      stt.stt=conchay1;
      return stt;
    }
  }
  return_point->adress=NULL;
  return stt;
}

status_t singly_list_search_divide_to_conpuer(singly_linked_list_bus a, char hamsosanh(blocks lef, blocks rig), blocks* return_point)
{
  status_t stt;
  stt.stt =-1;
  if(a.sizeofbus == 0)
  {
    return stt;
  }
  blocks trungchuyen1;
  int vt1, vt2;
  vt1=0;
  vt2= (a.sizeofbus -1);
  singly_linked_list_element(a, vt1, &trungchuyen1);
  switch(hamsosanh(*return_point, trungchuyen1))
  {
    case 0:
    {
      stt.stt=0;
      *return_point=trungchuyen1;
      return stt;
    }
    case 1:
    {
      break;
    }
    case -1:
    {
      return_point->adress=NULL;
      return stt;
    }
  }
  singly_linked_list_element(a, vt2, &trungchuyen1);
  switch(hamsosanh(*return_point, trungchuyen1))
  {
    case 0:
    {
      *return_point=trungchuyen1;
      stt.stt=vt2;
      return stt;
    }
    case 1:
    {
      return_point->adress=NULL;
      return stt;
    }
    case -1:
    {
      break;
    }
  }
  while((vt2 - vt1) > 1)
  {
    singly_linked_list_element(a, (vt1+vt2)/2, &trungchuyen1);
    switch(hamsosanh(*return_point, trungchuyen1))
    {
      case 0:
      {
        stt.stt=((vt1+vt2)/2);
        *return_point=trungchuyen1;
      }
      case 1:
      {
        vt1=((vt1+vt2)/2);
        break;
      }
      case -1:
      {
        vt2=((vt1+vt2)/2);
        break;
      }
    }
  }
  return_point->adress=NULL;
  return stt;
}

status_t singly_linkedlist_printf_from_t1_to_t2(singly_linked_list_bus a, int t1, int t2, void hamhienthi(blocks))
{
  status_t stt;
  stt.stt =1;
  if(a.sizeofbus == 0)
  {
    printf("Danh sách rỗng.\n");
    stt.stt=0;
    return stt;
  }
  if(t1 < t2)
  {
    printf("singly_linked_list_printf_from_t1_to_t2: Lỗi do vị trí 1 lớn hơn vị trí 2.\n");
    exit(1);
  }
  if( (t1 < 0) || (t2 > (a.sizeofbus +1)))
  {
    if(t1 < 0)
    {
      printf("singly_linked_list_printf_from_t1_to_t2: Lỗi do vị trí t1 không thích hợp.\n");
      exit(1);
    }
    printf("singly_linked_list_printf_from_t1_to_t2: Lỗi do vị trí t2 không thích hợp.\n");
    exit(1);
  }
  blocks trungchuyen1;
  int conchay1;
  for(conchay1=t1; conchay1 <=t2; conchay1++)
  {
    singly_linked_list_element(a, conchay1, &trungchuyen1);
    hamhienthi(trungchuyen1);
  }
  stt.stt=0;
  return stt;
}
status_t singly_linked_list_repawn(singly_linked_list_bus* a)
{
  if( a == NULL)
  {
    printf("singly_linked_list_repawn: Lỗi! Con trỏ bus rỗng.\n");
  }
  status_t stt;
  stt.stt=1;
  if(a->sizeofbus == 0)
  {
    stt.stt =0;
    return stt;
  }
  int conchay1;
  conchay1=(a->sizeofbus -1);
  blocks trungchuyen1, trungchuyen2;
  singly_linked_list_element(*a, conchay1, &trungchuyen2);
  while(conchay1-- > 0)
  {
    singly_linked_list_element(*a, conchay1, &trungchuyen1);
    singly_linked_list_linked_blocks_and_blocks(trungchuyen2, trungchuyen1);
    trungchuyen2=trungchuyen1;
  }
  trungchuyen1=a->firts;
  a->firts=a->end;
  a->end=trungchuyen1;
  stt.stt=0;
  return stt;
}

status_t linked_list_destroi_all_bus(singly_linked_list_bus* a)
{
  if(a == NULL)
  {
    printf("linked_list_destroi_all_bus: Lỗi! Con trỏ đến bus NULL.\n");
    exit(1);
  }
  status_t stt;
  stt.stt=1;
  if( a->sizeofbus == 0)
  {
    stt.stt=0;
    return stt;
  }
  int conchay1;
  conchay1=(a->sizeofbus -1);
  blocks trungchuyen1;
  for(;conchay1>=0;conchay1--)
  {
    singly_linked_list_element(*a, conchay1, &trungchuyen1);
    singly_linked_list_delete_current_blocks(a, &trungchuyen1);
  }
  stt.stt=0;
  return stt;
}


