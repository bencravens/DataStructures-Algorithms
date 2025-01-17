#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "queue.h"

typedef struct q_item *q_item;

struct q_item { 
    double item;
    q_item next;
};

struct queue {
    q_item first;
    q_item last;
    int length;
};

queue queue_new() {
    queue q = emalloc(sizeof *q);
    q->first = NULL;
    q->last = NULL;
    q->length = 0;
    return q;
}

void enqueue(queue q, double item) {
    q_item i = emalloc(sizeof *i);
    i->item = item;
    i->next = NULL;
    if (q->length == 0) {
        q->first = i;
    } else { 
        q->last->next = i;
    } 
    q->last = i;
    q->length++;
}

double dequeue(queue q) {
    q_item temp;
    double item;
    if (q->length == 0) {
        fprintf(stderr, "cannot dequeue, empty queue\n");
        exit(EXIT_FAILURE);
    }
    temp = q->first->next;
    item = q->first->item;
    free(q->first);
    q->first = temp;
    q->length--;
    return item;
}

void queue_print(queue q) { 
    int i;
    q_item temp = q->first;
    for (i=0;i<q->length;i++) {
        printf("%.2f\n",temp->item);
        temp = temp->next;
    }
}

void queue_print_info(queue q) {
    if (q->length == 0) {
        printf("The queue is empty\n");
    } else {
        printf("first %.2f, last %.2f, length %d\n", q->first->item,
                q->last->item, q->length);
    }
}

int queue_size(queue q) {
    return q->length;
}

void queue_free_aux(q_item i) {
    i->next = NULL;
    free(i);
}

queue queue_free(queue q) {
    q_item myq;
    q_item temp;
    myq = q->first;
    while (myq->next != NULL) {
        temp = myq->next;
        queue_free_aux(myq);
        myq = temp;
    }  
    free(myq);
    free(q);
    return q;
}
