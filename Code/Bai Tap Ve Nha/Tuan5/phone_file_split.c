#include "WinuxSke.h"

typedef struct
{
  char name[50];
  char phone[15];
  char email[50];
}contact_t;

int khaosat_file(FILE*,char);
void split_f(FILE*, int, int, FILE*, FILE*);

int main(int argc, char* argv[])
{
  FILE *sr_f, *f1_f, *f2_f;
  char sr[50], f1[50], f2[50];
  int socontact, socantach;


  if(argc == 1)
    {
      printf("Ban hay nhap vap file can cat: ");
      gets(sr);
      openfile(&sr_f,sr,"rb","Khong the mo duoc file can cat.");
      printf("Ban hay nhap vao ten file thu nhat sau khi tach: ");
      gets(f1);
      openfile(&f1_f,f1,"wb","Khong the mo duoc file sau khi tach thu nhat.");
      printf("Ban hay nhap vao ten file thu hai sau khi tach: ");
      gets(f2);
      openfile(&f2_f,f2,"wb","Khong the mo duoc file sau khi tach thu hai.");
      socontact=khaosat_file(sr_f,sizeof(contact_t));
      while(1)
	{
	  system("clear");
	  msg("Ban muon tach bao nhieu contact vao file thu nhat? ");
	  scanf("%d",&socantach);
	  while( getchar() != '\n');
	  if(socantach <socontact && socantach > 0)
	    {
	      break;
	    }
	}
    }
  else
    {
      check_parameter(argc,5);
      openfile(&sr_f,argv[1],"rb","Khong the mo duoc file nguon");
      socantach=atoi(argv[2]);
      socontact=khaosat_file(sr_f,sizeof(contact_t));
      if(socantach >= socontact || socantach <=0)
	{
	  printf("So contact can tach khong hop le!!!!\n");
	  exit(1);
	}
      openfile(&f1_f,argv[3],"wb","Khong the mo duoc file sau khi tach thu nhat.");
      openfile(&f2_f,argv[4],"wb","Khong the mo duoc file sau khi tach thu hai.");
    }
  split_f(sr_f, sizeof(contact_t), socantach, f1_f, f2_f);
  msg("Da tach xong file!!!!");
  getchar();
  fcloseall();
  return 0;
}

int khaosat_file(FILE* input,char size)
{
  int block;
  void* point;
  point=malloc(size);
  block=0;
  while(fread(point,size,1,input))
    {
      block++;
    }
  rewind(input);
  return block;
}

void split_f(FILE *sr_f, int size_block,int block, FILE *f1, FILE *f2)
{
  void* point;
  point=malloc(size_block);
  while(block--)
    {
      fread(point,size_block,1,sr_f);
      fwrite(point,size_block,1,f1);
    }
  while( fread(point,size_block,1,sr_f) )
    {
      fwrite(point,size_block,1,f2);
    }
  free(point);
}
