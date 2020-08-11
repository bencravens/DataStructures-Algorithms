#ifndef FLEXARRAY_H_
#define FLEXARRAY_H_

typedef struct flexarrayrec *flexarray;

extern void         flexarray_append(flexarray f, int item);
extern void         flexarray_free(flexarray f);
extern flexarray    flexarray_new();
extern void         flexarray_print(flexarray f);
extern void         flexarray_sort(flexarray f);
extern void*        emalloc(size_t n);
extern void*        erealloc(void* my_array, size_t n);
extern void         swap(int* x, int* y);
extern void         selection_sort(int* a, int n);

#endif 
