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
    double result;
    q_item q_temp;
    if (q->length > 0) {
        result = q->first->item;
        q_temp = q->first->next;
        free(q->first);
        q->first = q_temp;
        q->length--;
        return result;
    } else {
        exit(EXIT_FAILURE);
    }
}

void queue_print(queue q) { 
    q_item q_temp = q->first;
    while (q_temp!=NULL) {
        printf("%.2f\n",q_temp->item);
        q_temp = q_temp->next;
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
    free(i);
}

queue queue_free(queue q) {
    q_item iter = q->first;
    q_item temp;
    while(iter->next!=NULL) {
        temp = iter->next;
        free(iter);
        iter = temp;
    }
    free(iter);
    free(q);
    return q;
}
