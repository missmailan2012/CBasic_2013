#include<stdio.h>

void display(char* string, void print(char* str))
{
  print(string);
  return;
}

void myPrintf(char* str)
{
  printf("++++: %s\n", str);
  return;
}

int main()
{
  display("Hello world!", myPrintf);
  return 0;
}
