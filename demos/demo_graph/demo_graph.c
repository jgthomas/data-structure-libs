#include <stdio.h>
#include <string.h>
#include "tools/get_input.h"
#include "graph.h"
#include "adjacency_matrix.h"


int main(void)
{
        int choice = 0;

        printf("\nPick an Implementation\n\n");

        while (choice < 1 || choice > 2)
        {
                choice = get_int("(1) Adjacency Matrix or (2) Edge list");
        }

        if (choice == 1)
        {
                printf("\nAdjacency Matrix\n\n");

                char command[20];

                while (1)
                {
                        printf("Enter a command: ");
                        fgets(command, sizeof(command), stdin);

                        if (strncmp(command, "vertex", 6) == 0)
                        {
                                printf("\n");
                                list_vertices();
                                printf("\n");
                        }
                        else if (strncmp(command, "edges", 5) == 0)
                        {
                                printf("\n");
                                list_edges();
                                printf("\n");
                        }
                        else if (strncmp(command, "display", 7) == 0)
                        {
                                print_matrix();
                        }
                        else if (strncmp(command, "quit", 4) == 0)
                        {
                                break;
                        }
                }
        }
}
