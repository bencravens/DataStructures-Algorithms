#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htable.h"
#include "mylib.h"

struct htablerec {
    int num_keys;
    int capacity;
    int* frequencies;
    char** keys;
};

static unsigned int htable_word_to_int(char *word) {
    unsigned int result = 0;
    
    while (*word != '\0') {
        result = (*word++ + 31 * result);
    }
    return result;
}

htable htable_new(int capacity) {
    int i;
    htable result = emalloc(sizeof result[0]);
    result->capacity = capacity;
    result->num_keys = 0;
    /* allocate memory for key frequency array */
    result->frequencies = emalloc((result->capacity) * sizeof result->frequencies[0]);
    /* allocate memory for key pointers*/
    result->keys = emalloc((result->capacity) * sizeof result->keys[0]);
    /* initialize frequencies to zero */
    for(i=0;i<capacity;i++){
        result->frequencies[i] = 0;
    }
    /* initialize keys to null */
    for(i=0;i<capacity;i++){
        /*allocate some memory to store null characters*/
        result->keys[i] = '\0';
    }
    return result;
}

void htable_free(htable h) {
    /*free memory in reverse of declaration order*/
    /*free individual keys*/
    int i;
    for (i=0;i<h->capacity;i++) {
        free(h->keys[i]);
    } 
    free(h->keys);
    free(h->frequencies); 
    free(h);
}

int htable_insert(htable h, char* str){
    /* convert input string to int */
    long myint = htable_word_to_int(str);
    /* use hash function h(k) = k mod M (M is capacity) */
    int index = myint % h->capacity;
    int i;

    /* now we try to insert into hash table */
    printf("INSERTING %s INTO HASH TABLE\n",str);

    /* not allowed to if the hash table is full... */
    if (h->num_keys >= h->capacity) {
        printf("capacity reached...\n");
        return 0;
    }

    /* if there is no string at the index, go ahead and insert */
    /*reallocate memory first (string may be longer)*/
 
    if (h->keys[index]==NULL){
        printf("no string at this index, just inserting\n");
        h->keys[index] = emalloc((strlen(str)+1) * sizeof str[0]);
        strcpy(h->keys[index],str);
        h->frequencies[index]++;
        h->num_keys++;
        return 1;
    } else if ((strcmp(h->keys[index],str)==0)) {
        printf("string already exists at this index\n");
        h->frequencies[index]++;
        return 1;
    } else {
        i = index;
        do {
            /* may need to wrap around to beginning of table again... */
            i = (i+1)%(h->capacity);
            if (h->keys[i]==NULL){
                printf("no string at this index, just inserting\n");
                h->keys[i] = emalloc((strlen(str)+1) * sizeof str[0]);
                strcpy(h->keys[i],str);
                h->frequencies[i]++;
                h->num_keys++;
                return 1;
            } else if ((strcmp(h->keys[i],str)==0)) {
                printf("string already exists at this i\n");
                h->frequencies[i]++;
                return 1;
            }
        } while (i%index!=0); /*stop when we reach where we were*/
        /*looks like hash table is full... return zero*/
        printf("hash table full...\n");
        return 0;
    }
    /*if the same string is already there */

    /* print stuff for debugging purposes */
    return 0;
}

void htable_print(htable h, FILE* stream) {
    int i;
    for(i=0;i<h->capacity;i++) {
        if (h->keys[i]!=NULL) {
            fprintf(stream,"%s appears %d times\n",h->keys[i],h->frequencies[i]);
        }
    }
}
