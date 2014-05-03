#include <stdio.h>

#ifdef __x86_64__
asm (".data\n\
 .globl _XtInherit        \n\
 _XtInherit:              \n\
    jmp *_y(%rip)         \n\
_y: .quad __XtInherit     \n\
    .text                 \n");
#else
asm (".data\n\
 .globl __XtInherit        \n\
 __XtInherit:      jmp *_y \n\
 _y: .long ___XtInherit    \n\
 .text                     \n");
#endif

#define _XtInherit __XtInherit
void _XtInherit ()
{
  printf ("_XtInherit ()\n");
}
