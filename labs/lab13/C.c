#include <stdio.h>
#include <stdlib.h>

void repeats(int* my_array, int n) {
    int i=0;
    int* frequencies = malloc(n * sizeof frequencies[0]);

    /* initialize frequencies with zeros */
    for (i=0;i<n;i++) {
        frequencies[i] = 0;
    }

    /* now count the frequencies of each int in the range [0,(n-1)]
     */
    for (i=0;i<n;i++) {
        int cur = my_array[i];
        /*increment the corresponding frequency*/
        frequencies[cur]++;
    }

    /*now print out frequencies*/
    for (i=0;i<n;i++) {
        printf("%d occurs %d times\n",i,frequencies[i]);
    }

    free(frequencies);
}

int main(void) {
    int array_size = 0;
    int *my_array;
    int i = 0;

    printf("Enter the size of the array: ");
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
