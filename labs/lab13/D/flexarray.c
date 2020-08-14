#include <stdio.h>
#include <stdlib.h>
#include "flexarray.h"

struct flexarrayrec {
    int capacity;
    int itemcount;
    int* items;
};

void insertion_sort(int* a, int len) {
    int i;
    int j;
    int key;

    for (i=1;i<len;i++) {
        key = a[i];
        j = i - 1;
        while (key < a[j] && j>=0 ) {
            /*shift all elements to the left of key up (as long as they are less than key)*/
            a[j+1] = a[j];
            j--; 
        }   
        /*now put key in place*/
        a[j+1] = key;
    }   
}

void* emalloc(size_t n) {
    void* result = malloc(n);
    if (result == NULL) {
        fprintf(stderr,"memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

void* erealloc(int* a, size_t n) {
    void* result = realloc(a,n);
    if (result==NULL) {
        fprintf(stderr,"memory reallocation failed.\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

flexarray flexarray_new() {
    flexarray result = emalloc(sizeof *result);
    result->capacity=2;
    result->itemcount=0;
    result->items = emalloc(result->capacity * sizeof result->items[0]);
    return result;
}

void flexarray_append(flexarray f, int num) {
    /*reached capacity, reallocate*/
    if (f->itemcount==f->capacity) {
        f->capacity=2*(f->capacity);
        f->items = erealloc(f->items, f->capacity * sizeof f->items[0]);
    }
    /*add new item*/
    f->items[f->itemcount] = num;
    f->itemcount++; 
}

void flexarray_sort(flexarray f) {
    insertion_sort(f->items, f->itemcount);
}

void flexarray_print(flexarray f) {
    int i;
    for(i=0;i<f->itemcount;i++) {
        printf("%d\n",f->items[i]);
    }
}

void flexarray_free(flexarray f) {
    free(f->items);
    free(f);
}
