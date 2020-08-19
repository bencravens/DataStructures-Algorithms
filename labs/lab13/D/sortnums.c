#include <stdio.h>
#include <stdlib.h>
#include "flexarray.h"

int main(void) {
    /*initialize flexarray*/
    int num;
    flexarray flexy = flexarray_new();

    while(1==scanf("%d",&num)) {
        flexarray_append(flexy,num);
    }

    flexarray_sort(flexy);
    flexarray_print(flexy);
    
    flexarray_free(flexy);
    
    return EXIT_SUCCESS;
}
