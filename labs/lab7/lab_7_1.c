#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_LEN 80
#define NUM_WORDS 4

void *emalloc(size_t n){
    void *result = malloc(n);
    if (result == NULL) {
        fprintf(stderr,"memory failed to allocate\n");
        exit(EXIT_FAILURE);
    } 
    return result;
}

int main(void) {
    char word[ARRAY_LEN];
    char *word_list[NUM_WORDS];
    int num_words=0;
    double average;
    int i;

    while (num_words < NUM_WORDS && 1 == scanf("%79s",word)){
        word_list[num_words] = emalloc( strlen(word+1) * sizeof word_list[0][0]);
        strcpy(word_list[num_words],word);
        num_words++;  
    }

    for(i=0;i<num_words;i++){
        printf("word %d is %s\n",i,word_list[i]);
    }

    return EXIT_SUCCESS;
    
}
