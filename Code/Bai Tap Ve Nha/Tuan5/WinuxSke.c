#include "WinuxSke.h"

///////////////////
void msg(char *str)
{
  printf("%s\n",str);
}
/////////////////////
////////////////////////////////////////////////////////////////////
status_t openfile(FILE** file, char* path, char* mode, char* msg_er)
{
  status_t stt;
  *file=fopen(path,mode);
  if(*file == NULL)
    {
      msg(msg_er);
      exit(1);
    }
}
////
status_t check_parameter(int argc,int parameter)
{
  if(argc > parameter)
    {
      msg("Thua tham so!!!!!");
      exit(1);
    }
  if(argc < parameter)
    {
      msg("Thieu tham so!!!!");
      exit(1);
    }
}
