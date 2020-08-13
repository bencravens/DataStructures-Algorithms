#include <stdio.h>
#include <stdlib.h>

int isprime(int n) {
    int i;
    for (i=2;i<n;i++) {
        if (n%i==0) {
            return 0; /*number is not prime*/
        }
    }
    return 1;   /*number is prime...*/
}

int main(void) {
    int i=2; /*print first 200 prime numbers*/
    int num_printed=0;
    while (num_printed < 200) {
        if(isprime(i)) {
            printf("%5d",i);
            num_printed++;
            if (num_printed%10==0) {
                printf("\n");
            }
        }
        i++;
    }
    return EXIT_SUCCESS;
}
