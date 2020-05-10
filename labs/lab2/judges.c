#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int return_code;
    double score1, score2, score3;
    printf("This program will read in 3 doubles.\n");
    
    
    /*make sure output is written to screen*/
    fflush(stdout);
    /*return code to catch EOF or unsuccessful read errors*/
    return_code = scanf("%lg%lg%lg", &score1, &score2, &score3);
    
    /*make sure scores were read correctly*/
    if (return_code != 3) {
        printf("scanf returned code %d\n", return_code);
        return EXIT_FAILURE;
    }

    /*determine which score is the lowest. Discard this, and average the other two.*/
    fflush(stdout);    
    if (score1<score2 && score1<score3){
        printf("%f\n",(score2 + score3)/2);
    } else if (score2<score1 && score2<score3){
        printf("%f\n",(score1 + score3)/2);
    } else {
        printf("%f\n",(score1 + score2)/2);
    }
    return 0;
}
