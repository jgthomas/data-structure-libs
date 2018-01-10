#include <stdbool.h>
#include "graph.h"
#include "adjacency_matrix.h"


/**
 * Graph represented as an ADJACENCY MATRIX
 *
 * G(V,E)
 * V = {0,1,2...n}
 * E = {(0,1),(0,2)...(n,n)}
 *
 *
 * Good for dense graphs
 *
 * Space complexity: O(|V|**2)
 *
 * Time complexity by question
 *
 * 1. Is A connected to B: O(1)
 * 2. List all vertices connected to A: O(|V|)
 * 3. List all vertices: O(|V|)?
 * 4. List all edges: O(|V|**2)?
 *
 * */
int adjacency[VERTICES][VERTICES] = {{0,1,1,0,0},
                                     {1,0,1,1,0},
                                     {1,1,0,1,1},
                                     {0,1,1,0,1},
                                     {0,0,1,1,1}};
                                     
                       
bool is_connected(int vertex_1, int vertex_2)
{
        if (adjacency[vertex_1][vertex_2])
        {
                return true;
        }
        return false;
}


void vertex_report(int vertex)
{
        for (int i = 0; i < VERTICES; i++)
        {
                if (is_connected(vertex, i))
                {
                        printf("%d is connected to %d\n", vertex, i);
                }
                else
                {
                        printf("%d is NOT connected to %d\n", vertex, i);
                }
        }
}


void matrix_report(int first_vertex, int last_vertex)
{
        for (int i = first_vertex; i <= last_vertex; i++)
        {
                vertex_report(i);
        }
}


void list_vertices(void)
{
        printf("vertices: {");
        
        for (int i = 0; i < VERTICES; i++)
        {
               printf("%d", i);
               
               if (i < VERTICES-1)
               {
                       printf(",");
               }
        }
        
        printf("}\n");
}


void list_edges(void)
{
        printf("edges: {");
        
        for (int i = 0; i < VERTICES; i++)
        {
                for (int j = 0; j < VERTICES; j++)
                {
                        if (adjacency[i][j])
                        {
                                printf("(%d,%d)", i, j);
                                
                                if (i < VERTICES-1)
                                {
                                        printf(",");
                                }
                                else if (j < VERTICES-1)
                                {
                                        printf(",");
                                }
                        }
                }
        }
        
        printf("}\n");
}
