#include <stdio.h>
#include "x.h"

void
xaw (x x2)
{
  printf ("_XtInherit : %p\n", _XtInherit);
  printf ("x2.callback: %p\n", x2.callback);

  if (x2.callback == _XtInherit)
    {
      printf ("match\n");
    }
  else
    {
      printf ("mismatch\n");
    }

  _XtInherit();
}
