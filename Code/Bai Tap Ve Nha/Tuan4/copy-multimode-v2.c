#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void cp_char(char* , char*);
void cp_line(char* , char*);
void cp_blocks(char* , char*);

int main(int argc, char* argv[])
{
  int choice;
  while(1)
    {
      system("clear");
      printf("Ban hay lua chon mode:\n");
      printf("1) Copy theo ki tu.\n");
      printf("2) Copy theo dong.\n");
      printf("3) Copy theo blocks.\n");
      printf("4) Thoat.\n");
      scanf("%d", &choice);
      while(getchar() != '\n');
      switch(choice)
	{
	case 1:
	  {
	    cp_char(argv[1],argv[2]);
	    break;;
	  }
	case 2:
	  {
	    cp_line(argv[1],argv[2]);
	    break;
	  }
	case 3:
	  {
	    cp_blocks(argv[1], argv[2]);
	    break;
	  }
	}
      if(choice == 4)
	{
	  break;
	}
    }
  return 0;
}

void cp_char(char* in, char* out)
{
  FILE *input, *output;
  time_t t;
  t=clock();
  input=fopen(in,"r");
  if(input == NULL)
    {
      printf("Khong the mo duoc file nguon !!!!!!\n");
      return;
    }
  output=fopen(out,"w");
  if(output ==NULL)
    {
      printf("Khong the mo duoc file dich !!!!!!\n");
      return;
    }
  printf("Dang tien hanh sao chep!\n");
  char c;
  while( (c=fgetc(input))!= EOF)
    {
      fputc(c,output);
    }
  t=clock()-t;
  printf("Da sao chep xong!\n");
  printf("Hoan thanh tac vu trong %d clicks %gs\n",t,((float)t)/CLOCKS_PER_SEC);
  printf("Ban hay nhan phim bat ki de tiep tuc.\n");
  getchar();
  fcloseall();
  return;
}

void cp_line(char* in, char* out)
{
  FILE *input, *output;
  time_t t;
  t=clock();
  input=fopen(in,"r");
  if( input == NULL)
    {
      printf("Khong the mo duoc file nguon !!!!\n");
      return;
    }
  output=fopen(out, "w");
  if(output == NULL)
    {
      printf("Khoong the mo duoc file dich !! \n");
      return;
    }
  char str[80];
  printf("Dang tien hanh sao chep.\n");
  while(fgets(str,80,input))
    {
      fputs(str,output);
    }
  t=clock()-t;
  printf("Da sao chep xong!\n");
  printf("Hoan thanh tac vu trong %d clicks %gs\n",t,((float)t)/CLOCKS_PER_SEC);
  printf("Ban hay nhan phim bat ki de tiep tuc\n");
  getchar();
  fcloseall();
  return;
}

void cp_blocks(char* in, char* out)
{
  int size;
  size =0;
  while( size <=0)
    {
      printf("Ban hay nhao vao kich thuoc cua blocks can sao chep: ");
      scanf("%d", &size);
      while( getchar() != '\n');
    }
  time_t t;
  FILE *input, *output;
  t=clock();
  input=fopen(in, "rb");
  if(input == NULL)
    {
      printf("Khong the mo duoc file nguon!!!\n");
      return;
    }
  output=fopen(out,"wb");
  if(output == NULL)
    {
      printf("Khong the mo duoc file nguon!!!! \n");
      return;
    }
  void *block;
  int size_read;
  printf("Point0\n");
  block=malloc(sizeof(char)*size);
  while( (size_read =fread(block,sizeof(char),size,input)))
    {
      fwrite(block,sizeof(char),size_read,output);
    }
  free(block);
  t=clock()-t;
  printf("Da sao chep xong!\n");
  printf("Hoan thanh tac vu trong %d clicks %gs\n",t, ((float)t)/CLOCKS_PER_SEC);
  printf("Ban hay nhan phim bat ki de tiep tuc\n");
  getchar();
  fcloseall();
  return;
}
