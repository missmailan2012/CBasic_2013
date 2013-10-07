#include "WinuxSke.h"

typedef struct
{
  char name[50];
  char phone[15];
  char email[50];
}contact_t;

int main(char argc, char* argv[])
{
  char* path;
  if(argc == 1)
    {
      printf("Ban hay nhap vao ten file se dung de luu contact: ");
      gets(path);
    }
  else
    {
      if(argc == 2)
	{
	  strcpy(path,argv[1]);
	}
      else
	{
	  printf("Loi parameter!!!!\n");
	  exit(1);
	}
    }
  FILE *file;
  file=fopen(path,"wb");
  if(file == NULL)
    {
      msg("Khong the mo duoc file de luu.");
      exit(1);
    }
  int tieptuc;
  tieptuc ='y';
  contact_t *cont;
  cont=(contact_t*)malloc(sizeof(contact_t));
  if(cont== NULL)
    {
      msg("Co loi khi xin cap phat bo dem contact_t!!!!\n");
      exit(1);
    }
  while(tieptuc == 'y' || tieptuc == 'Y')
    {
      printf("Ban hay nhap:\n");
      printf("Name: ");
      gets(cont->name);
      printf("Phone: ");
      gets(cont->phone);
      printf("Email: ");
      gets(cont->email);
      fwrite(cont,sizeof(contact_t),1,file);
      printf("Ban co muon tiep tuc nhap vao contact nua khong (y/n)? ");
      scanf("%c",&tieptuc);
      while( getchar() != '\n');
      while( tieptuc != 'y' && tieptuc != 'Y' && tieptuc != 'n' && tieptuc != 'N')
	{
	  printf("Ban co muon tiep tuc nua khong, luu y: y/n? ");
	  scanf("%c", &tieptuc);
	  while(getchar() != '\n');
	}
    }
  free(cont);
  fclose(file);
  return 0;
}
