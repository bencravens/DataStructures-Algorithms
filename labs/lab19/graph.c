#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "graph.h"
#include "mylib.h"

typedef enum { UNVISITED, VISITED_SELF, VISITED_ALL } state_t;

struct vertexrec {
    int prev;
    int distance;
    int id;
    state_t state;
};

struct graphrec {
    int** edges;
    vertex* vertices;
    int size;
};

graph graph_new(int num_nodes) {
    int i;
    int j;
    graph G = emalloc(sizeof *G);
    G->size = num_nodes;
    /*initialize edges.
    edges is a pointer to a array of pointers, each which
    point to a row in a edges. So initially emalloc sizeof pointer 
    to array * num_rows
    */
    G->edges = emalloc(num_nodes * sizeof G->edges[0]);
    for (i=0;i<num_nodes;i++) {
        /*now we need to emalloc the length of row * size of 1 int entry*/
        G->edges[i] = emalloc(num_nodes * sizeof G->edges[0][0]);
        for(j=0;j<num_nodes;j++) {
            /*initialize edges as zeros*/
            G->edges[i][j] = 0;
        }
    }  
    /*initialize vertex...*/
    G->vertices = emalloc(num_nodes * sizeof G->vertices[0]);
    /*return G*/
    return G;
}

graph graph_free(graph G) {
    int i;
    
    /*free vertices*/
    for(i=0;i<G->size;i++) {
        free(G->vertices[i]);
    }
    free (G->vertices);

    /*free edge matrix*/
    for(i=0;i<G->size;i++) {
        free(G->edges[i]);
    }
    free(G->edges);

    /*now free G*/
    free(G);
    return G;
}

graph graph_add_edge(graph G, int u, int v) {
    G->edges[u][v]=1;
    return G;
}   

graph graph_add_2edge(graph G, int u, int v) {
    /*add edge to bidirectional graph*/
    /*add edge from u->v*/
    G->edges[u][v] = 1;
    /*add edge from v->u*/
    G->edges[v][u] = 1;
    return G;
}

void print_graph(graph G) {
    int i;
    int j;
    printf("adjacency list:\n");
    for (i=0;i<G->size;i++) {
        /*print adjacencies for ith node (ith row)*/
        printf("%d |",i);
        for (j=0;j<G->size;j++) {
            if (G->edges[i][j]==1) {
                printf(" %d",j);
            }
        }
        printf("\n");
    }
    printf("vertices:\n");
    printf("vertex distance pred\n");
    for (i=0;i<G->size;i++) {
        printf("%d     %d     %d\n",i,G->vertices[i]->distance,G->vertices[i]->prev);
    }
}

void graph_bfs(graph G, int source) {
    /*initialize queue*/
    int size;
    int i;
    queue Q = queue_new();     
    /*vertex ids for algorithm*/
    int u;
    int v;
    /*initialize vertices*/
    for (i=0;i<G->size;i++) {
        G->vertices[i] = emalloc(sizeof *G->vertices[i]);
        G->vertices[i]->prev = -1;
        G->vertices[i]->distance = -1;
        G->vertices[i]->id = i;
        G->vertices[i]->state = UNVISITED;
    }
    /*initialize source*/
    G->vertices[source]->state = VISITED_SELF;
    G->vertices[source]->distance = 0;
    enqueue(Q,source);
    size = queue_size(Q);
    printf("queue is size %d\n",size);
    while(size>0) {
        u = (int) dequeue(Q); /*dequeued vertex*/
        for (v=0;v<G->size;v++) {
            /*visit each node v adjacent to u which has not been visited already...*/
            if(G->edges[u][v]==1 && G->vertices[v]->state==UNVISITED) {
                G->vertices[v]->state = VISITED_SELF;
                G->vertices[v]->distance = G->vertices[u]->distance + 1;
                G->vertices[v]->prev = u;
                enqueue(Q,v);
            }
        }
        G->vertices[u]->state = VISITED_ALL;
        size = queue_size(Q);
    }
    free(Q);
} 
