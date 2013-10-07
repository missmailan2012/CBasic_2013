#include<stdio.h>

int main()
{
  FILE *in, *out;
  if( ( (in=fopen("labr.txt","r")) == NULL) || ( (out=fopen("labw.txt", "w")) == NULL) )
    {
      printf("Co loi khi mo file.\n");
      return 1;
    }
  char c;
  while( (c=getc(in)) != EOF)
    {
      putc(c,out);
    }
  fcloseall();
  getchar();
  return 0;
}
