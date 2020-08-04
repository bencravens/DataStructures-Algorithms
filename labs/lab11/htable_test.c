#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "htable.h"
#include <cstdlib>

int main(void) {
    
    int capacity = atoi(argv[1]);

    htable h = htable_new(capacity);
    char word[256];

    while (getword(word, sizeof word, stdin) != EOF) {
        htable_insert(h, word);
    }

    htable_print(h, stdout);
    htable_free(h);

    return EXIT_SUCCESS;
}
