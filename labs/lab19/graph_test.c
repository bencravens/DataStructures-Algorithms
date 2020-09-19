#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "queue.h"
#include "graph.h"

int main(void) {
    graph G = graph_new(8);
    graph_add_2edge(G,0,4);
    graph_add_2edge(G,0,1);
    graph_add_2edge(G,1,5);
    graph_add_2edge(G,5,2);
    graph_add_2edge(G,5,6);
    graph_add_2edge(G,6,2);
    graph_add_2edge(G,6,3);
    graph_add_2edge(G,6,7);
    graph_add_2edge(G,3,2);
    graph_add_2edge(G,3,7);
    graph_bfs(G,1);
    print_graph(G);
    graph_free(G);
    return EXIT_SUCCESS;
}
