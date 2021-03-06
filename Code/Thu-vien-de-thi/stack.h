#include "singly-linked-list.h"

typedef struct
{
  int max_element_in_stack;
  singly_linked_list_bus bus;
}stack;

// Khoi tao stack;
void Init_stack_msg(char*);
status_t Init_stack(stack* stack_bus, int sizeofdata);

// Kiem tra xem stack co rong hay khong. Neu stack rong tra ve ket qua 1, nguoc lai tra ve 0;
int IsEmpty(stack);


// Kiem tra xem stack co day hay khong. Neu stack day tra ve ket qua 1, nguoc lai tra ve 0;
int IsFull(stack);


// Them vao dau stack mot phan tu blocks;
void Push_msg(char*);
status_t Push(blocks, stack*);


// Day ra tu stack phan tu dau tien;
void Pop_msg(char*);
status_t Pop(blocks*, stack*);


// Xem noi dung chu khong pop phan tu dau tien cua stack;
void ViewTop_msg(char*);
status_t ViewTop(blocks*, stack);
