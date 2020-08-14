#ifndef FLEXARRAY_H_
#define FLEXARRAY_H_

typedef struct flexarrayrec *flexarray;

extern flexarray        flexarray_new();
extern void             flexarray_append(flexarray f, int item);
extern void             flexarray_print(flexarray f);
extern void             flexarray_sort(flexarray f);
extern void             flexarray_free(flexarray f);

#endif
