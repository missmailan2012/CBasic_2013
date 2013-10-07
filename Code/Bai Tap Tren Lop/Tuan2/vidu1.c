#include<stdio.h>

enum{SUCCESS, FAIL};

main(void)
{
  FILE *fptr;
  char filename[]="haiku.txt";
  int reval = SUCCESS;

  if( (fptr = fopen(filename, "r")) == NULL)
    {
      printf("Cannot open %s.\n", filename);
      reval = FAIL;
    }
  else
    {
      printf("Value of fptr: 0x%p\n", fptr);
      printf("Ready for close the file.\n");
      fclose(fptr);
    }
  return reval;
}
