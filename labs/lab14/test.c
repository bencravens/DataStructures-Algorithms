#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"
#include "mylib.h"

#define ARRAY_LEN 10
#define NUM_WORDS 10

int main(void) {
    bst b = NULL; /*start with empty tree*/
    char word[256];
    while(getword(word,256,stdin) != EOF) {
        b = bst_insert(b,word);
    }

    printf("printing in order\n");
    bst_inorder(b,print_key);
    printf("deleting George\n");
    bst_delete(b, "george");
    bst_inorder(b,print_key);
    bst_free(b);

    return EXIT_SUCCESS;
}
