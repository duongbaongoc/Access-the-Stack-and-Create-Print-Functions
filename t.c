#include <stdio.h>
#include <stdlib.h>

typedef unsigned int u32;
int *FP;

int A(int x, int y);
int B(int x, int y);
int C(int x, int y);

int main (int argc, char *argv[], char *env[])
{
  int a,b,c;
  myprintf("%s", "enter main\n");

  myprintf("&argc=%x argv=%x env=%x\n", (u32)&argc, (u32)argv, (u32)env);
  myprintf("&a=%x &b=%x &c=%x\n", (u32)&a, (u32)&b, (u32)&c);

  //(1) Ngoc's work: display argc value, argv and env strings
  myprintf("argc=%d\n", argc);
  for (int i = 0; i < argc; i++)
    myprintf("argv[%d] = %s\n", i, argv[i]);
  for (int i = 0; env[i]; i++)
    myprintf("env[%d] = %s\n", i, env[i]);  
  
  a=1; b=2; c=3;
  A(a,b);
  myprintf("char=%c string=%s   dec=%d hex=%x oct=%o neg=%d\n", 'A', "this is a test", 100, 100, 100, -100);
  printf("\nexit main\n");
}

int A(int x, int y)
{
  int d,e,f;
  myprintf("%s", "enter A\n");

  //PRINT ADDRESS OF d, e, f: Ngoc's work
  myprintf("&d=%x &e=%x &f=%x\n", (u32)&d, (u32)&e, (u32)&f);
  
  d=4; e=5; f=6;
  B(d,e);
  myprintf("%s", "exit A\n");
}

int B(int x, int y)
{
  int g,h,i;
  myprintf("%s", "enter B\n");

  //PRINT ADDRESS OF g,h,i: Ngoc's work
  myprintf("&g=%x &h=%x &i=%x\n", (u32)&g, (u32)&h, (u32)&i);
  
  g=7; h=8; i=9;
  C(g,h);
  myprintf("%s", "exit B\n");
}

int C(int x, int y)
{
  int u, v, w, i, *p;

  myprintf("%s", "enter C\n");
  
  //PRINT ADDRESS OF u, v, w, i, p: Ngoc's work
  myprintf("&u=%x &v=%x &w=%x &i=%x &p=%x\n", (u32)&u, (u32)&v, (u32)&w, (u32)&i, (u32)&p);
  
  u=10; v=11; w=12; i=13;

  FP = (int *)getebp();

  //(2) Write C code to print the stack frame link list: Ngoc's work
  myprintf("\n\nStack Frame List\n\n");
  while (*FP != 0)
    {
      myprintf("Frame Pointer = %x    Frame of its caller = %x\n", (u32)FP, (u32)*FP);
      FP = *FP;
    }
  myprintf("Frame Pointer = %x    Frame of its caller = %x\n\n", (u32)FP, (u32)*FP);

  p = (int *)&p;

  //(3). Print the stack contents from p to the frame of main()
  //YOU MAY JUST PRINT 128 entries of the stack contents.
  myprintf("128 entries  of the stack:\n");
  myprintf("LOW ADDRESS\n");
  for (int i = 0; i < 128; i++)
    {
      myprintf ("%x\t%x\n", (u32)p, (int)*p);
      p++;
    }
  myprintf("HIGH ADDRESS\n\n\n");
  

  //(4). On a hard copy of the print out, identify the stack content
  //as LOCAL VARIABLES, PARAMETERS, stack frame pointer of each function
  myprintf("%s", "exit C\n");
}
