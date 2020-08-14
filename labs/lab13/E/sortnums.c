#include <stdio.h>
#include <stdlib.h>
#include "flexarray.h"

int main(void) {
    /*initialize flexarray*/
    flexarray flexy = flexarray_new();
    int i;

    while(1==scanf("%d",&i)) {
        flexarray_append(flexy,i);
    }
    flexarray_sort(flexy);
    flexarray_print(flexy);
    flexarray_free(flexy);
    return EXIT_SUCCESS;
}
