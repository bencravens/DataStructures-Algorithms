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
    htable h = emalloc(sizeof *h);
    h->capacity = capacity;
    h->num_keys = 0;
    h->keys = emalloc(h->capacity * sizeof h->keys[0]);
    for (i=0; i < h->capacity; i++) {
        h->keys[i] = NULL;
    }
    return h;
}

void htable_free(htable h) {
    int i;
    for (i=0; i < h->capacity; i++) {
        free(h->keys[i]);
    }
    free(h->keys);
    free(h);
    h = NULL;
}

int htable_insert(htable h, char* key) {
    /*generate index based on string by hashing*/
    int i;
    int index;
    i = htable_word_to_int(key);
    index = htable_hash(h,i);
    /*if the index we have hashed is empty, simply insert.*/
    if (h->keys[index] == NULL) {
        h->keys[index] = emalloc((strlen(key)+1) * sizeof key[0]);
        strcpy(h->keys[index],key);
        h->num_keys++;
        return 1;
    } else if (strcmp(h->keys[index],key)==0) {
        /*key already exists at this index. do nothing 
         * as we are not storing frequencies */
        return 0;
    } else {
        /*A collision has occured. Insert key at next
         * available index. search the entire hash table
         * if need be by wrapping around*/
        i = index + 1;
        while ((i % h->capacity) != index) {
            fprintf(stderr, "i is %d, i mod capacity is %d, index is %d\n",i, i % h->capacity, index);
            if (h->keys[i % h->capacity] == NULL) {
                h->keys[i % h->capacity] = emalloc((strlen(key)+1) * sizeof key[0]);
                strcpy(h->keys[i % h->capacity],key);
                return 1;
            } else if (strcmp(h->keys[i % h->capacity],key)==0) {
                ;
            } else {
                i++;
            }
        }
        /*we have failed to insert.*/
        return 0;
    }
    /*should not reach here. */
    return 0;
}

void htable_print(htable h, FILE* stream) {
    int i;
    for (i=0;i<h->capacity;i++) {
        fprintf(stream, "%2d %s\n", i, h->keys[i] == NULL ? "" : h->keys[i]);
    }
}
