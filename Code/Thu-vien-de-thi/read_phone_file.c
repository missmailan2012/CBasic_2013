#include "WinuxSke.h"

typedef struct
{
  char name[50];
  char phone[15];
  char email[50];
}contact_t;

int main(int argc, char* argv[])
{
  status_t read_display(FILE*,char);
  FILE *input;
  status_t stt;
  char path_f[100];
  if(argc == 1)
    {
      printf("Ban hay nhap vao file phone can hien thi: ");
      gets(path_f);
      input=fopen(path_f,"rb");
      if(input == NULL)
	{
	  msg("Khong the mo duoc file!!!!");
	  exit(1);
	}
    }
  else
    {
      input=fopen(argv[1],"rb");
      if(input == NULL)
	{
	  msg("Khong the mo duoc file phone can hien thi.");
	  exit(1);
	}
    }
  read_display(input,sizeof(contact_t));
  fcloseall();
  getchar();
  return 0;
}

status_t read_display(FILE *input, char size)
{
  status_t stt;
  contact_t *point;
  point=(contact_t*)malloc(size);
  while( fread(point,size,1,input) )
    {
      printf("-------------------\n");
      printf("Name: %s\n",point->name);
      printf("Phone: %s\n",point->phone);
      printf("Email: %s\n",point->email);
    }
  free(point);
  stt.status=0;
  return stt;
}
