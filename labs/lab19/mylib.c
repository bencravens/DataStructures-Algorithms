#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "mylib.h"

void* emalloc(size_t n) {
    void* result = malloc(n);
    if (result == NULL) {
        fprintf(stderr, "memory allocation failed!");
        exit(EXIT_FAILURE);
    }
    return result;
}

void* erealloc(void* my_array, size_t n) {
    void* result = realloc(my_array, n);
    if (result == NULL) {
       fprintf(stderr, "memory re-allocation failed!\n");
       exit(EXIT_FAILURE);
    }
    return result; 
}

int getword(char *s, int limit, FILE *stream) {
    int c;
    char *w = s;
    assert(limit > 0 && s != NULL && stream != NULL);

    /*skip to start of word*/
    while (!isalnum(c = getc(stream)) && EOF != c) 
        ;
    if (EOF == c) {
        return EOF;
    } else if (--limit > 0) { /* reduce limit by 1 to allow for the \0 */
        *w++ = tolower(c);
    }
    while (--limit > 0) {
        if (isalnum(c = getc(stream))) {
            *w++ = tolower(c);
        } else if ('\'' == c) {
            limit++;
        } else {
            break;
        }
    }
    *w = '\0';
    return w - s;
}
