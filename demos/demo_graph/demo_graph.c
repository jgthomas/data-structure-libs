#include <stdio.h>


enum {VERTICES = 5, NODE_BASE 65};


typedef struct node {
        int id;
        struct node *next;
}
VertexNode;


typedef struct vertex {
        int id;
        struct vertex *connections[VERTICES];
}
Vertex;


/**
 * Graph represented as an ADJACENCY MATRIX
 *
 *
 * Space complexity: O(n**2)
 *
 *
 * Time complexity by question
 *
 * 1. Is A connected to B: O(1)
 *
 * 2. List all vertices connected to A: O(V)
 *
 * 3. List all vertices: ???
 *
 * 4. List all edges: ???
 *
 * */
int adjacency[5][5] = {{0,1,1,0,0},
                       {1,0,1,1,0},
                       {1,1,0,1,1},
                       {0,1,1,0,1},
                       {0,0,1,1,0}}


/**
 * Graph represented as an EDGE LIST
 *
 * */
VertexNode *connections[VERTICES];
