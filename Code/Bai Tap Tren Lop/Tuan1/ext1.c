#include<stdio.h>

int main(int argc, char* argv[])
{
  double chieudai, chieurong;
  if(argc != 3)
    {
      printf("Cac tham so cua chuong trinh bi nhap sai.\n");
      return 1;
    }
  printf("Canh thu nhat cua hinh chu nhat la: %s",argv[1]);
  chieudai=atof(argv[1]);
  printf("Chieu dai cua hinh chu nhat la: %g.\n", chieudai);
  chieurong=atof(argv[2]);
  printf("Chieu rong cua hinh chu nhat la; %g.\n", chieurong);
  printf("Chu vi cua hinh chu nhat la: %g.\n", 2*(chieudai+chieurong));
  printf("Dien tich cua hinh chu nhat la: %g.\n", chieudai*chieurong);
  getchar();
  return 0;
}
