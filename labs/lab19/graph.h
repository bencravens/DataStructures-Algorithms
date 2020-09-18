#ifndef GRAPH_H_
#define GRAPH_H_

#include <stdio.h>

typedef struct graphrec *graph;
typedef struct vertex *vertex;

extern graph    graph_new(int capacity);
extern graph    graph_add_edge(graph G, int u, int v);
extern graph    graph_add_2edge(graph G, int u, int v);
extern void     print_graph(graph G);

#endif
