#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "tools/comparison.h"
#include "tools/printing.h"
#include "tools/get_input.h"
#include "data_structures/binary_search_tree.h"


void print_commands(void)
{
        printf("\nCommands: ");
        printf("insert, search, show, inorder, preorder, postorder, ");
        printf("breadth, totnodes, maxdepth, maxval, minval, quit");
        printf("\n\n");
}


int main(void)
{
        BinTreeNode *root = NULL;

        int nums[] = {10,4,23,20,6,21,67,9,2,100,1,55,12,3};

        BST_load_data(&root, nums, sizeof(nums), sizeof(nums[0]), less_than_int);

        char command[20];

        print_commands();

        while (1)
        {
                printf("Enter a command: ");
                fgets(command, sizeof(command), stdin);

                if (strncmp(command, "insert", 6) == 0)
                {
                        char *msg = "Number to insert";
                        int n = get_int(msg);
                        BST_insert(&root, &n, sizeof(n), less_than_int);
                }
                else if (strncmp(command, "search", 6) == 0)
                {
                        char *data = "to find: ";
                        int new_int = get_int(data);

                        if (BST_search(&root, &new_int, equal_int, less_than_int))
                        {
                                printf("found\n");
                        }
                        else
                        {
                                printf("not found\n");
                        }
                }
                else if (strncmp(command, "show", 4) == 0)
                {
                        printf("\n");
                        BST_visualise_tree(root, 0, print_int);
                }
                else if (strncmp(command, "inorder", 7) == 0)
                {
                        printf("\nin-order: ");
                        BST_in_order_print(root, print_int);
                        printf("\n\n");
                }
                else if (strncmp(command, "preorder", 8) == 0)
                {
                        printf("\npre-order: ");
                        BST_pre_order_print(root, print_int);
                        printf("\n\n");
                }
                else if (strncmp(command, "postorder", 9) == 0)
                {
                        printf("\npost-order: ");
                        BST_post_order_print(root, print_int);
                        printf("\n\n");
                }
                else if (strncmp(command, "breadth", 7) == 0)
                {
                        printf("\nbreadth-first: ");
                        BST_breadth_first_print(root, print_int);
                        printf("\n\n");
                }
                else if (strncmp(command, "totnodes", 8) == 0)
                {
                        printf("\nTotal nodes: %d\n\n", BST_total_nodes(root));
                }
                else if (strncmp(command, "maxdepth", 8) == 0)
                {
                        printf("\nMax depth: %d\n\n", BST_max_depth(root));
                }
                else if (strncmp(command, "maxval", 6) == 0)
                {
                        printf("\nmax value: ");
                        print_int(BST_max_value(root, more_than_int));
                        printf("\n\n");
                }
                else if (strncmp(command, "minval", 6) == 0)
                {
                        printf("\nmin value: ");
                        print_int(BST_min_value(root, less_than_int));
                        printf("\n\n");
                }
                else if (strncmp(command, "del", 3) == 0)
                {
                        int n = get_int("Value to delete");
                        BST_delete_value(&root, &n, equal_int, less_than_int);
                }
                else if (strncmp(command, "quit", 4) == 0)
                {
                        BST_delete_tree(root);
                        break;
                }
                else
                {
                        print_commands();
                        continue;
                }
        }
}
