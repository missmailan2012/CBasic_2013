#include<stdio.h>
char mang[127], c;
int chiso;

int main()
{
  FILE *in, *out;
  if( (in=fopen("vidu4.c", "r"))== NULL || (out=fopen("thongke.txt", "w")) == NULL)
    {
      printf("Co loi xay ra khi mo file.\n");
      return 0;
    }
  while( (c=getc(in)) != EOF)
    {
      mang[c]++;
    }
  for(chiso =0; chiso<127; chiso++)
    {
      if( mang[chiso] != 0)
	{
	  fprintf(out,"Ki tu: %c xuat hien %d lan.\n",chiso,mang[chiso]);
	}
    }
  printf("Success!\n");
  return 0;
}
