#if !defined(_X_H_)
#define _X_H_

typedef void (*func) (void);

extern void _XtInherit(void);

typedef struct { func callback; } x;

extern x x1, x2;

void xaw (x x2);

#endif
