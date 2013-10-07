#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define songuoi 7

typedef struct
{
  char name[40];
  char phone[15];
  char email[40];
}contact;

int main(int argc, char* argv[])
{
  int start, end;
  char count;
  printf("Ban muon doc tu nguoi thu may: ");
  scanf("%d", &start);
  while(getchar() != '\n');
  while( (start < 0)|| (start > songuoi) )
    {
      printf("Ban hay nhap lai vi tri bat dau: ");
      scanf("%d", &start);
      while( getchar() != '\n');
    }
  printf("Ban muon doc den nguoi thu may: ");
  scanf("%d", &end);
  while( getchar() != '\n');
  while( (end < start) || (end > songuoi) )
    {
      printf("Ban hay nhap lai den nguoi thu may, luu y, no khong the nho hon nguoi bat dau va cung khong the lon hon so nguoi co trong adress duoc:");
      scanf("%d", &end);
      while(getchar()!='\n');
    }
  FILE *file;
  file=fopen(argv[1], "rb");
  if( file == NULL)
    {
      printf("Loi khong the mo duoc file!\n");
      exit(1);
    }
  if(fseek(file, (start-1)*sizeof(contact),SEEK_SET) != 0)
    {
      printf("Khong the nhay file duoc!\n");
      exit(1);
    }
  contact *new, *new2;
  new=(contact*)malloc((end-start+1)*sizeof(contact));
  if(new == NULL)
    {
      printf("Khong the cap phat!\n");
      exit(1);
    }
  fread(new,sizeof(contact),(end-start+1),file);
  new2=new;
  printf("Cac thong tin cua ho la:\n");
  for(count =0; count < (end-start+1);count++)
    {
      printf("Name: %s\n",new2->name);
      printf("Phone: %s\n",new2->phone);
      printf("Email: %s\n",new2->email);
      new2++;
    }
  new2=new;
  for(count =0; count < (1+end-start); count++)
    {
      printf("Sua cho nguoi thu: %d", count+1);
      printf("Name: ");
      gets(new2->name);
      printf("Phone: ");
      gets(new2->phone);
      printf("Mail: ");
      gets(new2->email);
      new2++;
    }
  fclose(file);
  file=fopen(argv[1],"rb+");
  if(file == NULL)
    {
      printf("Khong the luu chinh sau duoc\n");
      exit(1);
    }
  if(fseek(file, (start-1)*sizeof(contact),SEEK_SET) != 0)
    {
      printf("Khong the nhay file duoc!\n");
      exit(1);
    }
  fwrite(new,sizeof(contact),end-start+1,file);
  free(new);
  fcloseall();
  getchar();
  return 0;
}
