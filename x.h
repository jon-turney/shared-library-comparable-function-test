#if !defined(_X_H_)
#define _X_H_

typedef void (*func) (void);

extern long _XtInherit[];

typedef struct { func callback; } x;

extern x x1, x2;

#endif
