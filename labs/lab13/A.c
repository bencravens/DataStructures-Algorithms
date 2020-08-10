#include <stdio.h>
#include <stdlib.h>

int is_prime(int n) {
    int i=2;
    for(i=2;i<n;i++) {
        if (n%i==0) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    int init = 2;
    int colcount = 0;
    while (init < 200) {
        if (is_prime(init)) {
            colcount++;
            if (colcount%10==0) {
                printf("%5d\n",init);
            } else {
                printf("%5d",init);
            }
        }
        init++;
    }
    return EXIT_SUCCESS;
}
