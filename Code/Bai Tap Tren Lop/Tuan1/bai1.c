#include<stdio.h>
#include<math.h>

float trituyetdoi(float);

int main()
{
  char sophantu;
  char chisocantim;
  float saiso, saisonhonhat, trungbinh;
  int mang[10];
  char temp;
  int tong; tong =0;
  for(temp=0; temp < 10; temp++)
    {
      printf("Ban hay nhap vao phan tu thu %d cua mang:", temp+1);
      scanf("%d", &mang[temp]);
      while( getchar()!= '\n');
    }
  for( temp=0; temp <10; temp++)
    {
      tong+=mang[temp];
    }
  printf("Tong cac so la: %d.\n", tong);
  trungbinh=tong/10.0;
  printf("Trung binh cac so la: %f.\n", trungbinh);
  chisocantim=0; saisonhonhat=trituyetdoi(trungbinh-mang[0]);
  for(temp=1;temp<10;temp++)
    {
      if(trituyetdoi(trungbinh-mang[temp]) < saisonhonhat)
	{
	  saisonhonhat=trituyetdoi(trungbinh-mang[temp]);
	  chisocantim=temp;
	}
    }
  printf("So can tim co chi so la: %d.\nSo do la: %d.\n",chisocantim, mang[chisocantim]);
  getchar();
  return 0;
}

float trituyetdoi(float cantim)
{
  if(cantim <0)
    {
      return -cantim;
    }
  if( cantim >0)
    {
      return cantim;
    }
}
