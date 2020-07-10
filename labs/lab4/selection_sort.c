#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_MAX 1000000

void selection_sort(int *a, int n){
    
    /*define loop counters*/
    int i;
    int j;

    /*display array...*/
    for(i=0; i<n; i++){
        printf("%d ",a[i]);
    }

    printf("\n");

    /*for each index in array a*/
    for(i=0;i<n;i++){
        /* find the minimum element in sub array a[i:n-1]
        * assume it is the first element at first */
        int min = a[i];
        int index = i;
        /*check it is smaller than other elements in sub array,
        *if there is a smaller element, replace it with that one. */
        for(j=i;j<n;j++){
            if(a[j] < a[i]){
                min = a[j];
                index = j;
            }
        }
        /*now put the minimum element in the sub array a[i:n-1] into position a[i]*/
        a[index] = a[i];
        a[i] = min;
    }

    /*now display again*/
    for(i=0; i<n; i++){
        printf("%d ",a[i]);
    }

    printf("\n");
 
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
