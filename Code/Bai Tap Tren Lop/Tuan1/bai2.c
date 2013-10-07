#include<stdio.h>
typedef struct
{
  char maasci;
  char count;
}kitu;
kitu mang[54];
int temp;
int count;
int thanhdan;thanhdan=0;
int main()
{
  char string[200];
  printf("Ban hay nhap vao mot chuoi: ");
  gets(string);
  count=0;
  for(temp =0; temp < strlen(string); temp++)
    {
      count =-1;
      while(1)
	{
	  count++;
	  if(count >= thanhdan || string[temp] == mang[count].maasci)
	    {
	      break;
	    }
	}
      if(count < thanhdan)
	{
	  mang[count].count++;
	}
      if(count == thanhdan && string[temp]== mang[count].maasci)
	{
	  mang[count].count+=1;
	}
      if(count == thanhdan && string[temp] != mang[count].maasci)
	{
	  thanhdan++;
	  mang[thanhdan].count+=1;
	  mang[thanhdan].maasci=string[temp];
	}
    }
  printf("Buoc 1.\n");
  for(temp=1; temp <=thanhdan; temp++)
    {
      printf("Ki tu: %c xuat hien %d lan.\n", mang[temp].maasci, mang[temp].count);
    }
  getchar();
  return 0;
}
