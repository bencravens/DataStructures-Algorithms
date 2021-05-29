#include <stdio.h>
#include <stdlib.h>

void max_min(int* a, int n, int* max, int* min){
    int i;
    *max = a[0];
    *min = a[0];
    for(i=0;i<n;i++){
        printf("a[i] is %d, max is %d, min is %d\n",a[i],*max,*min);
        if (a[i]>*max) {
            *max = a[i];
        } else if (a[i]<*min) {
            *min = a[i];
        }
    }
}

int main()
{
    int my_array[] = { 5, 2, 7, 3, 4 };
    int biggest, smallest;
    max_min(my_array, 5, &biggest, &smallest);
    printf("max %d, min %d\n",biggest,smallest);
    return 0;
}
