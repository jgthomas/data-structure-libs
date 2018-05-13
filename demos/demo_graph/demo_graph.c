#include <stdio.h>
#include <string.h>
#include "tools/get_input.h"
#include "graph.h"
#include "adjacency_matrix.h"


void print_commands(void)
{
        printf("\nCommands: ");
        printf("vertices, edges, display, quit");
        printf("\n\n");
}


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
                print_commands();

                char command[20];

                while (1)
                {
                        printf("Enter a command: ");
                        fgets(command, sizeof(command), stdin);

                        if (strncmp(command, "vertices", 6) == 0)
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
                        else
                        {
                                print_commands();
                        }
                }
        }
}
