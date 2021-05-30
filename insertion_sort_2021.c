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
        
        /*
        printf("a[p] is %d\n",a[p]);
        printf("a[left_p] is %d\n",a[left_p]);
        printf("array is: \n");
        for (i=0;i<n;i++) {
            printf("%d\n",a[i]);
        }
        */
        
        /* find position to the left of where a[p] should
        go... */
        while (a[left_p] > key && left_p >= 0) {
            left_p--;
        }
        
        /*printf("position of a[p] in array is index %d\n",left_p+1);*/
        
        /*now, starting with the index i=p-1, set a[i+1]=a[i]
        (shift entry to the right) and then increment i down (i--)
        until we are at the left most entry (i=left_p)*/
        for(i=p-1;i>left_p;i--){
            a[i+1] = a[i];
        }
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
