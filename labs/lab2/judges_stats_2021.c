#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double average(double* judge, double size) {
    int i;
    double total=0;
    double average;
    for (i=0;i<size;i++){
        total+=judge[i];
    }
    average = total/size;
    return average;
}

double stddev(double* judge, double size, double mean) {
    /**calculate sum of square of difference from mean **/
    int i;
    double variance = 0;
    double stddev;
    for (i=0;i<size;i++){
        variance+=pow(judge[i] - mean,2);
    }
    /**now return stddev**/
    variance /= size;
    stddev = sqrt(variance);
    return stddev;
}

int main()
{
    int i;
    /** means for each array **/
    double mean1, mean2, mean3;
    /** stddev for each array **/
    double stddev1, stddev2, stddev3;
    /** scores for each judge **/
    double s1,s2,s3;
    /** judge scores **/
    double judge1[10];
    double judge2[10];
    double judge3[10];
    /** entry id **/
    int id;
    /** number of participants passed **/
    int num=0;
    
    printf("Enter ID & then the 3 scores:\n");
    while (4 == scanf("%d%lg%lg%lg",&id,&s1,&s2,&s3)) {
        /**add scores to arrays**/
        judge1[num] = s1;
        judge2[num] = s2;
        judge3[num] = s3;
        num++;
        printf("input was %d %f %f %f\n",id,s1,s2,s3);
    }
    
    printf("judge 1 scores are:\n");
    for(i=0;i<num;i++){
        printf(" %f ",judge1[i]);
    }
    
    printf("\njudge 2 scores are:\n");
    for(i=0;i<num;i++){
        printf(" %f ",judge2[i]);
    }
    
    printf("\njudge 3 scores are:\n");
    for(i=0;i<num;i++){
        printf(" %f ",judge3[i]);
    }
    
    /**calculate means**/
    mean1 = average(judge1,num);
    mean2 = average(judge2,num);
    mean3 = average(judge3,num);
    
    /**calculate stddev**/
    stddev1 = stddev(judge1,num,mean1);
    stddev2 = stddev(judge2,num,mean2);
    stddev3 = stddev(judge3,num,mean3);
    
    printf("\njudge 1: mean %f sd %f\n",mean1,stddev1);
    printf("judge 2: mean %f sd %f\n",mean2,stddev2);
    printf("judge 3: mean %f sd %f\n",mean3,stddev3);
    
    return 0;
}
