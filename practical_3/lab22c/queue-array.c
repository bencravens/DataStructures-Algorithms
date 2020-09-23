#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "queue.h"

struct queue {
    int num_items;
    int capacity;
    int head;
    double* items;
};

queue queue_new() {
    int default_size = 7;
    int i;
    queue q = emalloc(sizeof *q);
    q->num_items = 0;
    q->capacity = default_size;
    q->head = 0;
    q->items = emalloc(q->capacity * sizeof q->items[0]);
    /*initialize array to 0.0*/
    for (i=0;i<default_size;i++) {
        q->items[i] = 0.0;
    }
    return q;
}

void enqueue(queue q, double item) {
    if (q->num_items < q->capacity) {
        q->items[(q->head + q->num_items) % q->capacity] = item;
        q->num_items++;
    } else if (q->num_items == q->capacity) {
        /*trying to insert into empty queue, do nothing instead...*/
        return;
    }
}

double dequeue(queue q) {
    double item;
    if (q->num_items == 0) {
        /*cannot dequeue empty queue, do nothing instead...*/
        exit(EXIT_FAILURE);    
    } else {
        item = q->items[q->head];
        q->head++;
        q->num_items--;
        return item; 
    }
}

void queue_print(queue q) {
    int i;
    double temp;
    for (i=0;i<q->num_items;i++) {
        temp = q->items[(q->head + i) % q->capacity];
        printf("%.2f\n",temp);
    }
}

void queue_print_info(queue q) {
    int i;
    printf("capacity %d, num_items %d, head %d\n[",q->capacity,
        q->num_items, q->head);
    for (i=0; i< q->capacity; i++) {
        printf("%s%.2f", i == 0 ? "" : ", ", q->items[i]);
    }
    printf("]\n");
}

int queue_size(queue q) {
    return q->num_items;
}

queue queue_free(queue q) {
    free(q->items);
    free(q);
    q = NULL;
    return q;
}
