#include <stdio.h>
#include <stdlib.h>

double smaller(double a, double b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

double bigger(double a, double b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main(void) {
    double s1,s2,s3;
    double min;
    double score;
    int id;
    double max = 0;
    int max_id;
    
    while (4==scanf("%d%lg%lg%lg",&id,&s1,&s2,&s3)) {
        min = smaller(s1,smaller(s2,s3));
        if (s1 == min) {
            score = (s2 + s3) / 2;
        } else if (s2 == min) {
            score = (s1 + s3) / 2;
        } else {
            score = (s1 + s2) / 2;
        } 
        if (score > max) {
            max = score;
            max_id = id;
        }
    }
    
    printf("%d\n",max_id);
 
    return EXIT_SUCCESS;
}   
