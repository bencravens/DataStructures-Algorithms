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
    h->keys = emalloc(capacity * sizeof h->keys[0]);
    for (i=0; i<capacity; i++) {
        h->keys[i] = NULL;
    }
    return h;
}

void htable_free(htable h) {
    int i;
    for (i=0; i<h->capacity; i++) {
        free(h->keys[i]);
    }
    free(h->keys);
    free(h);
}

int htable_insert(htable h, char* key) {
    int ind = htable_word_to_int(key);
    int index = htable_hash(h,ind);
    if (h->keys[index]==NULL) {
        /*htable free at this index, just insert.*/
        h->keys[index] = emalloc((strlen(key)+1) * sizeof key[0]);
        strcpy(h->keys[index],key);
        h->num_keys++;
        return 1;
    } else if (strcmp(h->keys[index],key)==0) {
        return 0;
    } else {
        ind = index + 1;
        while ((ind % h->capacity) != index) {
            if (h->keys[ind % h->capacity] == NULL) {
                h->keys[ind % h->capacity] = emalloc((strlen(key)+1) * sizeof key[0]);
                strcpy(h->keys[ind % h->capacity], key);
                h->num_keys++;
                return 1;
            } else if (strcmp(h->keys[ind % h->capacity],key)==0) {
                return 0;
            } else {
                ind++;
            }
        }
        return 0;
    }
}

void htable_print(htable h, FILE* stream) {
    int i;
    for (i=0; i<h->capacity; i++) {
        if (h->keys[i]==0) {
            fprintf(stream, "%2d \n",i);
        } else {
            fprintf(stream, "%2d %s\n",i,h->keys[i]);
        }
    }
}
