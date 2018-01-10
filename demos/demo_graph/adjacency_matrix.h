#include <stdio.h>
#include <stdbool.h>

extern int adjacency[VERTICES][VERTICES];

bool is_connected(int vertex_1, int vertex_2);
void vertex_report(int vertex);
void matrix_report(int first_vertex, int last_vertex);
void list_vertices(void);
void list_edges(void);
