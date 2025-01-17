#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "queue.h"

struct queue {
    double* items;
    int head;
    int num_items;
    int capacity;
};

queue queue_new() {
    int default_size = 7;
    int i;
    queue q = emalloc(sizeof *q);
    q->head = 0;
    q->num_items = 0;
    q->capacity = default_size;
    q->items = emalloc(default_size * sizeof q->items[0]);
    for (i=0;i<default_size;i++) {
        q->items[i] = 0.0;
    }
    return q;
}

void enqueue(queue q, double item) {
    if (q->num_items == q->capacity) {
        return;
    } else {
        q->items[(q->head + q->num_items) % q->capacity] = item;
        q->num_items++;
    }
}

double dequeue(queue q) {
    double item;
    if (q->num_items!=0) {
        item = q->items[q->head];
        q->head = (q->head + 1) % q->capacity;
        q->num_items--;
        return item;
    } else {
        exit(EXIT_FAILURE);
    }
}

void queue_print(queue q) {
    int i;
    for(i=q->head;i<(q->head+q->num_items);i++) {
        printf("%.2f\n",q->items[(i%q->capacity)]);
    }
}

void queue_print_info(queue q) {
    int i;
    printf("capacity %d, num_items %d, head %d\n[",q->capacity, q->num_items, q->head);
    for (i=0; i< q->capacity; i++) {
        printf("%s%.2f",i==0 ? "" : ", ", q->items[i]);
    }
    printf("]\n");
}

int queue_size(queue q) {
    return q->num_items;
}

queue queue_free(queue q) {
    free(q->items);
    free(q);
    return q;
}
