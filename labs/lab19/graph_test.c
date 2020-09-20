#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "queue.h"
#include "graph.h"

int main(void) {
    graph G = graph_new(6);
    graph_add_edge(G,0,1);
    graph_add_edge(G,0,3);
    graph_add_edge(G,1,4);
    graph_add_edge(G,2,4);
    graph_add_edge(G,2,5);
    graph_add_edge(G,3,1);
    graph_add_edge(G,4,3);
    graph_add_edge(G,5,5);
    graph_dfs(G);
    print_graph(G);
    graph_free(G);
    return EXIT_SUCCESS;
}
