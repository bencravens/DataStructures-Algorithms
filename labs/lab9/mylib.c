#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"

void* emalloc(size_t n) {
    void* result = malloc(n);
    if (result == NULL) {
        fprintf(stderr, "memory allocation failed!");
        exit(EXIT_FAILURE);
    }
    return result;
}

void* erealloc(void* my_array, size_t n) {
    void* result = realloc(my_array, n);
    if (result == NULL) {
       fprintf(stderr, "memory re-allocation failed!\n");
       exit(EXIT_FAILURE);
    }
    return result; 
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
