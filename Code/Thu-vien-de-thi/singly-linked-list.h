#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct
{
  void* adress;
  int size;
}blocks;

typedef struct
{
  int sizeofdata;
  int sizeofbus;
  blocks firts;
  blocks end;
}singly_linked_list_bus;

typedef struct
{
  char stt;
  void* point;
}status_t;


// Kkoi tao mot bus du lieu, dau vao la dia chi cua bus du lieu, cung kich co int cua truong du lieu;
void singly_linked_list_init(singly_linked_list_bus* , int);
// Copy blocks thu nhat sang blocks thu 2;
status_t copy_blocks_to_blocks(blocks, blocks);
// Nhap vao blocks hien tai no se dieu chinh dia chi blocks dau ra la dia chi ke tiep;
status_t singly_linked_list_element_next(blocks, blocks*);
// Them vua buoi bus data mot blocks;
status_t singly_linked_list_bus_add_end(singly_linked_list_bus*, blocks);
// Tra ve bus la phan tu thu int trong bus du lieu;
status_t singly_linked_list_element(singly_linked_list_bus, int, blocks*);
// Tra ve vi tri cua blocks trong bus data;
status_t singly_linked_list_offset_of_element(singly_linked_list_bus, blocks, int*);
// Dich chuyen con tro blocks hien tai, huong dich chuyen la char, dich chuyen int blocks;
status_t singly_linked_list_seek(singly_linked_list_bus, blocks*, char, int);
