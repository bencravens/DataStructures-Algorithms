#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "mylib.h"

int main(void) {
    double item;
    int size;
    queue Q = queue_new();
    enqueue(Q, 1.4);
    enqueue(Q, 2.4);
    enqueue(Q,3.14);
    queue_print(Q);
    item = dequeue(Q);
    printf("%f dequeued.\n",item);
    queue_print(Q);
    size = queue_size(Q);
    printf("queue is size %d\n",size);
    queue_free(Q);
    return EXIT_SUCCESS;
}
