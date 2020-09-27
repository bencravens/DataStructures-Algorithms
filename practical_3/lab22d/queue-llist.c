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
    int length;
    q_item first;
    q_item last;
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
    double item;
    q_item temp;
    if (q->length>0) {
        item = q->first->item;
        temp = q->first->next;
        free(q->first);
        q->first = temp;
        q->length--;
        return item;
    } else {
        exit(EXIT_FAILURE);
    }
}

void queue_print(queue q) { 
    q_item temp=q->first;
    while(temp!=NULL) {
        printf("%.2f\n",temp->item);
        temp=temp->next;
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
    q_item iter=q->first;
    q_item temp;
    while(iter!=NULL) {
        temp = iter->next;
        free(iter);
        iter = temp;
    }
    free(iter);
    free(q);
    return q;
}
