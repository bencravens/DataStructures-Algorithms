#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_MAX 1000000

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selection_sort(int *a, int n){
    
    /*define loop counters*/
    int i;
    int j;
    
    /*move boundary of subarray in which we are finding the minimum*/
    for(i=0;i<n-1;i++){
        /* find the minimum element in sub array a[i:n-1]
        * assume it is the first element at first */
        int index = i;
        /*check it is smaller than other elements in sub array,
        *if there is a smaller element, replace it with that one. */
        for(j=i+1;j<n;j++){
            if(a[j] < a[index]){
                index = j;
            }
        }
        /*now put the minimum element in the sub array a[i:n-1] into position a[i]*/
        swap(&a[index],&a[i]); 
    }

}

int main(void) {
    int my_array[ARRAY_MAX];
    int i, count = 0;
    clock_t start, end;

    while (count < ARRAY_MAX && 1 == scanf("%d", &my_array[count])) {
        count++;
    }

    start = clock();
    selection_sort(my_array, count);
    end = clock();

    fprintf(stderr, "%d %f\n", count, (end - start) / (double)CLOCKS_PER_SEC);

    return EXIT_SUCCESS;
}
