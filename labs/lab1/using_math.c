#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {

    /* variable declarations */
    int i = 0;
    double j = 1.0;

    /* a familiar "for loop" */
    for (i = 0; i < 10; i++) {
        printf("%2d %6.0f %8.3f\n", i, j, sqrt(j)); /* sqrt defined in math.h */
        j *= 2;
    }

    return EXIT_SUCCESS; /* defined in stdlib.h */
}
