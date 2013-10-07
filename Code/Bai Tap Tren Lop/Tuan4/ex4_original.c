#include<stdio.h>
#include<stdlib.h>
#define MAX_LEN 10

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
  int num;
  char buff[MAX_LEN +1];
  while( !feof(in))
    {
      num =fread(buff,sizeof(char), MAX_LEN,in);
      fwrite(buff,sizeof(char),num,out);
    }
  printf("Success\n");
  fcloseall();
  return 0;
}
