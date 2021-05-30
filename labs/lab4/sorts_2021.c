#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_MAX 100000

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selection_sort(int* a, int n){
    int p;
    int i;
    int min;
    
    for (p=0;p<n;p++) {
        /*set the default min to the current element*/
        min=p;
        /*grab an element*/
        for (i=p;i<n;i++){
            /*find the smallest item to the right of that element*/
            if (a[i] < a[min]) {
                min = i;
            }
        }
        /*Swap the current element with the smallest element to its right*/
        swap(&a[min],&a[p]);
    }
}

void insertion_sort(int* a, int n){
    int p;
    int key;
    int left_p;
    int i;
    
    for (p=1;p<n;p++) {
        
        key = a[p];
        left_p = p-1;
        
        /* find position to the left of where a[p] should
        go... */
        while (a[left_p] > key && left_p >= 0) {
            a[left_p+1]=a[left_p];
            left_p--;
        }
        a[left_p+1]=key;
    }
}

int main() {
    int my_array[ARRAY_MAX];
    clock_t start, end;
    int i, count=0;
    
    while (count < ARRAY_MAX && 1 == scanf("%d", &my_array[count])) {
        count++;
    }
    
    start = clock();
    insertion_sort(my_array, count);
    end = clock();
    
    for (i=0; i<count; i++) {
        printf("%d\n", my_array[i]);
    }
    
    printf("%d %f\n",count, (end-start)/ (double)CLOCKS_PER_SEC);
    
    return EXIT_SUCCESS;
}
