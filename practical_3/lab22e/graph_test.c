#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "queue.h"
#include "graph.h"

int main(void) {
    graph G = graph_new(8);
    graph_add_2edges(G,4,0);
    graph_add_2edges(G,0,1);
    graph_add_2edges(G,1,5);
    graph_add_2edges(G,5,2);
    graph_add_2edges(G,5,6);
    graph_add_2edges(G,6,2);
    graph_add_2edges(G,6,3);
    graph_add_2edges(G,6,7);
    graph_add_2edges(G,2,3);
    graph_add_2edges(G,3,7);
    graph_print_list(G);
    graph_free(G);
    return EXIT_SUCCESS;
}
