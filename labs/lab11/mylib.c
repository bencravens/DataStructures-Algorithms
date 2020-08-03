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


