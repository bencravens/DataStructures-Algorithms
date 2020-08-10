#include <stdio.h>
#include <stdlib.h>

/*determine the maximum of a,b and c*/
double maximum(double x, double y) {
    if (x==y) {
        return x;
    } else if (x > y) {
        return x;
    } else {
        return y;
    }
}

double minimum(double x, double y) {
    if (x==y) {
        return x;
    } else if (x < y) {
        return x;
    } else {
        return y;
    }
}


int main(void) {
    double s1, s2, s3; /*judge scores*/
    int id; /*participant id number*/
    int winner_id; /*who got the maximum score*/
    double score;
    double min;
    double best_score=0;
    while (4==scanf("%d%lg%lg%lg", &id, &s1, &s2, &s3)) {
        min = minimum(s1,minimum(s2,s3)); 
        if (s1==min) {
            score = (s2 + s3)/2;
        } else if (s2==min) {
            score = (s1 + s3)/2;
        } else {
            score = (s1 + s2)/2;
        }
        if (score > best_score) {
            winner_id = id;
            best_score = score;
        }
    }
    printf("%d\n",winner_id);
    return EXIT_SUCCESS;
}
