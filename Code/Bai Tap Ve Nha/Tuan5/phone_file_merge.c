#include "WinuxSke.h"

typedef struct
{
  char name[50];
  char phone[15];
  char email[50];
}contact_t;

int khaosat_file(FILE*,char);
void merge_f(FILE*, int, FILE*);

int main(int argc, char* argv[])
{
  FILE *des_f, *f;
  char path[50];
  int temp, socansapnhap;

  if(argc == 1)
    {
      printf("Ban muon sap nhap may file? ");
      scanf("%d", &socansapnhap);
      while( getchar() != '\n');
      while(socansapnhap < 1)
	{
	  system("clear");
	  msg("Ban hay nhap lai so file can sap nhap: ");
	  scanf("%d", &socansapnhap);
	  while( getchar()!= '\n');
	}
      printf("Ban hay nhap ten file dich: ");
      gets(path);
      openfile(&des_f,path,"wb","Khong the mo duoc file dich.");
      for(temp=1;temp<=socansapnhap;temp++)
	{
	  printf("Ban hay nhap file thu %d can sap nhap: ",temp);
	  gets(path);
	  openfile(&f,path,"rb","Khong mo duoc file ma ban vua nhap!!!!!");
	  merge_f(f,sizeof(contact_t),des_f);
	  fclose(f);
	}
      printf("Da tien hanh sap nhap xong!!!!!\n");
      getchar();
      fcloseall();
      return 0;
    }
  else
    {
      if(argc <3)
	{
	  msg("Co loi parameter!!!!");
	  exit(1);
	}
      printf("File dich la: %s\n",argv[1]);
      openfile(&des_f,argv[1],"wb","Khong the mo duoc file dich!!");
      for(temp=2;temp<argc;temp++)
	{
	  printf("Tien hanh sap nhap file %s\n",argv[temp]);
	  openfile(&f,argv[temp],"rb","Khong the mo duoc file nay!!!");
	  merge_f(f,sizeof(contact_t),des_f);
	  fclose(f);
	  printf("Da sap nhap xong file %s\n",argv[temp]);
	}
    }
  printf("Hoan thanh tac vu!!!!\n");
  fcloseall();
  getchar();
  return 0;
}

void merge_f(FILE *f, int size_block, FILE *des_f)
{
  void* point;
  point=malloc(size_block);
  while( fread(point,size_block,1,f) )
    {
      fwrite(point,size_block,1,des_f);
    }
  free(point);
}
