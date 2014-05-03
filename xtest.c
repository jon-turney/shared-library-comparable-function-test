#include "x.h"
#include <stdio.h>

int
main (int argc, char **argv)
{
  printf ("x1.callback: %p\n", x1.callback);
  printf ("_XtInherit : %p\n", _XtInherit);
  x1.callback();

  xaw(x2);

  return 0;
}
