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

void insertion_sort(int* a, int n) {
    int i;
    int j;
    int key; /*element to be "inserted" in sorted list*/

    for(i=1;i<n;i++) {
        /*the first element is automatically "sorted"*/
        key = a[i];
        j = i - 1;
        /* iterate through the sorted list, and move each entry along one index
         * until we find an entry smaller than the key, at which point we 
         * insert the key into the sorted list. */
        while (j>=0 && a[j] > key) {
            a[j+1] = a[j]; 
            j = j - 1;
        }
        a[j+1] = key;
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
    insertion_sort(f->items, f->itemcount);
}

void flexarray_free(flexarray f) {
    free(f->items);
    free(f);
}
