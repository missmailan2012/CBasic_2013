#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* des;
char* my_strcat(char*, char*);

int main( int argc, char* argv[])
{
  if( argc != 3)
    {
      printf("Error agrument.\n");
      exit(1);
    }
  des=my_strcat(argv[1],argv[2]);
  printf("Dia chi con tro la: 0x%p\nXau la: %s\n",des,des);
  free(des);
  return 0;
}

char* my_strcat(char* f, char* s)
{
  char len_f, len_s;
  len_f=strlen(f);
  len_s=strlen(s);
  int tong;
  tong=len_f + len_s +1;
  char* result;
  result=(char*)malloc(tong*sizeof(char));
  if( result == NULL)
    {
      printf("Error Allocation failed! Check memory\n");
      exit(1);
    }
  strcpy(result,f);
  strcat(result,s);
  return result;
}
