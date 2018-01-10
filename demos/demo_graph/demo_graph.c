#include <stdio.h>
#include "graph.h"
#include "adjacency_matrix.h"


int main(void)
{
        printf("adjacency matrix\n");
        vertex_report(2);
        printf("\n");
        matrix_report(0, 4);
        list_vertices();
        list_edges();
}
