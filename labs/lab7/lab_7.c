#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_LEN 80
#define ARRAY_LEN 10

void *emalloc(size_t s) {
    void *result = malloc(s);
    if (NULL == result) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

void print_array(char *stringlist[], int n, double average, int index) {
    /*here n is the size of the array of strings
     *we want to print all the entries of the string array 
     *that are longer than average... */
    if (index < n){
        if (strlen(stringlist[index]) > average){
            printf("%s\n", stringlist[index]);
            print_array(stringlist,n,average,index+1);
        } else {
            print_array(stringlist,n,average,index+1);
        }
    }
}

int main(void) {
    /*declaring variables*/
    char word[STRING_LEN];
    char *wordlist[ARRAY_LEN];
    int num_words;
    double average;
    int i;

    /*reading in words*/
    num_words = 0;
    while (num_words < ARRAY_LEN && 1 == scanf("%79s", word)) {
        wordlist[num_words] = emalloc((strlen(word) + 1) * sizeof wordlist[0][0]);
        strcpy(wordlist[num_words], word);
        num_words++;
    }


    /*calculating the average length of words and printing it*/
    average = 0;
    for (i=0;i<num_words;i++){
        average += strlen(wordlist[i]);
    }

    average = average / num_words;
    printf("%f\n", average);

    printf("now printing greater than average words\n");

    /*now printing in all entries that are longer than average*/
    print_array(wordlist,num_words,average,0);

    /*freeing the memory allocated to wordlist*/
    for (i=0;i<num_words;i++){
        free(wordlist[i]);
    }

    return EXIT_SUCCESS;
}
