#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct
{
  char status;
  void* point;
}status_t;

void msg(char*);
status_t openfile(FILE** file, char* path, char* mode, char* msg_er);
status_t check_parameter(int,int);
