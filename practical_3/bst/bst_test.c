#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "mylib.h"

int main(void) {
    bst b = NULL;
    char word[256];
    while (getword(word,256,stdin) != EOF) {
        b = bst_insert(b, word);
    }

    printf("printing preorder\n");
    bst_preorder(b, print_key);
    printf("printing inorder\n");
    bst_inorder(b, print_key);
    if (bst_search(b, "apple")==1) {
        printf("found apple in tree\n");
    } else {
        printf("apple is not in tree...\n");
    }
    bst_free(b);
    return EXIT_SUCCESS;
}
