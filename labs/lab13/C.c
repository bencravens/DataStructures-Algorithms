#include <stdio.h>
#include <stdlib.h>


void repeats(int* a, int len) {
    int* frequencies = malloc(len * sizeof frequencies[0]);
    int i;
        
    /*count frequencies*/
    for (i=0;i<len;i++) {
        frequencies[a[i]]++;
    }

    for (i=0;i<len;i++) {
        if (frequencies[i] > 1) {
            printf("%d occurs %d times\n",i,frequencies[i]);
        }
    }
        
    free(frequencies);

}


int main(void) {
    int array_size = 0;
    int *my_array;
    int i = 0;

    printf("Enter the size of the array:\n");
    scanf("%d", &array_size);
    my_array = malloc(array_size * sizeof my_array[0]);
    if (NULL == my_array) {
        fprintf(stderr, "memory allocation failed!\n");
        return EXIT_FAILURE;
    }

    for (i=0; i<array_size; i++) {
        my_array[i] = rand() % array_size;
    }
    printf("What's in the array:\n");
    for (i=0; i<array_size; i++) {
        printf("%d ", my_array[i]);
    }
    printf("\n");

    repeats(my_array, array_size);

    free(my_array);

    return EXIT_SUCCESS;
    
}
