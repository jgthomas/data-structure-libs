#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "shared_sort.h"


void swap(void *left, void *right, size_t elem_size)
{
        uint8_t temp[elem_size];
        memcpy(temp, left, elem_size);
        memcpy(left, right, elem_size);
        memcpy(right, temp, elem_size);
}


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
