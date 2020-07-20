#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_MAX 10

void insertion_sort(int *a, int n){
    
    /*define variables for insertion sort...*/
    int i;
    int key;
    int j;

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
    clock_t start, end;
    int i, count = 0;

    while (count < ARRAY_MAX && 1 == scanf("%d", &my_array[count])) {
        count++;
    }

    start = clock(); 
    insertion_sort(my_array, count);
    end = clock();

    printf("printing array now! \n");

    print_array(&my_array[0],count);

    fprintf( stderr, "%d %f\n", count, (end - start) / (double)CLOCKS_PER_SEC);

    return EXIT_SUCCESS;
}
