#include<stdio.h>
#include<stdlib.h>

long khaosat(char*);
void load_data(char*, long, contact*);
void display_data(contact*,long);

int main(int argc, char* argv)
{
  FILE *in;
  if( (in=fopen(argv[1],"rb")) == NULL)
    {
      printf("Khong the mo duoc file!\n");
      exit(1);
    }
  long size;
  size=khaosat(argv[1]);
  load_data(argv[1],size,block);
  display_data(blocks,size);
  getchar();
  return 0;
}

long khaosat(char* in)
{
  FILE *inp;
  if((inp=fopen(in,"rb"))== NULL)
    {
      printf("Khong the tien hanh khao sat file!\n");
      exit(1);
    }
  long size_of_file;

}
