#include <stdio.h>

typedef unsigned int u32;
char *ctable = "0123456789ABCDEF";
int BASE = 10;

int myprintf(char *fmt, ...);
int prints(char *s);
int rpu(u32 x);
int printo(u32 x);
int printx(u32 x);
int help2(u32 x);
int help1(u32 x, u32 base);
int printu(u32 x);
int printd(int x);

//Ngoc's work: myprintf to print different formats
int myprintf(char *fmt, ...) {
  int *ip = (int *)(&fmt+1);
 
    while(*fmt !=0)
      {
	if(*fmt == '%')
	  {
	    fmt++;
	    switch(*fmt)
	      {
	      case 'c':
		putchar(*ip);
		break;
	      case 's':
		prints((char*)*ip);
		break;
	      case 'd':
		printd(*ip);
		break;
	      case 'x': printx(*ip);
		break;
	      case 'u': printu(*ip);
		break;
	      case 'o':
		printo(*ip);
		break;
	      default:
		prints("Invalid format identifier\n");
		break;
	      }
	    ip++;
	  }
	else
	  {
	    putchar(*fmt);
	    if (*fmt == '\n')
	       putchar('\r');
	  }
	fmt++;
      }
}  
  
//Ngoc's work: my function to print a string
int prints(char *s)
{
  while (*s)
    {
      putchar(*s);
      s++;
    }
}

//given functions
int rpu(u32 x)
{
  char c;
  if (x){
    c = ctable[x%BASE];
    rpu(x/BASE);
    putchar(c);
  }
}

int printu(u32 x)
{
  (x==0)? putchar('0') : rpu(x);
  putchar(' ');
}

//Ngoc's work: my function to print an int
int printd(int x)
{
  if (x < 0)
    {
      putchar('-');
      x = -x;
    }
    printu(x);
}

//Ngoc's work: my function to print x in HEX and in Octal
int help1(u32 x, u32 base)
{
  BASE = base;
  (x==0)? putchar('0') : help2(x);
}

int help2(u32 x)
{
  char c;
  if(x){
    c = ctable[x%BASE];
    help2(x/BASE);
    putchar(c);
  }
}

int printx(u32 x) {
  putchar('0');
  putchar('x');
  help1(x, 16);
}

int printo(u32 x) {
  putchar('0');
  help1(x, 8);
}
