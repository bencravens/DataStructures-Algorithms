#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ARRAY_SIZE 10000

void insertion_sort(int *a, int n){

    /*define variables for insertion sort...*/
    int i;
    int key;
    int j;

    /*use insertion sort to sort the array*/
    for (i=1;i<n;i++){
        key = a[i];
        j = i - 1;
        while ((j>=0) & (a[j]>key)) {
            a[j+1] = a[j];
            j = j - 1;
        }
        a[j+1] = key;
    }
    
}

int binary_search(int *a, int n, int left, int right, int target){
    
    /* recursive binary search.
     * takes in pointer to int array a,
     * length of array n,
     * left subarray index boundary left,
     * right subarray index boundary right,
     * and the target we are searching for. */    
    
    int mid;
    
    if (left > right) {
        printf("number not found");
        return EXIT_FAILURE;
    } else {
        mid = floor((left + right)/2); 
        if (a[mid] < target){
            /* left = mid + 1 */
            return binary_search(a,n,mid+1,right,target);    
        } else if (a[mid] > target) {
            /* right = mid - 1 */
            return binary_search(a,n,left,mid-1,target);
        } else {
            /* the value is there, return index*/
            return mid;
        }
    }
}

int binary_search_leftmost(int *a, int n, int left, int right, int target){
    
    /* recursive binary search.
     * takes in pointer to int array a,
     * length of array n,
     * left subarray index boundary left,
     * right subarray index boundary right,
     * and the target we are searching for. 
     * returns leftmost index of target in case of duplicates
     * */    
    
    int mid;
    if (left > right) {
        printf("number not found");
        return EXIT_FAILURE;
    } else {
        mid = floor((left + right)/2); 
        if (a[mid] < target) {
            binary_search_leftmost(a,n,mid+1,right,target);
        } else if (a[mid] > target) {
            binary_search_leftmost(a,n,left,mid,target);
        } else {
            while(--mid>=0) {
                if (a[mid]!=target) break;
            }
            return mid+1;
        }
    }
}

int binary_search_rightmost(int *a, int n, int left, int right, int target){
    
    /* recursive binary search.
     * takes in pointer to int array a,
     * length of array n,
     * left subarray index boundary left,
     * right subarray index boundary right,
     * and the target we are searching for. 
     * returns rightmost index of target in the case
     * of duplicates.
     * */    
    
    int mid;
    
    if (left > right) {
        printf("number not found");
        return EXIT_FAILURE;
    } else {
        mid = floor((left + right)/2); 
        if (a[mid] > target){
            return binary_search_rightmost(a,n,left,mid,target);    
        } else if (a[mid] < target) {
            return binary_search_rightmost(a,n,mid+1,right,target);
        } else {
            /* the value is there, return index*/
            while(++mid<=n) {
                if (a[mid]!=target) break;
            }
            return mid-1;
        }
    }
}


void test_search(int *a, int n, int *found, int target){
    int i;
    int leftmost, rightmost;

    /*initialize values in boolean array to 0*/
    for (i=0;i<n;i++){
        found[i]=0;
    }
    
    leftmost = binary_search_leftmost(a,n,0,n,target);
    rightmost = binary_search_rightmost(a,n,0,n,target);

    /*now set the values in the range to "+" */
    for (i=leftmost;i<=rightmost;i++){
        found[i] = 1;
    }

    /* now we print the boolean array */
    for (i=0;i<n;i++){
        if (found[i] == 1) {
            printf("+\n");
        } else {
            printf("-\n");
        }
    }
}

int main(int argc, char **argv) {
    FILE *infile;
    int my_array[ARRAY_SIZE];
    int num_items;
    int i;

    /*handling the case where there is no file */
    if (NULL == (infile = fopen(argv[1], "r"))){
        fprintf(stderr, "%s: can't find file %s\n", argv[0], argv[1]);
        return EXIT_FAILURE;
    }

    num_items=0;
    
    /*as long as we have not exceeded the array size, keep reading in numbers*/
    while (num_items < ARRAY_SIZE && 
            1 == fscanf(infile, "%d", &my_array[num_items])) {
        num_items++;
    }

    /*close the file*/
    fclose(infile);

    /*sort the array*/
    insertion_sort(my_array,num_items);

    /*print the array*/
    for (i = 0; i < num_items; i++) {
        printf(" %d\n", my_array[i]);
    }
    
    printf("doing binary search\n");
    int found[num_items];
    int target = atoi(argv[2]);
    test_search(my_array,num_items,found,target);

    return EXIT_SUCCESS;
}
