#if !defined(_X_H_)
#define _X_H_

typedef void (*func) (void);

#ifdef IN_DLL
#define DLLATTRIB  __attribute__ ((dllexport))
#else
#define DLLATTRIB  __attribute__ ((dllimport))
#endif

extern void _XtInherit(void) DLLATTRIB;

typedef struct { func callback; } x;

void xaw (x x2);

#endif
