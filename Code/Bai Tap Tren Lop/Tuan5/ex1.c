#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
  char name[40];
  char phone[15];
  char email[40];
}contact;

int main(int argc, char* argv[])
{
  contact adress[100];
  int songuoi;
  contact *new, *new2;
  char count;
  FILE *file;
  printf("Ban hay nhap vao so nguoi muon luu contact: ");
  scanf("%d", &songuoi);
  while(getchar() != '\n');
  while( songuoi < 0 || songuoi> 100)
    {
      printf("Ban hay nhap lai so nguoi, luu y so nguoi phai > 0 va < 100: ");
      scanf("%d",&songuoi);
      while( getchar() != '\n');
    }
  for(count =0; count < songuoi; count++)
    {
      printf("Ban hay nhap vao ho va ten cua nguoi thu %d: ", count+1);
      gets(adress[count].name);
      printf("Ban hay nhap vao so dien thoai cua %s:",adress[count].name);
      gets(adress[count].phone);
      printf("Ban hay nhap vao email cua %s: ", adress[count].name);
      gets(adress[count].email);
    }
  file=fopen(argv[1],"wb");
  if(file == NULL)
    {
      printf("Khong the mo duoc file!!!\n");
      exit(1);
    }
  fwrite(adress,sizeof(contact),songuoi,file);
  fclose(file);
  new=(contact*)malloc(sizeof(contact)*songuoi);
  if(new == NULL)
    {
      printf("Khong cap phat dc bo nho\n");
      return 0;
    }
  file=fopen(argv[1],"rb");
  if(file == NULL)
    {
      printf("Loi khi mo file de doc lai!\n");
      exit(1);
    }
  fread(new,sizeof(contact),songuoi,file);
  fclose(file);
  new2=new;
  for(count=0; count< songuoi; count++)
    {
      printf("Thong tin cua nguoi thu: %d\n",count+1);
      printf("Name: %s\n",new->name);
      printf("Phone: %s\n",new->phone);
      printf("Email: %s\n", new->email);
      new++;
    }
  free(new2);
  getchar();
  return 0;
}
