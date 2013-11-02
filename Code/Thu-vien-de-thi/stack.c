#include "stack.h"

////////////////////////////////////////////////////////////////
void Init_stack_msg(char* string)
{
  printf("Init_stack: %s\n", string);
}

status_t Init_stack(stack* stack_bus, int sizeofdata)
{
  status_t stt;
  stack_bus->max_element_in_stack = -1;
  singly_linked_list_bus_init(&stack_bus->bus, sizeofdata);
  return stt;
}


/////////////////////////////////////////////////////////////////
int IsEmpty(stack a)
{
  if(a.bus.sizeofbus == 0)
    {
      return 1;
    }
  return 0;
}

//////////////////////////////////////////////////////////////////
int IsFull(stack a)
{
  if(a.bus.sizeofbus == a.max_element_in_stack)
    {
      return 1;
    }
  return 0;
}

/////////////////////////////////////////////////////////////////
void Push_msg(char* string)
{
  printf("Push: %s\n", string);
}

status_t Push(blocks add, stack* stack_bus)
{
  status_t stt;
  stt.stt=1;
  // Kiem tra xem co bi gioi han tran stack hay khong;
  if( stack_bus->max_element_in_stack != -1 && IsFull(*stack_bus))
    {
      Push_msg("Stack bi han che tran, tran stack!");
      exit(1);
    }

  if(IsEmpty(*stack_bus))
    {
      singly_linked_list_bus_add_end(&stack_bus->bus, add);
      printf("Phan tu dau tien cua stack\n");
      return stt;
    }
  // Tao con tro blocks vao phan tu thu 0 cua stack;
  blocks* prt;
  singly_linked_list_element(stack_bus->bus, 0, prt);
  // Chen vao stack mot phan tu truoc phan tu hien tai;
  singly_linked_list_insert_prew_current_blocks(&(stack_bus->bus), *prt, add);
  stt.stt=0;
  printf("Phan tu tiep theo cua stack\n");
  return stt;
}

///////////////////////////////////////////////////////////////////
void Pop_msg(char* string)
{
  printf("Pop: %s\n", string);
}

status_t Pop(blocks* buff, stack* stack_bus)
{
  // Kiem tra xem stack co bi rong hay khong.
  if(stack_bus->bus.sizeofbus == 0)
    {
      Pop_msg("Stach bi rong, khong Pop duoc.");
      exit(1);
    }
  status_t stt;
  // Khoi tao mot con tro blocks den phan tu thu 0 cua stack;
  blocks* prt;
  singly_linked_list_element(stack_bus->bus, 0, prt);
  singly_linked_list_copy_blocks_to_blocks(*prt, *buff);
  singly_linked_list_delete_current_blocks(&stack_bus->bus, prt);
  return stt;
}

/////////////////////////////////////////////////////////////////////
void ViewTop_msg(char* string)
{
  printf("ViewTop: %s\n", string);
}

status_t ViewTop(blocks* buff, stack stack_bus)
{
  status_t stt;
  // Kiem tra xem stack rong hay khong;
  if(IsEmpty(stack_bus))
    {
      ViewTop_msg("Stack da bi rong, khong the view.");
      exit(1);
    }
  // Khoi tao mot con tro den dau stack;
  blocks* prt;
  singly_linked_list_element(stack_bus.bus, 0, prt);
  singly_linked_list_copy_blocks_to_blocks(*prt, *buff);
  return stt;
}
