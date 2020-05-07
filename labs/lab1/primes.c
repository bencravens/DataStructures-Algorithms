#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int x){
    int i=0;
    /* check for divisibility */
    for (i=2; i<x; i++){
        if(x%i==0){
            return 0;
        }    
    }
    return 1;
}

int main(void) {

    int i = 0; 
    /* n is number of primes */
    int n = 0;     

    while (n<100) {
        if (is_prime(i)) {
            n += 1;
            printf("%d is prime\n",i);
        }
        i++;
    }

    printf("%d total prime numbers\n",n);
    return EXIT_SUCCESS; /* defined in stdlib.h */
}
