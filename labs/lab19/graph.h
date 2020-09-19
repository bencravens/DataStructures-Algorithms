#ifndef GRAPH_H_
#define GRAPH_H_

#include <stdio.h>

struct graphrec;
struct vertexrec;
typedef struct graphrec *graph;
typedef struct vertexrec *vertex;

extern graph    graph_new(int capacity);
extern graph    graph_add_edge(graph G, int u, int v);
extern graph    graph_add_2edge(graph G, int u, int v);
extern void     print_graph(graph G);
extern graph    graph_free(graph G);
extern void     graph_bfs(graph G, int source);

#endif
