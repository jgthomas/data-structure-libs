#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "node.h"
#include "utilities.h"
#include "list_funcs.h"


void convert(Node **top, long long *decimal, int base);
long long to_int(char *string);
void print_conversion(Node *node, void(*fptr)(void *));


enum {MIN_BASE = 2, MAX_BASE = 16};

char BASE_MAP[16] = {'0', '1', '2', '3', '4', '5',
                     '6', '7', '8', '9', 'A', 'B',
                     'C', 'D', 'E', 'F'};


int main(int argc, char *argv[])
{
        if (argc == 1)
        {
                printf("usage: nbase_ll decimal [base]\n");
                printf("if base not specified, defaults to binary\n");
                printf("use base 0 to get all conversions\n");
                exit(1);
        }

        // default to binary
        int base = 2;

        // unless other base specified on command line
        if (argc == 3)
        {
                int base_opt = to_int(argv[2]);

                if (base_opt != 1 && base_opt <= MAX_BASE)
                {
                        base = base_opt;
                }
        }

        long long decimal = to_int(argv[1]);

        printf("\ninput number: %lld\n\n", decimal);

        // cycle through all bases if zero passed on command line
        if (base == 0)
        {
                for (int i = MIN_BASE; i <= MAX_BASE; i++)
                {
                        Node *top = NULL;
                        printf("base %d: ", i);
                        convert(&top, &decimal, i);
                        print_conversion(top, print_char);
                        delete_list(top);
                }
        }
        // otherwise convert the specified base
        else
        {
                Node *top = NULL;
                printf("base %d: ", base);
                convert(&top, &decimal, base);
                print_conversion(top, print_char);
                delete_list(top);
        }

        return 0;
}


void convert(Node **top, long long *decimal, int base)
{
        int index;
        int base_10 = *decimal;
        int char_size = sizeof(char);

        while (base_10 >= 1)
        {
                index = base_10 % base;
                push(top, &BASE_MAP[index], char_size);
                base_10 = base_10 / base;
        }
}


long long to_int(char *string)
{
    long long n;
    sscanf(string, "%lld", &n);
    return n;
}


void print_conversion(Node *node, void(*fptr)(void *))
{
        while (node != NULL)
        {
                (*fptr)(node->data);
                node = node->next;
        }
        printf("\n");
}
