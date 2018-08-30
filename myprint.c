#include <stdio.h>
#include <stdarg.h>

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
  va_list vl;
  va_start(vl, fmt);
  while (*fmt)
    {
      if (*fmt=='%') {
	fmt++;
	switch(*fmt) {
	case 'c':
	  putchar(va_arg(vl,int));
	  break;
	case 's':
	  prints(va_arg(vl,char *));
	  break;
	case 'u':
	  printu(va_arg(vl,u32));
	  break;
        case 'd':
	  printd(va_arg(vl,int));
	  break;
	case 'o':
	  printo(va_arg(vl,u32));
	  break;
	case 'x':
	  printx(va_arg(vl,u32));
	  break;
	}
      }
      else
	putchar(*fmt);
      fmt++;
    }
    va_end(vl);
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