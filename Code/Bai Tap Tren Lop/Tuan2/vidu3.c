#include<stdio.h>

int main()
{
  FILE *in, *out;
  if( (in=fopen("in.txt", "r")) == NULL || (out=fopen("out.txt","w")) == NULL  )
    {
      printf("Co loi trong qua trinh mo file.\n");
      return 0;
    }
  char c;
  while( (c=getc(in)) != EOF)
    {
      if( c >= 65&& c<= 90)
	{
	  c+=32;
	}
      putc(c,out);
    }
  printf("Success!\n");
  return 0;
}
