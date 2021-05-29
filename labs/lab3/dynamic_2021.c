#include <stdio.h>
#include <stdlib.h>

void display_repeats(int* a, int* collisions, int n){
    int i;
    for (i=0;i<n;i++){
        collisions[a[i]]++;
    }
}

int main(void) {
    int array_size = 0;
    int* my_dynamic_array;
    int* collisions;
    int i = 0;
    
    printf("enter the size of the array: ");
    scanf("%d", &array_size);
    
    /*allocate memory*/
    my_dynamic_array = malloc(array_size * sizeof my_dynamic_array[0]);
    collisions = malloc(array_size * sizeof collisions[0]);
    if (NULL == my_dynamic_array | NULL == collisions) {
        fprintf(stderr, "memory allocation failed!\n");
        return EXIT_FAILURE;
    }
    
    for (i=0; i<array_size; i++) {
        my_dynamic_array[i] = rand() % array_size;
    }
    
    printf("contents of array:\n");
    
    for(i=0; i<array_size; i++) {
        printf("%d ", my_dynamic_array[i]);
    }
    printf("\n");
    
    display_repeats(my_dynamic_array,collisions,array_size);
    
    
    printf("frequency:\n");
    
    for(i=0;i<array_size;i++) {
        printf("%d appears %d times.\n",i,collisions[i]);
    }
    /*free memory*/
    free(my_dynamic_array);
    free(collisions);
    
    return EXIT_SUCCESS;
}
