#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
  if( argc != 3)
    {
      printf("Error agrument!!!!\n");
      exit(1);
    }
  FILE *in, *out;
  if( (in=fopen(argv[1],"r")) == NULL || (out=fopen(argv[2],"w")) == NULL)
    {
      printf("Error!!!!\nCannot open file\n\n\n\n");
      exit(1);
    }
  int key;
  while(1)
    {
      system("clear");
      printf("Input the key: ");
      scanf("%d", &key);
      while(getchar()!='\n');
      if( (key <=100)&&(key >=0))
	{
	  break;
	}
    }
  char c;
  while( (c=fgetc(in)) !=EOF )
    {
      printf("Doc duoc ki tu: |%c| co ma %d, decode ki tu: |%c| ma %d\n",c,c,c-key,c-key);
      c-=key;
      fputc(c , out);
    }
  printf("Success!!!!\n");
  fcloseall();
  getchar();
  return 0;
}
