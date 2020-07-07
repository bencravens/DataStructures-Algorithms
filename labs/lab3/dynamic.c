#include <stdio.h>
#include <stdlib.h>

void display_repeats(int *a, int n){
    int repeats[n];
    int i;
    int value;    

    /*fill repeats array with zeros*/
    for (i=0; i<n; i++){
        repeats[i] = 0;
    }

    /*determine which integers appear repeatedly*/
    for (i=0; i<n; i++){
        value = a[i];
        repeats[value] = repeats[value] + 1;
    }

    for (i=0; i<n; i++){
        if (repeats[i]>1){
            printf("%d appears %d times, is repeated.\n",i,repeats[i]);
        }
    }
}

int main(void) {
    int array_size = 0;
    int *my_dynamic_array;
    int i = 0;
    int array_memory;

    printf("Enter the size of the array: ");
    scanf("%d", &array_size);

    printf("array_size is %d\n",array_size);

    printf("size of one entry in dynamic array is %lu\n", sizeof my_dynamic_array[0]);

    /*allocate the proper amount of memory to the array...*/
    array_memory = array_size * sizeof(my_dynamic_array[0]);
     

    printf("amount of memory allocated is %d\n", array_memory);

    my_dynamic_array = malloc(array_memory);
   
    /*check that this worked...*/
    if (NULL == my_dynamic_array) {
        fprintf(stderr, "memory allocation failed!\n");
        return EXIT_FAILURE;
    } 

    /*randomly fill array*/
    for (i=0; i<array_size; i++){
        my_dynamic_array[i] = rand() % array_size;
    }

    /*display array*/
    printf("displaying array: ");

    /*display the array*/
    for (i=0; i<array_size; i++){
        printf("%d ", my_dynamic_array[i]);
    }
    printf("\n");

    /*call display_repeats function*/
    display_repeats(my_dynamic_array,array_size);

    /* release memory allocated to array */
    free(my_dynamic_array); 

    return EXIT_SUCCESS;
}
