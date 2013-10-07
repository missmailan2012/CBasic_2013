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

/*
Khao sat xem file co bao nhieu sinh vien.
Kiem tra xem bien key da duoc nguoi dung nhap chua, neu chua thi no se yeu cau nhap, con neu roi thi thoi.
Bien key la bien luu tru ki tu dung de phan cach giua cac truong cua cau truc sv.
*/
int khaosat(char*, char*);

/*
Doc du lieu vao tu file co duong dan la path.
sosv chinh la soluongsv co trong file.
key chinh la ki tu phan cach giua cac truong cua cau truc sv.
*/
void load_mangcautruc(char* path, sv* mangsv, int sosv, char key);

/*
Doc du lieu dang nhi phan tu file co duong dan la path vao mang mangsv.
 */
void load_mangcautruc_nhi_phan(char* path, sv* mangsv, int sosv);

/*
Hien thi thong tin cua sosv sinh vien co trong mangsv
*/
void display_mangcautruc(sv* mangsv, int sosinhvien);

/*
Luu mangsv gom sosv vao file co duong dan path
*/
void save_mangcautruc(char* path, sv* mangsv, int sosv);

/*
Khao sat file dang nhi phan co duong dan la path xem co bao nhieu sinh vien trong do.
*/
int khaosat_nhi_phan(char *path);



int main(int argc, char* argv[])
{
  int soluongsv;
  sv* mangcautruc;
  char key;
  key=0;
  //// Khao sat xem so sinh vien co trong file. Dong thoi nhap ki hieu da dung de phan cach giua cac truong cua cau truc trong file.
  soluongsv=khaosat(argv[1], &key);
  //// Khoi tao mang dong de chua soluongsv da khao sat o tren.
  mangcautruc=(sv*)malloc(sizeof(sv)*soluongsv);
  //// Doc du lieu tu file vao mang dong tren voi ki tu phan cach giua cac truong la: key.
  load_mangcautruc(argv[1], mangcautruc, soluongsv, key);
  //// Luu mang dong tren vao file duoi dang nhi phan.
  save_mangcautruc(argv[2], mangcautruc, soluongsv);
  //// Dong het cac file lai. Giai phong bo nho da malloc de chuan bi lam y sau cua de bai.
  fcloseall();
  free(mangcautruc);

  //// Y thu 2 cua bai toan!!!!!!!!!
  //// Khao sat lai file nhi phan.
  soluongsv=khaosat_nhi_phan(argv[2]);
  ///// Khoi tao mang dong de chua soluongsv vua khao sat.
  mangcautruc=(sv*)malloc(sizeof(sv)*soluongsv);
  if(mangcautruc == NULL)
    {
      printf("Loi cap phat bo nho!!!!");
    }
  //// Doc tu file nhi phan vao mang dong vua tao.
  load_mangcautruc_nhi_phan(argv[2], mangcautruc, soluongsv);
  //// Hien thi mang dong ra man hinh.
  display_mangcautruc(mangcautruc,soluongsv);
  printf("\n\nDa hoan thanh tac vu!\n\n\n");
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
  if(*key ==0)
    {
      printf("Ki tu ma ban dung de ngan cach giua cac truong cua sinh vien la: ");
      scanf("%c", key);
      while( getchar() != '\n');
    }
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
  printf("\n\nTrong lop co %d sinh vien.\n", sosinhvien);
  fclose(inp);
  return sosinhvien;
}

void load_mangcautruc(char* path, sv* mangct, int sosv, char key)
{
  FILE *inp;
  inp=fopen(path,"r");
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
      while(buff[buff_count++]!=0);
      mangct->diem=atof(&buff[buff_count]);
      block=0;
      mangct++;
    }
  printf("Da load xong danh sach lop\n");
  getchar();
  return;
}

void display_mangcautruc(sv* mangct, int sosv)
{
  float diem;
  while(sosv)
    {
      printf("\nSinh vien co:\nSTT:%s\nMSSV: %s\nHo va ten: %s\nSDT: %s\nDiem: %g\n-----------------------------------------------",mangct->stt,mangct->mssv,mangct->hoten,mangct->sdt,mangct->diem);
      sosv--;
      mangct++;
    }
  getchar();
  return;
}

void save_mangcautruc(char* out, sv* mangct, int sosv)
{
  FILE *outp;
  outp=fopen(out,"wb");
  if(outp == NULL)
    {
      printf("Khong the mo duoc file de luu diem cho ca lop\n");
      exit(1);
    }
  fwrite(mangct,sizeof(sv),sosv,outp);
  printf("Da luu diem cua ca lop vao file\n\n");
  getchar();
  fclose(outp);
  return;
}

void load_mangcautruc_nhi_phan(char* path, sv* mangsv, int sosv)
{
  FILE *inp;
  inp=fopen(path,"rb");
  if(inp == NULL)
    {
      printf("Khong the mo duoc file nhi phan da ghi!!!!!\n");
      exit(1);
    }
  if( fread(mangsv,sizeof(sv),sosv,inp) != sosv)
    {
      printf("Co loi trong khi doc file nhi phan. Khong doc du thong tin cua so sinh vien.\n");
      exit(1);
    }
  fclose(inp);
}

int khaosat_nhi_phan(char* path)
{
  int sosv;
  sosv=0;
  FILE *file;
  file=fopen(path,"rb");
  if(file == NULL)
    {
      printf("Khong the tien hanh khao sast file nhi phan!!!!\n");
      exit(1);
    }
  sv *point;
  point=(sv*)malloc(sizeof(sv));
  while( fread(point,sizeof(sv),1,file))
    {
      sosv++;
    }
  free(point);
  fclose(file);
  return sosv;
}
