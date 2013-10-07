#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main( int argc, char* argv[])
{
  if( argc != 2)
    {
      printf("Error agrument\n\n\n\n");
      exit(1);
    }
  FILE *file;
  if((file=fopen(argv[1],"a+"))== NULL)
    {
      printf("Error!!!!\nCannot open file.\n\n\n\n");
      exit(1);
    }
  char c[2]= {0}, str[120]={0};
  c[0]=fgetc(file);
  strcat(str,c);
  while(1)
    {
      c[0]=fgetc(file);
      if( c[0] == EOF)
	{
	  break;
	}
      if( c[0]== '\n')
	{
	  c[0]=fgetc(file);
	  strcat(str,c);
	}
    }
  fputc('\n',file);
  fprintf(file,"%s",str);
  fcloseall();
  printf("Success\n");
  return 0;
}
