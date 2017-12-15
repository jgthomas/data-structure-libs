#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "tools/comparison.h"
#include "tools/printing.h"
#include "tools/get_input.h"
#include "data_structures/treap.h"


void print_commands(void)
{
        printf("commands: show, insert, inorder, preorder, postorder, quit\n\n");
}


int main(void)
{
        TreapNode *root = treap_init();

        int nums[] = {10,45,1,23,44,6,8,99,21,34,19,2};

        treap_load_data(&root, nums, sizeof(nums), sizeof(nums[0]), less_than_int);

        char command[20];

        print_commands();

        while (1)
        {
                printf("Enter a command: ");
                fgets(command, sizeof(command), stdin);

                if (strncmp(command, "show", 4) == 0)
                {
                        treap_visualise(root, 0, print_int);
                }
                else if (strncmp(command, "insert", 6) == 0)
                {
                        int n = get_int("Number to insert");
                        treap_insert(&root, &n, sizeof(n), less_than_int);
                }
                else if (strncmp(command, "inorder", 7) == 0)
                {
                        printf("\nin-order: ");
                        treap_in_order_print(root, print_int);
                        printf("\n\n");
                }
                else if (strncmp(command, "preorder", 8) == 0)
                {
                        printf("\npre-order: ");
                        treap_pre_order_print(root, print_int);
                        printf("\n\n");
                }
                else if (strncmp(command, "postorder", 9) == 0)
                {
                        printf("\npost-order: ");
                        treap_post_order_print(root, print_int);
                        printf("\n\n");
                }
                else if (strncmp(command, "quit", 4) == 0)
                {
                        treap_delete(root);
                        break;
                }
                else
                {
                        print_commands();
                        continue;
                }
        }
}
