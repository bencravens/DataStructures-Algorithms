#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htable.h"
#include "mylib.h"

struct htablerec {
    int capacity;
    int num_keys;
    char** keys;
};

static unsigned int htable_word_to_int(char* word) {
    unsigned int result = 0;
    
    while (*word != '\0') {
        result = (*word++ + 31 * result);
    }
    return result;
}

static unsigned int htable_hash(htable h, unsigned int i_key) {
    return i_key % h->capacity;
}

htable htable_new(int capacity) {
    int i;
    htable result = emalloc(sizeof *result);
    result->capacity = capacity;
    result->num_keys = 0;
    result->keys = emalloc(capacity * sizeof result->keys[0]);
    /*initialize kets to null*/
    for (i=0;i<capacity;i++) {
        result->keys[i] = '\0';
    }
    return result;
}

void htable_free(htable h) {
    int i;
    for (i=0;i<h->capacity;i++) {
        free(h->keys[i]);
    }
    free(h->keys);
    free(h);
}

int htable_insert(htable h, char* key) {
    long myint = htable_word_to_int(key);
    int index = htable_hash(h,myint);
    int ind;
    if (h->num_keys == h->capacity) {
        fprintf(stderr, "ERROR: hash table is full. Cannot insert.\n");
        exit(EXIT_FAILURE);
    }
    /*index is empty, so insert key into table*/
    if (h->keys[index] == NULL ) {
        h->keys[index] = emalloc((strlen(key) + 1) * sizeof key[0]);
        strcpy(h->keys[index],key);
        h->num_keys++;
        return 1;
    /*if the key is already there do nothing*/
    } else if (strcmp(key,h->keys[index])==0) {
        return 0;
    } else {
        /*search for next empty bin*/
        ind = index + 1;
        while(ind != index) {
            /* ind might reach end of hash table, so loop around
            * to beginning again to search other half of table*/
            if (ind >= h->capacity) {
                ind = ind % h->capacity;
            }
            /*index is empty, so insert key into table*/
            if (h->keys[ind] == NULL ) {
                h->keys[ind] = emalloc((strlen(key) + 1) * sizeof key[0]);
                strcpy(h->keys[ind],key);
                h->num_keys++;
                return 1;
            /*if the key is already there do nothing*/
            } else if (strcmp(key,h->keys[ind])==0) {
                return 0;
            /*otherwise this index is occupied, look at the next one*/
            } else {
                ind++;
            }
        }
    }
    /*we have failed to insert ...*/
    fprintf(stderr, "Failed to insert... (should not reach this point)\n");   
    return 0;
}

void htable_print(htable h, FILE* stream) {
    int i;
    for (i=0;i<h->capacity;i++) {
        if (h->keys[i] != NULL) {
            fprintf(stream, "%s\n",h->keys[i]);
        }
    }
}
