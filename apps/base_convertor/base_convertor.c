/**
 * DESCRIPTION:
 *
 * Converts decimal numbers to other bases
 *
 *
 * DATA STRUCTURES:
 *
 * Uses a STACK implemented with a LINKED LIST
 *
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linked_list.h"
#include "convertors.h"
#include "printing.h"


void convert_to_base(long long decimal, int base);
void convert(Node **top, long long *decimal, int base);


enum {MIN_BASE = 2, MAX_BASE = 16};

char BASE_MAP[16] = {'0', '1', '2', '3', '4', '5',
                     '6', '7', '8', '9', 'A', 'B',
                     'C', 'D', 'E', 'F'};


int main(int argc, char *argv[])
{
        if (argc == 1)
        {
                printf("usage: base_convertor decimal [base]\n");
                printf("if base not specified, defaults to binary\n");
                printf("use base 0 to get all conversions\n");
                exit(1);
        }

        // default to binary
        int base = 2;

        // unless other base specified on command line
        if (argc == 3)
        {
                int base_opt = convert_to_int(&argv[2], string_to_int);

                if (base_opt != 1 && base_opt <= MAX_BASE)
                {
                        base = base_opt;
                }
        }

        long long decimal = convert_to_longlong(&argv[1], string_to_longlong);

        printf("\ninput number: %lld\n\n", decimal);

        // cycle through all bases if zero passed on command line
        if (base == 0)
        {
                for (int i = MIN_BASE; i <= MAX_BASE; i++)
                {
                        convert_to_base(decimal, i);
                }
        }
        // otherwise convert the specified base
        else
        {
                convert_to_base(decimal, base);
        }

        return 0;
}


void convert_to_base(long long decimal, int base)
{
        Node *top = NULL;
        printf("base %d: ", base);
        convert(&top, &decimal, base);
        print_values(top, print_char);
        delete_list(top);
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
