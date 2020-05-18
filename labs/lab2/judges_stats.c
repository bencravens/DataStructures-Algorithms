#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double stddev(double *judge, double mean, int size){
    /* calculate the standard deviation */
    
    double variance = 0;
    double stddev = 0;
    int i = 0;

    /* find total squared distance between
     * samples and mean
     */
    for (i=0; i<size; i++){
        variance += pow(judge[i] - mean,2);
        printf("%f\n",variance);
    }
   
    /* normalize variance*/
    variance /= size;
    /* stddev is sqrt of variance */
    stddev = sqrt(variance);
    return stddev;
}


double mean(double *judge, int size){
    /* calculate the mean */
    int i = 0;
    double total = 0;
    double mean = 0;

    for (i=0; i<size; i++){
        printf("%f \n", judge[i]);
        total += judge[i];
    }

    mean = total/i; 
    printf("mean is %f \n",mean); 
    return mean;
}

int main(void) {
    
    /* now defining input data
     * in format 44 3.1 5.0 4.7
     * id score1 score2 score3 
     */
    
    int n = 0;
    /* arrays for storing scores of different judges */
    double judge1[10];
    double judge2[10];
    double judge3[10];
    /* values to store the mean scores for different judges */
    double mean1 = 0;
    double mean2 = 0;
    double mean3 = 0;
    /* values to store the stddev scores for different judges */
    double stddev1 = 0;
    double stddev2 = 0;
    double stddev3 = 0; 
    /* loop counters */
    int count=0;
    int i=0;


    /* read in arrays */
    while (4 == scanf("%d%lg%lg%lg", &n, &judge1[count], &judge2[count], &judge3[count])){    
        count++;             
    } 

    /* print entries from each judge array */
    mean1 = mean(judge1,count);
    mean2 = mean(judge2,count);
    mean3 = mean(judge3,count);

    /* now calculate stddev */
    stddev1 = stddev(judge1,mean1,count);
    stddev2 = stddev(judge2,mean2,count);
    stddev3 = stddev(judge3,mean3,count);    
    
    printf("mean 1 is %f \n",mean1);
    printf("stddev 1 is %f \n",stddev1);
    printf("mean 2 is %f \n",mean2);
    printf("stddev 2 is %f \n",stddev2);
    printf("mean 3 is %f \n",mean3);
    printf("stddev 3 is %f \n",stddev3);
  
    return EXIT_SUCCESS;
}

