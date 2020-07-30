#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_MAX 30000

void insertion_sort(int *a, int n){
    
    /*define variables for insertion sort...*/
    int i;
    int key;
    int j;

    /*use insertion sort to sort the array*/
    for (i=1;i<n;i++){
        key = a[i];
        j = i - 1;
        while (j>=0 && a[j]>key) {
            a[j+1] = a[j];
            j = j - 1;
        }
        a[j+1] = key;
    }
    
}

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void quicksort(int* a, int len) {
    int pivot = a[0];
    int i = -1;
    int j = len;

    if (len < 2) {
        return;
    }

    for (;;) {
        do {
            i++;
        } while (a[i] < pivot);
        do {
            j--;
        } while (a[j] > pivot);
        if (i < j) {
            swap(&a[i],&a[j]);
        } else {
            break;
        } 
    }
    quicksort(a,j+1);
    quicksort(a + (j+1), len - j - 1);
}

/* n is the size of the array */
void print_array(int *a, int n){
    if (n > 0 ) {
        printf("%d\n", a[0]);
        print_array(a + 1, n - 1);
    }
}

int main(void) {
    int my_array[ARRAY_MAX];
    int count = 0;

    while (count < ARRAY_MAX && 1 == scanf("%d", &my_array[count])) {
        count++;
    }

    quicksort(my_array,count);

    printf("printing array now! \n");

    print_array(&my_array[0],count);


    return EXIT_SUCCESS;
}
