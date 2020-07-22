#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_MAX 80
#define NUM_WORDS 5

void *emalloc(size_t n){
    void *result = malloc(n);
    if (result == NULL){
        fprintf(stderr,"memory allocation failed...\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

void print_above_average(char **word_list, int length, double average){
    if (length > 0){
        if(strlen(word_list[0]) > average){
            printf("%s\n",word_list[0]);
        }
        print_above_average(word_list + 1, length - 1, average);
    }
}

int main(void) {
    char word[ARRAY_MAX];
    char *word_list[NUM_WORDS];
    int num_words = 0;
    int i;
    double average,total=0;

    while (num_words < NUM_WORDS && 1 == scanf("%79s",word)){
        word_list[num_words] = emalloc( strlen(word + 1) * sizeof word[0]);
        strcpy(word_list[num_words],word);
        total += strlen(word);
        num_words++;
    }

    average = (total/num_words);
    fprintf(stderr,"%.2f\n",average);
   
    print_above_average(word_list,num_words,average);

    for (i=0;i<num_words;i++){
        free(word_list[i]);
    }

    return EXIT_SUCCESS;
}
