#include <stdio.h>
#include <stdlib.h>

/*returns bigger number*/
double bigger(double a, double b) {
    if (a > b) {
        return a;
    } else if (a==b) {
        return a;
    } else {
        return b;
    }
}

/*returns smaller number*/
double smaller(double a, double b) {
    if (a<b) {
        return a;
    } else if (a==b) {
        return a;
    } else {
        return b;
    }
}

int main(void) {
    double s1;
    double s2;
    double s3;
    double min;
    int id;
    double score;
    int largest_id;
    double largest_score = 0;

    while (4==scanf("%d%lg%lg%lg",&id,&s1,&s2,&s3)) {
        min = smaller(s1,smaller(s2,s3));
        if (s1==min) {
            score = (s2 + s3)/2;
        } else if (s2==min) {
            score = (s1 + s3)/2;
        } else {
            score = (s1 + s2)/2;     
        }
        if (score > largest_score) {
            largest_score = score;
            largest_id = id;
        }
    }
    
    printf("%d\n",largest_id);
    return EXIT_SUCCESS;
}
