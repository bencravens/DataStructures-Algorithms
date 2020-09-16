#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/*define the queue struct*/
struct queue {
    double* items;
    int head;
    int capacity;
    int num_items;
};

void* emalloc(size_t n) {
    void* result = malloc(n);
    if (result == NULL) {
        fprintf(stderr, "malloc failed.\n");
    }
    return result;
}

queue queue_new() {
    /*initialize queue*/
    queue Q = emalloc(sizeof *Q);
    /*initialize head & tail at zero.*/
    Q->head = 0; 
    /*set default capacity to 5*/
    Q->capacity = 5;
    /*start with zero items*/
    Q->num_items = 0;
    /*now allocate memory to store items in array later*/
    Q->items = emalloc((Q->capacity) * sizeof Q->items[0]);
    /*done*/
    return Q;
}

void enqueue(queue Q, double item) {
    int index;
    if (Q->num_items == Q->capacity) {
        fprintf(stderr, "ERROR: cannot insert into a full queue\n");
        exit(EXIT_FAILURE);
    } else {
        index = (Q->head + Q->num_items) % Q->capacity;
        Q->items[index] = item;
        Q->num_items++;
        printf("%f queued successfully.\n",Q->items[index]);
    }
}

double dequeue(queue Q){
    double item;
    if (Q->num_items == 0) {
        fprintf(stderr, "ERROR: cannot dequeue an empty queue\n");
        exit(EXIT_FAILURE);
    } else {
        item = Q->items[Q->head];
        Q->head++;
        Q->num_items--;
        return item;
    }
}

void queue_print(queue Q) {
    int i;
    for (i=Q->head;i<(Q->head + Q->num_items);i++) {
        printf("%f\n",Q->items[i%Q->capacity]);
    }
}

int queue_size(queue Q) {
    return Q->num_items;
}

queue queue_free(queue Q) {
    free(Q->items);
    free(Q);
    return NULL;
}
