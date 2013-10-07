#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
  char stt[6];
  char mssv[13];
  char hoten[40];
  char sdt[15];
  float diem;
}sv;

int khaosat(char*, char*);
void load_mangcautruc(char* , sv*, int, char);
void input_mangcautruc(sv*, int);
void save_mangcautruc(char*, sv*, int, char);
int main(int argc, char* argv[])
{
  int soluongsv;
  sv* mangcautruc;
  char key;
  soluongsv=khaosat(argv[1],&key);
  mangcautruc=(sv*)malloc(sizeof(sv)*soluongsv);
  load_mangcautruc(argv[1],mangcautruc, soluongsv,key);
  input_mangcautruc(mangcautruc, soluongsv);
  save_mangcautruc(argv[2],mangcautruc, soluongsv,key);
  printf("Da luu xong diem cho cac sinh vien!\n");
  getchar();
  return 0;
}

int khaosat(char* in, char* key)
{
  FILE *inp;
  inp=fopen(in,"r");
  if(inp == NULL)
    {
      printf("Khong the mo duoc file danh sach sinh vien\n");
      exit(1);
    }
  printf("Ki tu ma ban dung de ngan cach giua cac truong cua sinh vien la: ");
  scanf("%c", key);
  while( getchar() != '\n');
  int sosinhvien;
  char block_sv, read;
  block_sv=0;
  sosinhvien=0;
  while(1)
    {
      read=fgetc(inp);
      if( (read != EOF) && (read !='\n') && (block_sv == 0) )
	{
	  block_sv =1;
	  sosinhvien++;
	  continue;
	}
      if( ((read == EOF) ||( read == '\n')) )
	{
	  block_sv=0;
	  if(read == EOF)
	    {
	      break;
	    }
	}
    }
  printf("Trong lop co %d sinh vien.\n", sosinhvien);
  fclose(inp);
  return sosinhvien;
}

void load_mangcautruc(char* in, sv* mangct, int sosv, char key)
{
  FILE *inp;
  inp=fopen(in,"r");
  if(inp == NULL)
    {
      printf("Khong the mo duoc file danh sach sinh vien!\n");
      exit(1);
    }
  char block, read;
  char buff[80], buff_count;
  block =0;
  for(;sosv;sosv--)
    {
      while(1)
	{
	  read=fgetc(inp);
	  if( (block == 0) && read != '\n' && read != ' ')
	    {
	      buff_count =0;
	      while(1)
		{
		  if( read == key)
		    {
		      read =0;
		    }
		  buff[buff_count++]=read;
		  read=fgetc(inp);
		  if(read == '\n' || read == EOF)
		    {
		      if( read == '\n')
			{
			  buff[buff_count]=0;
			  break;
			}
		      break;
		    }
		}
	      break;
	    }
	}
      buff_count=0;
      strcpy(mangct->stt,&buff[buff_count]);
      while(buff[buff_count++]!=0);
      strcpy(mangct->mssv,&buff[buff_count]);
      while(buff[buff_count++]!=0);
      strcpy(mangct->hoten,&buff[buff_count]);
      while(buff[buff_count++]!=0);
      strcpy(mangct->sdt, &buff[buff_count]);
      block=0;
      mangct++;
    }
  printf("Da load xong danh sach lop\n");
  printf("Ban hay nhan phim bat ki de tien hanh nhap diem cho lop!\n");
  getchar();
  return;
}

void input_mangcautruc(sv* mangct, int sosv)
{
  float diem;
  while(sosv)
    {
      printf("Sinh vien co:\nSTT:%s\nMSSV: %s\nHo va ten: %s\nSDT: %s\nBan hay nhap diem: ",mangct->stt,mangct->mssv,mangct->hoten,mangct->sdt);
      scanf("%f",&diem);
      while(getchar() != '\n');
      while(diem < 0 || diem > 10)
	{
	  printf("Diem ma ban nhap vao khong hop le, ban hay nhap lai: ");
	  scanf("%f", &diem);
	}
      mangct->diem=diem;
      sosv--;
      mangct++;
    }
  printf("Da nhap xong diem cho ca lop, ban hay nhan phim bat ki de tiep tuc chuong trinh\n");
  getchar();
  return;
}

void save_mangcautruc(char* out, sv* mangct, int sosv, char key)
{
  FILE *outp;
  outp=fopen(out,"w");
  if(outp == NULL)
    {
      printf("Khong the mo duoc file de luu diem cho ca lop\n");
      exit(1);
    }
  while(sosv--)
    {
      fprintf(outp,"%s%c%s%c%s%c%s%c%g\n",mangct->stt, key, mangct->mssv, key, mangct->hoten, key, mangct->sdt, key, mangct->diem);
      mangct++;
    }
  printf("Da luu diem cua ca lop vao file\n");
  getchar();
  return;
}
