#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
  if( argc !=4)
    {
      printf("Error agrument\n\n\n\n");
    }
  FILE *file1, *file2, *file3;
  if((file1=fopen(argv[1],"r"))==NULL || (file2=fopen(argv[2],"r"))== NULL|| (file3=fopen(argv[3],"w"))== NULL)
    {
      printf("Error!!!!\n\n\nCannot open file.\n\n");
      exit(1);
    }
  char c;
  while(1)
    {
      c=fgetc(file1);
      if( c == EOF)
	{
	  while(1)
	    {
	      c=fgetc(file2);
	      if( c== EOF)
		{
		  break;
		}
	      fputc(c,file3);
	    }
	  break;
	}
      else
	{
	  while(1)
	    {
	      if( c == '\n')
		{
		  fputc(c,file3);
		  break;
		}
	      fputc(c,file3);
	      c=fgetc(file1);
	      if( c == EOF)
		{
		  fputc('\n',file3);
		  break;
		}
	    }
	}
      c=fgetc(file2);
      if( c == EOF)
	{
	  while(1)
	    {
	      c=fgetc(file1);
	      if( c == EOF)
		{
		  break;
		}
	      fputc(c,file3);
	    }
	  break;
	}
      else
	{
	  while(1)
	    {
	      if( c == '\n')
		{
		  fputc(c,file3);
		  break;
		}
	      fputc(c,file3);
	      c=fgetc(file2);
	      if( c== EOF)
		{
		  fputc('\n',file3);
		  break;
		}
	    }
	}
    }
  fcloseall();
  printf("Success\n\n\n\n");
  return 0;
}
