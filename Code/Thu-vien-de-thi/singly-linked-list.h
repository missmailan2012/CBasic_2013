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
  int stt;
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
// Hàm add blocks vào bus và từ động sắp xếp theo chiều tăng dần;
status_t singly_linked_list_insert_auto_sort(singly_linked_list_bus* a, char hamsosanh(blocks,blocks),char huong, blocks add);
// Sắp xếp bus theo thuật tóan sắp xếp chọn selection sort
status_t singly_linked_list_selection_sort(singly_linked_list_bus* a, char hamsosanh(blocks, blocks));
// Tìm một phần tử trong bus theo kiểu chạy từ đầu bus đến cuối bus;
// Vị trí của phần từ tìm thấy nằm trong status_t.stt. Nếu không có thì sẽ trả về -1;
status_t singly_linked_list_search(singly_linked_list_bus a, char hamsosanh(blocks original, blocks input), blocks* return_point);
// Tìm một phần tử bằng thuật tóan chia để trị. Yêu cầu bạn sắp xếp bus trước khi dùng hàm này;
// Vị trí của phần tử tìm thấy nằm trong status_t.stt. Nếu không có thi sẽ trả về -1;
status_t singly_linked_list_search_divide_to_conpuer(singly_linked_list_bus a, char hamsosanh(blocks original, blocks input, blocks* return_point));
// Hàm này có tác dụng trung chuyển từ phần tử thứ t1 đến phần tử thứ t2 cho hàm hiển thị;
// Bạn cần chuẩn bị sẵn hàm hiển thị để dùng hàm này;
status_t singly_linked_list_print_from_t1_to_t2(singly_linked_list_bus a, int 1, int t2, void hamhienthi(blocks));
// Đảo ngược lại bus. Tức là đảo lại thứ tự của bus;
status_t singly_linked_list_repawn(singly_linked_list_bus* a);
// Phá hủy bus dữ liệu, hay là giải phóng bus;
status_t singly_linked_list_destroi_all_bus(singly_linked_list_bus *a);
