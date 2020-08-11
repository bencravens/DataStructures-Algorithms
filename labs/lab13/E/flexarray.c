#include <stdio.h>
#include <stdlib.h>
#include "flexarray.h"

struct flexarrayrec {
    int capacity;
    int itemcount;
    int* items;
};

void* emalloc(size_t n) {
    void* result = malloc(n);
    if (result==NULL) {
        fprintf(stderr,"memory allocation failed.");
        exit(EXIT_FAILURE);
    }
    return result;
}

void* erealloc(void* my_array, size_t n) {
    void* result = realloc(my_array, n);
    if (result==NULL) {
        fprintf(stderr,"memory reallocation failed.");
        exit(EXIT_FAILURE);
    }
    return result;
}

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selection_sort(int* a, int n) {
    int i;
    int boundary_index=0;;
    while (boundary_index < n) {
        int min_index = boundary_index;
        for(i=boundary_index;i<n;i++) {
            if (a[i] < a[min_index]) {
                swap(&a[i],&a[min_index]);
            }
        }
        boundary_index++;        
    }
}

flexarray flexarray_new() {
    flexarray result = emalloc(sizeof *result);
    result->capacity = 2;
    result->itemcount = 0;
    result->items = emalloc(result->capacity * sizeof result->items[0]);
    return result;
}

void flexarray_append(flexarray f, int num) {
    if (f->capacity == f->itemcount) {
        /*array is full... must reallocate*/
        f->capacity = 2*(f->capacity);
        f->items = erealloc(f->items, f->capacity * sizeof f->items[0]);
    }
    f->items[f->itemcount] = num;
    f->itemcount++; 
}

void flexarray_print(flexarray f) {
    int i;
    for(i=0;i<f->itemcount;i++) {
        printf("%d\n",f->items[i]);
    }
}

void flexarray_sort(flexarray f) {
    selection_sort(f->items, f->itemcount);
}

void flexarray_free(flexarray f) {
    free(f->items);
    free(f);
}
