#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int i = 5;
    /*pointer variable*/
    int *p; 

    printf("i is %d, the address of i is %p\n", i, &i);

    p = &i;  
    /* p is now storing the address of i (whatever that is) */
    printf("p is %p, what’s stored at p is %d\n", p, *p);
    
    *p = 6; 
    /* make the value stored at memory location p 6, i.e i=6*/
    printf("what's stored at p is %d, i is %d\n", *p, i);

    return EXIT_SUCCESS;
}
