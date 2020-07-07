#include <stdio.h>
#include <stdlib.h>

#define ARRAY_MAX 10

void insertion_sort(int *a, int n){
    
    /*define variables for insertion sort...*/
    int i;
    int key;
    int j;

    printf("printing a \n");

    /*display array*/
    for (i=0;i<n;i++){
        printf(" %d ", a[i]);
    }

    printf("\n");

    /*use insertion sort to sort the array*/
    for (i=1;i<n;i++){
        key = a[i];
        j = i - 1;
        while (j>=0 & a[j]>key) {
            a[j+1] = a[j];
            j = j - 1;
        }
        a[j+1] = key;
    }

    printf("printing sorted a \n");

    /*display sorted array*/
    for (i=0;i<n;i++){
        printf(" %d ", a[i]);
    }

    printf("\n");
}

int main(void) {
    int my_array[ARRAY_MAX];
    int i, count = 0;

    while (count < ARRAY_MAX && 1 == scanf("%d", &my_array[count])) {
        count++;
    }

    insertion_sort(my_array, count);

    return EXIT_SUCCESS;
}
