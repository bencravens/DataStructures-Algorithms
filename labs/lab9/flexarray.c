#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "flexarray.h"

struct flexarrayrec {
    int capacity;
    int itemcount;
    int *items;
};

flexarray flexarray_new() {
    flexarray result = emalloc(sizeof *result);
    result->capacity = 2;
    result->itemcount = 0;
    result->items = emalloc(result->capacity * sizeof result->items[0]);
    return result;
}

void flexarray_append(flexarray f, int num) {
    if (f->itemcount == f->capacity) {
        f->capacity = f->capacity + f->capacity;
        f->items = erealloc(f->items, f->capacity * sizeof f->items[0]);
    }
    f->items[f->itemcount] = num;
    f->itemcount = f->itemcount + 1;
}

void flexarray_print(flexarray f) {
    int i;
    printf("PRINTING\n");
    printf("number of items in flexarray: %d\n",f->itemcount);
    for(i=0;i<f->itemcount;i++){
        printf("%d\n",f->items[i]);
    }
}

void flexarray_sort(flexarray f) {
    int* workspace = emalloc(f->itemcount * sizeof f->items[0]);
    merge_sort(f->items,workspace,f->itemcount);
}

void flexarray_free(flexarray f) {
    free(f);
}
