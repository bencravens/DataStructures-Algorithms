#include <stdio.h>
#include <stdlib.h>
#include "flexarray.h"

int main(void) {
    int num;
    /*testing flexarray ADT*/
    flexarray my_flexarray = flexarray_new();

    while (1 == scanf("%d", &num)) {
        flexarray_append(my_flexarray,num);
    }

    printf("printing flexarray...\n");
    flexarray_print(my_flexarray);

    printf("printing sorted array... \n");

    flexarray_sort(my_flexarray);
    flexarray_print(my_flexarray);

    printf("freeing array...\n");
    flexarray_free(my_flexarray);

    return EXIT_SUCCESS;
}
