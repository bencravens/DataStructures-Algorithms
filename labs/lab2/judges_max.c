#include <stdio.h>
#include <stdlib.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

int main(void) {
    /*maximum score*/
    double max = 0;
    /*who had the max score*/
    int id = 0;

    /* now defining input data
     * in format 44 3.1 5.0 4.7
     * id score1 score2 score3 
     */
    int n = 0;
    double a = 1.0;
    double b = 2.0;
    double c = 3.0;
    /*temporary variable for current maximum of (a,b,c) */
    double temp_max = 0;

    while (4 == scanf("%d%lg%lg%lg", &n, &a, &b, &c)){    
        temp_max = MAX(MAX(a,b),c);
        if (temp_max>max) {
            max = temp_max;
            id = n;
        }
    }
    printf ("max = %f, ID = %d\n",max,id);
    return EXIT_SUCCESS;
} 
