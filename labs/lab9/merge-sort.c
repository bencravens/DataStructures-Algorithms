#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define ARRAY_MAX 30000

/* n is the size of the array */
void print_array(int *a, int n){
    if (n > 0 ) {
        printf("%d\n", a[0]);
        print_array(a + 1, n - 1);
    }
}

void merge(int *array, int *workspace, int len){
    /*point to beginning of left half*/
    int i = 0;
    /*poinr to beginning of right half*/
    int j = len/2;
    /*index indicating how many items have been sorted into result array*/
    int k = 0;

    /*while there are items remaining in both halves*/
    while((i < len/2) && (j<len)){
       if (array[i] < array[j]) {
           workspace[k] = array[i];
           i++;
           k++;
       } else {
           workspace[k] = array[j];
           j++;
           k++;
       } 
    }
   
    /*first and second halves of array may not finish allocating to
     * workspace at the same time, so now take care of leftover elements
     * in the half arrays */

    /*copy over remaining elements from left array to workspace*/
    while(i < len/2){
        workspace[k] = array[i];
        i++;
        k++;
    }
    /*copy over remaining elements from right array to workspace*/
    while(j < len){
        workspace[k] = array[j];
        j++;
        k++;
    }
}

void merge_sort(int *array, int *workspace, int len){
    int i;

    if (len < 2) {
        return;
    }
    
    /*call merge sort on first half of array*/
    merge_sort(array,workspace,len/2);
    /*call merge sort on second half of array*/
    merge_sort(array + (len/2),workspace, len - (len/2));

    merge(array,workspace,len);

    /*now copy merged, sorted array into place*/
    for(i=0;i<len;i++){
        array[i] = workspace[i];
    }
}


int main(void) {
    int my_array[ARRAY_MAX];
    int workspace[ARRAY_MAX];
    int count = 0;
    clock_t start, end;

    while (count < ARRAY_MAX && 1 == scanf("%d", &my_array[count])) {
        count++;
    }

    start = clock();
    merge_sort(my_array, workspace, count);
    stop = clock();

    printf("printing array now! \n");

    print_array(&my_array[0],count);

    fprintf( stderr, "%d %f\n", count, (end - start) / (double)CLOCKS_PER_SEC);

    return EXIT_SUCCESS;
}
