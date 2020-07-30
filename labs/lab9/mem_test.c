#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"

static void array_print(int *a, int n) {
    int i;

    for(i=0; i<n; i++) {
        printf("%d\n", a[i]);
    }
}

void insertion_sort(int *a, int n){
    
    /*define variables for insertion sort...*/
    int i;
    int key;
    int j;

    /*use insertion sort to sort the array*/
    for (i=1;i<n;i++){
        key = a[i];
        j = i - 1;
        while ((j>=0)&&(a[j]>key)) {
            a[j+1] = a[j];
            j = j - 1;
        }
        a[j+1] = key;
    }
    
}

int main(void) {
    int capacity = 2;
    int itemcount = 0;
    int item;
    int *my_array = emalloc(capacity * sizeof my_array[0]);

    while (1==scanf("%d", &item) && (capacity < 10)) {
        if (itemcount == capacity) {
            capacity += capacity;
            my_array = erealloc(my_array, capacity * sizeof my_array[0]);
        }
        my_array[itemcount++] = item;
    }

    printf("-------unsorted array-----\n\n");
    array_print(my_array, itemcount);
    insertion_sort(my_array,itemcount);
    printf("-------sorted array-------\n\n");
    array_print(my_array, itemcount);
    free(my_array);

    return EXIT_SUCCESS;
}
