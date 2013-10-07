#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
  if( argc != 3)
    {
      printf("Error!\n");
      exit(1);
    }
  FILE *in, *out;
  if( (in=fopen(argv[1], "r")) == NULL || (out=fopen(argv[2], "w")) == NULL )
    {
      printf("Cannot open file\n");
      exit(0);
    }
  char c;
  c=getc(in);
  while(c!= EOF)
    {
      putc(c,out);
      c=getc(in);
    }
  printf("Success!!\n");
  return 0;
}
