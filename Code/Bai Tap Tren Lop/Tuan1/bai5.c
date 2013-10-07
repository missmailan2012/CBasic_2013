#include<stdio.h>
float sothuc;
float phanthuc;
int phannguyen;
void phantach(float, float*, int*);

int main()
{
  printf("Ban hay nhap vao mot so thuc: ");
  scanf("%f", &sothuc);
  phantach(sothuc, &phanthuc, &phannguyen);
  printf("So thuc %f:\nCo phan nguyen la: %d.\nPhan thuc la: %g.\n", sothuc, phannguyen, phanthuc);
  getchar();
  return 0;
}

void phantach(float sothuc, float* phanthuc, int* phannguyen)
{
  *phannguyen=(int)sothuc;
  *phanthuc=sothuc-*phannguyen;
}
