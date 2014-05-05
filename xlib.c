#include <stdio.h>

#define IN_DLL
#include "x.h"

#ifdef __x86_64__
asm (".section .trampoline, \"dwx\" \n\
 .globl _XtInherit        \n\
 _XtInherit:              \n\
    jmp *_y(%rip)         \n\
_y: .quad XX__XtInherit     \n\
    .text                 \n");
#else
asm (".data\n\
 .globl __XtInherit        \n\
 __XtInherit:      jmp *_y \n\
 _y: .long _XX__XtInherit    \n\
 .text                     \n");
#endif

void XX__XtInherit ()
{
  printf ("in xlib dll\n");
}
