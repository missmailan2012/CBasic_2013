#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum{run, stop};
typedef char status;

void conver_number_to_char();
void conver_char_to_number();
void compare_two_string();
void lenght_of_string();
void display_array_string();

int main()
{
  char cChoice;
  status TStatus;
  TStatus = run;
  while(TStatus == run)
    {
      system("clear");
      printf("Menu:\n");
      printf("1) Conver number to character.\n");
      printf("2) Input a character, conver to number.\n");
      printf("3) Compare two string.\n");
      printf("4) Input a string, display lenght of string.\n");
      printf("5) Input a string, display array string in number.\n");
      printf("6) Quit, stop process.\n");
      scanf("%c", &cChoice);
      while( getchar() != '\n');
      switch(cChoice)
	{
	case '1':
	  {
	    conver_number_to_char();
	    break;
	  }
	case '2':
	  {
	    conver_char_to_number();
	    break;
	  }
	case '3':
	  {
	    compare_two_string();
	    break;
	  }
	case '4':
	  {
	    lenght_of_string();
	    break;
	  }
	case '5':
	  {
	    display_array_string();
	    break;
	  }
	case '6':
	  {
	    system("clear");
	    printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
	    printf("____________________________________\n");
	    printf("WinuxSke!\n");
	    printf("____________________________________\n");
	    printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
	    printf("\n\n\n");
	    TStatus = stop;
	    break;
	  }
	}
    }
  return 0;
}


void conver_number_to_char()
{
  int nNumber;
  printf("Input a number: ");
  scanf("%d", &nNumber);
  while( getchar() != '\n' );
  printf("Number %d is %c character!\n", nNumber, nNumber);
  getchar();
  return;
}

void conver_char_to_number()
{
  char Character;
  printf("Input a character: ");
  scanf("%c", &Character);
  while( getchar() != '\n' );
  printf("Character %c is %d number!\n", Character, Character);
  getchar();
  return;
}

void compare_two_string()
{
  char s1[1000];
  char s2[1000];
  printf("Input string 1: ");
  gets(s1);
  printf("Input string 2: ");
  gets(s2);
  printf("Compare \"%s\" and \"%s\" is %d!\n", s1, s2, strcmp(s1, s2));
  getchar();
  return;
}

void lenght_of_string()
{
  char s[1000];
  printf("Input a string: ");
  gets(s);
  printf("Lenght of \"%s\" is %d!\n", s, strlen(s));
  getchar();
  return;
}

void display_array_string()
{
  char s[1000];
  printf("Input s string: ");
  gets(s);
  int leng_of_string;
  leng_of_string = 0;
  for( ;leng_of_string <= strlen(s) ; leng_of_string++ )
    {
      printf("Adress: %0x -> %d -> %c\n", &s[leng_of_string], s[leng_of_string], s[leng_of_string]);
    }
  getchar();
  return;
}
