#include <stdio.h>
#include <stdlib.h>

double smaller(double a, double b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int main(void) {
    double s1, s2, s3;
    double min;
    double score;
    double winner_score=0;
    int id;
    int winner_id;

    while(4==scanf("%d%lg%lg%lg",&id,&s1,&s2,&s3)) {
        min = smaller(s1,smaller(s2,s3));
        if (min == s1) {
            score = (s2 + s3) / 2;
        } else if (min == s2) {
            score = (s1 + s3) / 2;
        } else {
            score = (s1 + s2) /2;
        } 
        if (score > winner_score) {
            winner_score = score;
            winner_id = id;
        }
    }
    
    printf("%d\n",winner_id);
    return EXIT_SUCCESS;
}
