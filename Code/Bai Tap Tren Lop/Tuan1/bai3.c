#include<stdio.h>
int mang1[5];
int mang2[5];
char temp;

char check(int*, int*);

int main()
{
  printf("Ban hay nhap mang thu nhat.\n");
  for(temp =0; temp <5; temp++)
    {
      printf("Ban hay nhap vao so thu %d", temp+1);
      scanf("%d", &mang1[temp]);
      while( getchar()!= '\n');
    }
  printf("Ban hay nhap mang thu hai.\n");
  for(temp=0; temp <5; temp++)
    {
      printf("Ban hay nhap vao phan tu thu %d:", temp +1);
      scanf("%d", &mang2[temp]);
      while( getchar()!= '\n');
    }
  printf("Ma tra ve cua ham check la: %d", check(mang1, mang2));
  getchar();
  return 0;
}





char check(int* mang1,int* mang2)
{
  for(temp=0; temp <5; temp++)
    {
      if(mang1[temp]!= mang2[temp])
	{
	  return 0;
	}
    }
  return 1;
}
