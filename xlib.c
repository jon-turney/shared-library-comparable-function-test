#include <stdio.h>

asm (".data\n\
 .globl __XtInherit        \n\
 __XtInherit:      jmp *_y \n\
 _y: .long ___XtInherit    \n\
 .text                     \n");

#define _XtInherit __XtInherit
void _XtInherit ()
{
  printf ("_XtInherit ()\n");
}
