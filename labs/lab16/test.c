#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rbt.h"
#include "mylib.h"

#define ARRAY_LEN 10
#define NUM_WORDS 10

int main(void) {
    rbt b = NULL; /*start with empty tree*/
    char word[256];
    while(getword(word,256,stdin) != EOF) {
        b = rbt_insert(b,word);
    }

    printf("\n\n\n\n\n-----------------------\n\n\n\n");

    rbt_preorder(b);
    rbt_free(b);

    return EXIT_SUCCESS;
}
