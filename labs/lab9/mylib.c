#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"

void* emalloc(size_t n) {
    void* result = malloc(n);
    if (result == NULL) {
        fprintf(stderr, "memory allocation failed!");
        exit(EXIT_FAILURE);
    }
    return result;
}

void* erealloc(void* my_array, size_t n) {
    void* result = realloc(my_array, n);
    if (result == NULL) {
       fprintf(stderr, "memory re-allocation failed!\n");
       exit(EXIT_FAILURE);
    }
    return result; 
}

void insertion_sort(int *a, int n){
    
    /*define variables for insertion sort...*/
    int i;
    int key;
    int j;

    /*use insertion sort to sort the array*/
    for (i=1;i<n;i++){
        key = a[i];
        j = i - 1;
        while ((j>=0)&&(a[j]>key)) {
            a[j+1] = a[j];
            j = j - 1;
        }
        a[j+1] = key;
    }
    
}
