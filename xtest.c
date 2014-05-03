#include "x.h"
#include <stdio.h>

int
main (int argc, char **argv)
{
  printf ("x1.callback: %p\n", x1.callback);
  printf ("x2.callback: %p\n", x2.callback);
  printf ("_XtInherit : %p\n", _XtInherit);
  x1.callback();
  x2.callback();

  return 0;
}
