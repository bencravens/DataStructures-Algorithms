#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(void) {
    double item;
    int size;
    queue Q = queue_new();
    enqueue(Q, 1.4);
    enqueue(Q, 2.4);
    enqueue(Q,3.14);
    enqueue(Q,420.69);
    enqueue(Q,0.01);
    printf("printing queue\n");
    queue_print(Q);
    size = queue_size(Q);
    printf("queue is size %d\n",size);
    printf("dequeuing\n");
    item = dequeue(Q);
    printf("dq'd %f\n",item);
    queue_print(Q);
    printf("dequeuing\n");
    item = dequeue(Q);
    printf("dq'd %f\n",item);
    queue_print(Q);
    printf("dequeuing\n");
    item = dequeue(Q);
    printf("dq'd %f\n",item);
    queue_print(Q);
    queue_free(Q);
    return EXIT_SUCCESS;
}
