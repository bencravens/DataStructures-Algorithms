#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "graph.h"
#include "mylib.h"
#include "queue.h"

typedef enum state {UNVISITED, VISITED_SELF, VISITED_DESCENDANTS} state_t;

struct graphrec {
    int* pred;
    int* distance;
    state_t* state;
    int* finish;
    int** edges;
    int size;
};

static int step;

graph graph_new(int num_vertices) {
    int i;
    int j;
    graph g = emalloc(sizeof *g);
    g->size = num_vertices; 
    g->pred = emalloc(num_vertices * sizeof g->pred[0]);
    g->distance = emalloc(num_vertices * sizeof g->distance[0]);
    g->state = emalloc(num_vertices * sizeof g->state[0]);
    g->finish = emalloc(num_vertices * sizeof g->finish[0]);
    /*as the edge matrix is represented by a array of rows ( also arrays ) we
     * have to allocate memory to these iteratively*/
    g->edges = emalloc(num_vertices * sizeof g->edges[0]);
    for (i=0; i<num_vertices; i++) {
        g->edges[i] = emalloc(num_vertices * sizeof g->edges[0][0]);
    }
    /*now initialize edge matrix*/
    for (i=0; i<num_vertices; i++) {
        for (j=0; j<num_vertices; j++) {
            g->edges[i][j] = 0;
        }
    }
    return g;
}

graph graph_free(graph g) {
    int i;
    /*free edges matrix*/
    for (i=0;i < g->size;i++) {
        free(g->edges[i]);
    }
    free(g->edges);
    /*free vertex arrays*/
    free(g->finish);
    free(g->state);
    free(g->distance);
    free(g->pred);
    /*free graph itself*/
    free(g);
    return(g);
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
    int count=0;
    printf("adjacency list:\n");
    for (i=0;i < g->size;i++) {
        /*reset count*/
        count = 0;
        printf("%d | ",i);
        for (j=0;j < g->size;j++) {
            if (g->edges[i][j] == 1) {
                if (count == 0) {
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

void visit(graph g, int v) {
    int u;
    g->state[v] = VISITED_SELF;
    step++;
    g->distance[v] = step;
    for (u=0; u<g->size; u++) {
        if (g->state[u]==UNVISITED && g->edges[v][u] == 1) {
            g->pred[u] = v;
            visit(g,u);
        }
    }
    step++;
    g->state[v] = VISITED_DESCENDANTS;
    g->finish[v] = step;
}

void graph_dfs(graph g) {
    int i;
    for (i=0; i<g->size; i++) {
        g->state[i] = UNVISITED;
        g->pred[i] = -1;
    }
    step = 0;
    for (i=0; i<g->size; i++) {
        if (g->state[i]==UNVISITED) {
            visit(g,i);
        }
    }
}


void graph_print_state(graph g) {
    int i;
    printf("vertex distance pred finish\n");
    for (i=0; i<g->size; i++) {
        printf("%5d%7d%6d%6d\n",i,g->distance[i],g->pred[i],g->finish[i]);
    }
}
