#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <stdio.h>

int getword(char* s, int limit, FILE* stream) {
    int c;
    char* w = s;
    assert(limit > 0 && s != NULL && stream != NULL);
    
    /*skip to the start of the word*/
    while (!isalnum(c = getc(stream)) && EOF != c) 
        ;
    if (EOF == c) {
        return EOF;
    } else if (--limit > 0) {
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

void* emalloc(size_t n) {
    void* result = malloc(n);
    if (result==NULL) {
        fprintf(stderr, "malloc failed.\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

void* erealloc(int* a, size_t n) {
    void* result = realloc(a,n);
    if (result == NULL) {
        fprintf(stderr, "realloc failed\n");
        exit(EXIT_FAILURE);
    }
    return result;
}
