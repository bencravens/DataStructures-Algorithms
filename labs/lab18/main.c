#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(void) {
    double item;
    int size;
    queue Q = queue_new();
    enqueue(Q, 1.4);
    enqueue(Q, 2.4);
    enqueue(Q, 3.4);
    enqueue(Q, 4.4);
    enqueue(Q, 5.4);
    queue_print(Q);
    size = queue_size(Q);
    printf("Q is size %d\n",size); 
    item = dequeue(Q);
    printf("popped %f.\n",item);
    queue_print(Q);
    size = queue_size(Q);
    printf("Q is size %d\n",size); 
    Q = queue_free(Q);
    return EXIT_SUCCESS;
}
