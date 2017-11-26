#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "shared_sort.h"


void print_array(void *array,
                 size_t data_size,
                 size_t elem_size,
                 void (*print_ptr)(void *data))
{
        int size = data_size/elem_size;

        for (int i = 0; i < size; i++)
        {
                print_ptr(array + i*elem_size);
                printf(" ");
        }
        printf("\n");
}
