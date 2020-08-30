#include <stdio.h>
#include <stdlib.h>
#include "flexarray.h"

int main(void) {
    /*initialize flexarray*/
    int num;
    flexarray flexy = flexarray_new();
    while (1==scanf("%d",&num)) {
        flexarray_append(flexy,num);
    }
    printf("printing!\n");
    flexarray_print(flexy);
    printf("printing sorted!\n");
    flexarray_sort(flexy);
    flexarray_print(flexy); 
    return EXIT_SUCCESS;
}
