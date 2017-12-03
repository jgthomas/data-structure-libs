#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "tools/comparison.h"
#include "tools/printing.h"
#include "tools/get_input.h"
#include "data_structures/binary_search_tree.h"


int get_int(char *message);


int main()
{
        BinTreeNode *head = NULL;
        int nums[] = {10,4,23,20,6,21,67,9,2,100,1,55,68,12,3,89,1000};
        int num_len = sizeof(nums) / sizeof(nums[0]);

        int int_size = sizeof(int);

        for (int i = 0; i < num_len; i++)
        {
                insert(&head, &nums[i], int_size, less_than_int);
        }

        char command[20];

        printf("commands: search, print, quit\n\n");

        while (1)
        {
                printf("Enter a command: ");
                fgets(command, sizeof(command), stdin);

                if (strncmp(command, "search", 5) == 0)
                {
                        char *data = "to find: ";
                        int new_int = get_int(data);
                        bool in_list = search(&head, &new_int, equal_int, less_than_int);

                        if (in_list)
                        {
                            printf("found\n");
                        }
                        else
                        {
                            printf("not found\n");
                        }
                }
                else if (strncmp(command, "print", 5) == 0)
                {
                        int level = 0;
                        visualise_tree(head, level, print_int);
                }
                else if (strncmp(command, "quit", 4) == 0)
                {
                        delete_tree(head);
                        break;
                }
        }
}
