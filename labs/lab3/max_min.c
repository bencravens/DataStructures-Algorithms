#include <stdio.h>
#include <stdlib.h>

/* given the memory addresses of two integers,
 * swap their values */
void swap(int *x, int *y) {
    int old_x = *x; /* get the values at address x */
    *x = *y; /* the value at x gets the value at y. */
    *y = old_x; /* y gets the old value of x */
}

void max_min(int *a, int n, int *max, int *min){
    /* we want to sort the array, and then
     * call swap on the max and min elements.
     * use insertion sort. */
    
    /*define variables for insertion sort...*/
    int i;
    int key;
    int j;

    printf("printing a \n");

    /*display array*/
    for (i=0;i<n;i++){
        printf(" %d \n", a[i]);
    }

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
        printf(" %d \n", a[i]);
    }

    /*assign max and min values of array 
     * to corresponding addresses in memory
     * &big and &small */
    *max = a[n-1];
    *min = a[0];
}

int main(void) {

    int a[5] = {5, 4, 3, 2, 1};
    int n = 5;

    int big,small;

    printf("a and n declared. Now calling max_min \n");

    /*now call max_min*/
    max_min(a, n, &big, &small);

    printf("a max is %d, a min is %d\n",big,small);
    return EXIT_SUCCESS;
}
