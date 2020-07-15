#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_LEN 80
<<<<<<< HEAD
#define ARRAY_LEN 10000
=======
#define ARRAY_LEN 8
>>>>>>> 00b95ea70b1cc9258504e0e0ee3f63bf9dbf57fe

void *emalloc(size_t s){
    void *result = malloc(s);
    if (NULL == result) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

void insertion_sort(char *a[], int n){
    
    /*define variables for insertion sort...*/
    int i;
    char *key;
    int j;

    /*just trying to print each word*/
    for (i=0;i<n;i++){
        printf("word is %s \n",a[i]);
    }

    /*use insertion sort to sort the array*/
    for (i=1;i<n;i++){
        key = a[i];
        j = i - 1;
        while (j>=0 && strcmp(a[j],key)>0) {
            a[j+1] = a[j];
            j = j - 1;
        }
        a[j+1]=key;
    }

}

int main(void) {
    char word[STRING_LEN];
    char *wordlist[ARRAY_LEN];
    int num_words;
    int i;

    num_words = 0;
    while (num_words < ARRAY_LEN && 1 == scanf("%79s", word)) {
        wordlist[num_words] = emalloc((strlen(word) + 1) * sizeof wordlist[0][0]);
        strcpy(wordlist[num_words], word);
        num_words++;
    }
    
    insertion_sort(wordlist, ARRAY_LEN);

    printf("printing sorted array \n");
    for(i=0;i<ARRAY_LEN;i++){
        printf("%s \n", wordlist[i]);
    }
    
    return EXIT_SUCCESS;
}
