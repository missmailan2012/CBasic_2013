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
// Them vao cuoi bus data mot blocks;
status_t singly_linked_list_bus_add_end(singly_linked_list_bus*, blocks);
// Tra ve bus la phan tu thu int trong bus du lieu;
status_t singly_linked_list_element(singly_linked_list_bus, int, blocks*);
// Tra ve vi tri cua blocks trong bus data;
status_t singly_linked_list_offset_of_element(singly_linked_list_bus, blocks, int*);
// Dich chuyen con tro blocks hien tai, huong dich chuyen la char, dich chuyen int blocks;
status_t singly_linked_list_seek(singly_linked_list_bus, blocks*, char, int);
// Noi blocks thu hai vao sau blocks thu nhat;
status_t singly_linked_list_linked_blocks_and_blocks(blocks nhat, blocks nhi);
// Xoa blocks hien tai;
status_t singly_linked_list_delete_current_blocks(singly_linked_list_bus* a, blocks* curr);
// Chen truoc blocks hien tai;
status_t singly_linked_list_insert_prew_current_blocks(singly_linked_list_bus* a, blocks curr, blocks add);
// Chen sau blocks hien tai;
status_t singly_linked_list_insert_next_current_blocks(singly_linked_list_bus* a, blocks curr, blocks add);

// Ham add du lieu vao bus tu dong sap xep;
status_t singly_linked_list_insert_auto_sort(singly_linked_list_bus* a, char hamsosanh(blocks,blocks),char huong, blocks add);
// Tim mot phan tu trong lien ket theo kieu chay tu dau day xuong cuoi day.
status_t singly_linked_list_search(singly_linked_list_bus a, char hambangnhau(blocks original, blocks input), blocks* return_point);
// Hien thi tat ca du lieu trong Bus du lieu. Luu y, ban phai chuan bi ham hien thi data
// Ham nay chi co tac dung tai du lieu tu bus ra block trung chuyen ma thoi.
status_t singly_linked_list_print_all(singly_linked_list_bus a, void hamhienthi(blocks));
// Dao lai bus, tuc la dao nguoc lai danh sach du lieu.
status_t singly_linked_list_repawn(singly_linked_list_bus* a);
status_t singly_linked_list_destroi_all_bus(singly_linked_list_bus *a);
