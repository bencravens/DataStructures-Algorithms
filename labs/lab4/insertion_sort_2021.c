#include <stdio.h>
#include <stdlib.h>

#define ARRAY_MAX 100

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
    int i, count=0;
    
    while (count < ARRAY_MAX && 1 == scanf("%d", &my_array[count])) {
        count++;
    }
    
    insertion_sort(my_array, count);
    
    for (i=0; i<count; i++) {
        printf("%d\n", my_array[i]);
    }
    return EXIT_SUCCESS;
}
