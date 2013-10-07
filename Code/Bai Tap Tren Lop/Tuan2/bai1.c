#include<stdio.h>
#include<stdlib.h>

double giaithua(int);
double mu(int, int);
double Pow(int);
double kq;
int sm;

int main(int argv, char* argc[])
{
  if(argv != 2)
    {
      printf("Ban da nhap sai doi so dong lenh.\n");
      return 1;
    }
  sm=atoi(argc[1]);
  printf("Ban da nhap vao so mu: %d", sm);
  while( getchar() != '\n');
  printf("Gia tri can tinh la: %f.\n",Pow(sm));
  getchar();
  return 0;
}

double giaithua(int gt)
{
  double kq; kq =1;
  int temp;
  for(temp =1; temp<=gt; temp++)
    {
      kq*=temp;
    }
  return kq;
}

double mu(int coso, int somu)
{
  double kq;
  kq=1;
  int temp;
  for(temp=1; temp <= somu; temp++)
    {
      kq*=coso;
    }
  return kq;
}

double Pow(int spow)
{
  double kq;
  kq =1;
  double n;
  n=1;
  while(mu(spow,n)/giaithua(n) > 1.0/10000000)
    {
      kq+=mu(spow,n)/giaithua(n);
      n++;
    }
  return kq;
}
