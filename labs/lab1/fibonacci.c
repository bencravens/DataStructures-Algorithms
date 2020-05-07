#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {

    /* variable declarations */
    int f = 0;
    int g = 1;
    int i = 0;    
    int g_old;
    
    for (i = 0; i < 40; i++) {
        printf("%d\n",g);
        g_old = g;
        g += f;
        f = g_old;
    }

    return EXIT_SUCCESS; /* defined in stdlib.h */
}
