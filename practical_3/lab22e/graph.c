#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "graph.h"
#include "mylib.h"
#include "queue.h"

typedef enum state {UNVISITED, VISITED_SELF, VISITED_DESCENDANTS} state_t;

struct graphrec {
    int** edges;
    int size;
    int* pred;
    int* distance;
    state_t* state;
    int* finish;
};

graph graph_new(int num_vertices) {
    int i,j;
    graph g = emalloc(sizeof *g);
    g->edges = emalloc(num_vertices * sizeof g->edges[0]);
    for (i=0; i<num_vertices; i++) {
        g->edges[i] = emalloc(num_vertices * sizeof g->edges[0][0]);
        for (j=0; j<num_vertices; j++) {
            g->edges[i][j] = 0;
        }
    }
    g->size = num_vertices;
    g->pred = emalloc(num_vertices * sizeof g->pred[0]);
    g->distance = emalloc(num_vertices * sizeof g->distance[0]);
    g->state = emalloc(num_vertices * sizeof g->state[0]);
    g->finish = emalloc(num_vertices * sizeof g->finish[0]);
    return g;
}

graph graph_free(graph g) {
    int i;
    for (i=0; i<g->size; i++) {
        free(g->edges[i]);
    }
    free(g->edges);
    free(g->pred);
    free(g->distance);
    free(g->state);
    free(g->finish);
    free(g);
    return g;
}

void graph_add_2edges(graph g, int u, int v) {
    g->edges[u][v] = 1;
    g->edges[v][u] = 1;
}

void graph_add_edge(graph g, int u, int v) {
    g->edges[u][v] = 1;
}

void graph_print_list(graph g) {
    int i;
    int j;
    int count;
    printf("adjacency list:\n");
    for (i=0; i<g->size; i++) {
        count=0;
        printf("%d | ",i);
        for (j=0; j<g->size; j++) {
            if (g->edges[i][j]==1) {
                if (count==0) {
                    printf("%d",j);
                } else {
                    printf(", %d",j);
                }
                count++;
            }
        }
        printf("\n");
    }
}

void graph_bfs(graph g, int source) {
    int i;
    int u,v;
    queue q = queue_new();
    for (i=0; i<g->size; i++) {
        g->state[i] = UNVISITED;
        g->distance[i] = -1;
        g->pred[i] = -1;
    }
    g->state[source] = VISITED_SELF;
    g->distance[source] = 0;
    enqueue(q,source);
    while (queue_size(q)>0) {
        u = (int)dequeue(q);
        for (v=0; v<g->size; v++) {
            if (g->edges[u][v]==1 && g->state[v]==UNVISITED) {
                g->state[v] = VISITED_SELF;
                g->distance[v] = 1 + g->distance[u];
                g->pred[v] = u;
                enqueue(q,v);
             }
        }
        g->state[u] = VISITED_DESCENDANTS;
    }
}

void graph_print_state(graph g) {
    int i;
    printf("vertex distance pred\n");
    for (i=0; i<g->size; i++) {
        printf("%5d%7d%6d\n",i,g->distance[i],g->pred[i]);
    }
}
