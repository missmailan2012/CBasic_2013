#include<stdio.h>
typedef struct point
{
  double x;
  double y;
}point_t;

typedef struct circle
{
  point_t center;
  double radius;
}circle_t;

int main()
{
  circle_t o;
  point_t a;
  printf("Ban hay nhap vao toa do tam cua duong tron: ");
  scanf("%lf %lf",&o.center.x, &o.center.y);
  while( getchar() != '\n');
  printf("Ban hay nhap vao ban kinh cua duong tron: ");
  scanf("%lf", &o.radius);
  while( getchar() != '\n');
  printf("Ban hay nhap vao toa do cua diem can kiem tra: ");
  scanf("%lf %lf", &a.x, &a.y);
  if( o.radius*o.radius < ( (o.center.x - a.x)*(o.center.x - a.x) + (o.center.y - a.y)*(o.center.y - a.y) ))
    {
      printf("Diem nam ngoai duong tron\n");
    }
  else
    {
      printf("Diem nam trong hinh tron\n");
    }
  return 0;
}
