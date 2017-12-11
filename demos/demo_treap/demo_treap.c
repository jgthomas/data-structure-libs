#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "tools/comparison.h"
#include "tools/printing.h"
#include "tools/get_input.h"
#include "data_structures/treap.h"


void print_commands(void);


int main()
{
        TreapNode *head = NULL;
        int nums[] = {10,4,23,20,6,21,67,9,2,100,1,55,12,3};

        treap_load_data(&head, nums, sizeof(nums), sizeof(nums[0]), less_than_int);

        char command[20];

        print_commands();

        while (1)
        {
                printf("Enter a command: ");
                fgets(command, sizeof(command), stdin);

                if (strncmp(command, "search", 5) == 0)
                {
                        char *data = "to find: ";
                        int new_int = get_int(data);
                        bool in_list = treap_search(&head, &new_int, equal_int, less_than_int);

                        if (in_list)
                        {
                            printf("found\n");
                        }
                        else
                        {
                            printf("not found\n");
                        }
                }
                else if (strncmp(command, "insert", 6) == 0)
                {
                        char *msg = "Number to insert";
                        int n = get_int(msg);
                        void *new_num = &n;
                        treap_insert(&head, new_num, less_than_int);
                }
                else if (strncmp(command, "inorder", 7) == 0)
                {
                        treap_in_order_print(head, print_int);
                        printf("\n");
                }
                else if (strncmp(command, "quit", 4) == 0)
                {
                        treap_delete(head);
                        break;
                }
                else
                {
                        print_commands();
                        continue;
                }
        }
}


void print_commands(void)
{
        printf("commands: search, insert, inorder, quit\n\n");
}
