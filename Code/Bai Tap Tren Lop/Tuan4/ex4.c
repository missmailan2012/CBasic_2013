#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char* argv[])
{
  char t;
  if( argc !=3)
    {
      printf("Error agrument\n");
      exit(1);
    }
  FILE *in, *out;
  if( (in=fopen(argv[1],"rb")) == NULL || (out=fopen(argv[2],"wb")) == NULL)
    {
      printf("Error cannot open file\n");
      exit(1);
    }
  while(!feof(in))
    {
      fread(&t,sizeof(char),1,in);
      printf("%d",t);
      fwrite(&t,sizeof(char),1,out);
    }
  printf("Success\n");
  fcloseall();
  return 0;
}
