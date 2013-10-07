#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
  if(argc !=2)
    {
      printf("Error!!!\n");
      exit(1);
    }
  FILE *in;
  if( (in=fopen(argv[1],"r"))==NULL)
    {
      printf("Can not open file!!\n");
      exit(0);
    }
  char kitu[127]={0};
  char count;
  count=getc(in);
  while( count != EOF)
    {
      kitu[count]+=1;
      count=getc(in);
    }
  printf("Thong ke cac ki tu xuat hien:\n");
  for(count=0;;++count)
    {
      if(count == 127)
	{
	  break;
	}
      if(kitu[count] != 0)
	{
	  printf("Ki tu \'%c\' ma ASCII: %d xuat hien %d lan.\n",count,count,kitu[count]);
	}
    }
  getchar();
  return 0;
}
