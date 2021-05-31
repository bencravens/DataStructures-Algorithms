#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_LEN 90
#define ARRAY_LEN 10000

void* emalloc(size_t s) {
    void* result = malloc(s);
    if (NULL == result) {
        fprintf(stderr,"Memory allocation failed...\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

void swap(char** words, int i, int j) {
    /*swap two words in an array of pointers to words.
    The words are at index i & j*/
    char temp[strlen(words[i])+1];
    strcpy(temp,words[i]);
    strcpy(words[i], words[j]);
    strcpy(words[j], temp);
}

void selection_sort(char** a, int n){
    int p;
    int i;
    int min;
    
    for (p=0;p<n;p++) {
        /*set the default min to the current element*/
        min=p;
        /*grab an element*/
        for (i=p;i<n;i++){
            /*find the smallest item to the right of that element*/
            if (strcasecmp(a[i],a[min])<0) {
                min = i;
            }
        }
        /*Swap the current element with the smallest element to its right*/
        swap(a,min,p);
    }
}

int main(void) {
    char word[STRING_LEN];
    char* wordlist[ARRAY_LEN];
    int num_words;
    double average;
    int i;
    
    num_words = 0;
    while (num_words < ARRAY_LEN && 1 == scanf("%79s",word)) {
        wordlist[num_words] = emalloc((strlen(word)+1) * sizeof wordlist[0][0]);
        strcpy(wordlist[num_words], word);
        num_words++;
    }
    
    selection_sort(wordlist,num_words);
    
    for (i=0; i<num_words; i++) {
        printf("%s\n",wordlist[i]);
    }
    
    for (i=0; i<num_words; i++){
        free(wordlist[i]);
    }
    
    return EXIT_SUCCESS;
}
