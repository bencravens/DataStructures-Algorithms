#include <stdio.h>
#include <stdlib.h>

int isprime(int num) {
    int i;
    for (i=2;i<num;i++) {
        if (num%i==0) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    int num = 2;
    int nums_printed = 0;
    while (nums_printed < 200) {
        if (isprime(num)) {
            printf("%5d",num);
            nums_printed++;
            if (nums_printed%10==0) {
                printf("\n");
            }
        }
        num++;
    }
    return EXIT_SUCCESS;
}
