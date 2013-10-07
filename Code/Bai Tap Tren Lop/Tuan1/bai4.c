#include<stdio.h>
#include<string.h>

char canthay;
char dich;
char xau[100];
void thaythe(char*);

int main()
{
  printf("Ban hay nhap vao mot xau:");
  gets(xau);
  printf("Ban muon thay the chu cai nao? ");
  scanf("%c", &canthay);
  while( getchar() != '\n');
  printf("Ban can thay the %c thanh ki tu nao? ", canthay);
  scanf("%c", &dich);
  while( getchar()!= '\n');
  thaythe(xau);
  printf("Xau sau khi da thay the la: %s.\n", xau);
  getchar();
  return 0;
}

void thaythe(char* xau)
{
  int temp;
  for(temp=0; temp < strlen(xau); temp++)
    {
      if( xau[temp] == canthay)
	{
	  xau[temp] = dich;
	}
    }
}
