#ifndef MYLIB_H_
#define MYLIB_H_

#include <stddef.h>

extern void *emalloc(size_t);
extern void *erealloc(void *, size_t);
extern void insertion_sort(int *, int);
extern void merge_sort(int*, int*, int);
extern void merge(int*, int*, int);

#endif
