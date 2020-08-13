#include <stdio.h>
#include <stdlib.h>

void repeats(int* a, int n) {
    int* freq;
    int i;
    int index;
    
    freq = malloc(n * sizeof freq[0]);
    if (NULL == freq) {
        fprintf(stderr, "memory allocation failed!\n");
    }

    for (i=0;i<n;i++) {
        /*initialize frequencies to zero*/
        freq[i] = 0;
    }

    for (i=0;i<n;i++) {
        /*increment the index corresponding to our num*/
        index = a[i];
        freq[index]++;
    }

    for (i=0;i<n;i++) {
        /*print repeats*/
        if (freq[i] > 1) {
            printf("%d occurs %d times\n",i,freq[i]);
        }
    }
    free(freq);
    return ;
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
