#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
  if( argc!= 3)
    {
      printf("Error.\n");
	exit(1);
    }
  FILE *in, *out;
  if( (in=fopen(argv[1],"r"))== NULL || (out=fopen(argv[2],"w")) == NULL)
    {
      printf("Can not open file!!\n");
      exit(1);
    }
  char kitu[127]={0};
  char count;
  count=getc(in);
  while(count != EOF)
    {
      kitu[count]+=1;
      count=getc(in);
    }
  for(count=0;;count++)
    {
      if(count == 127)
	{
	  break;
	}
      if(kitu[count]!=0)
	{
	  fprintf(out,"Ki tu \'%c\' co ma %d xuat hien %d lan.\n",count,count,kitu[count]);
	  printf("Ki tu \'%c\' co ma %d xuat hien %d lan.\n", count, count, kitu[count]);
	}
    }
  printf("Success!!!\n");
  getchar();
  return 0;
}
