#include <stdlib.h>
#include <stdio.h>

int main()
{
    /** judge scores **/
    int s1,s2,s3;
    /** scanf return code **/
    int return_code;
    /** average result **/
    double average;
    
    printf("Enter the 3 scores:\n");
    return_code = scanf("%d%d%d",&s1,&s2,&s3);
    if (return_code!=3) {
        printf("scanf failed.\n");
        return EXIT_FAILURE;
    }
    printf("input was %d %d %d\n",s1,s2,s3);
    if (s1<s2 && s1<s3) {
        average = (s2 + s3) / 2.0;
        printf("%f",average);
    } else if (s2<s1 && s2<s3) {
        average = (s1 + s3) / 2.0;
        printf("%f",average);
    } else {
        average = (s1 + s2) / 2.0;
        printf("%f",average);
    }
    return 0;
}
