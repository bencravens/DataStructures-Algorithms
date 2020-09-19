#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "queue.h"

/*an implementation of a linked list queue*/

typedef struct q_item *q_item;

struct q_item {
    double item;
    q_item next;
};

/*define the queue struct*/
struct queue {
    q_item first;
    q_item last;
    int length;
};

queue queue_new() {
    /*initialize queue*/
    queue Q = emalloc(sizeof *Q);
    Q->first = NULL;
    Q->last = NULL;
    Q->length = 0;
    /*done*/
    return Q;
}

void enqueue(queue Q, double item) {
    /*make new q_item*/
    q_item q_new = emalloc(sizeof *q_new);
    /*initialize key*/
    q_new->item = item;
    /*q_new will be the last item, so there is 
    * nothing after it...*/
    q_new->next = NULL;
    /*is the queue empty... then our q_item will be first*/
    if (Q->length == 0) {
        /*only q_new in queue, so it is "first" and "last"*/
        Q->first = q_new;
        Q->last = q_new;
    } else {
        /*now q_new comes after current Q_last...*/
        Q->last->next = q_new;
        /*now the last item is q_new*/
        Q->last = q_new;
    }
    /*increment number of items...*/
    Q->length++;
    printf("queued %f\n successfully.\n",Q->last->item);
}

double dequeue(queue Q){
    double item;
    q_item temp;
    /*can't dequeue an empty queue...*/
    if (Q->length == 0) {
        fprintf(stderr,"ERROR: can't dequeue empty queue...\n");
        exit(EXIT_FAILURE);
    } else {
        /*pop "first" element*/
        /*temp pointer to keep track of Q->first after 
        * we unlink it from queue*/
        temp = Q->first;
        /*set item we are dqing to return*/
        item = temp->item;
        Q->first = temp->next;
        free(temp);
        /*we have one less item...*/
        Q->length--;
    }
    return item;
}

void queue_print(queue Q) {
    q_item q_cur;
    /*nothing to print if queue is empty...*/
    if (Q->length == 0) {
        fprintf(stderr,"Queue is empty...\n");
    } else {
        /*iterate over Q items, starting with Q_first*/
        q_cur = Q->first;
        while(q_cur != NULL) {
            printf("%f\n",q_cur->item);
            q_cur = q_cur->next;
        }
    }
}

int queue_size(queue Q) {
    return Q->length;
}

queue queue_free(queue Q) {
    q_item q_cur = emalloc(sizeof *q_cur);
    /*while there are still items in queue*/
    while (Q->length > 0) { 
        /*store the next Q first in a temp var*/
        q_cur = Q->first->next;
        /*free current Q first*/
        free(Q->first);
        /*now our temp var is the next Q first*/
        Q->first = q_cur;
        /*we have one less item in queue*/
        Q->length--;
    }
    free(q_cur);
    free(Q);
    Q = NULL;
    return Q; 
}
