#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"
#include "mylib.h"

#define ARRAY_LEN 10
#define NUM_WORDS 10

int main(void) {
    bst b = bst_new();
    char word[ARRAY_LEN];
    char* word_list[NUM_WORDS];
    int num_words = 0;
    int i;
    /*read in a bunch of words*/
    while ((num_words < NUM_WORDS) && (1==scanf("%79s",word))) {
        word_list[num_words] = malloc((strlen(word)+1) * sizeof word_list[0][0]);
        strcpy(word_list[num_words],word);
        num_words++;
    }
    /* insert words into BST */
    for (i=0;i<num_words;i++) {
        b = bst_insert(b,word_list[i]);
    } 
    printf("printing all now\n");
    bst_inorder(b,print_key);
    printf("is \"test\" in the tree?\n");
    if (bst_search(b,"test")) {
        printf("yes!\n");
    } else {
        printf("no!\n");
    }
    return EXIT_SUCCESS;
}
