#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "distribution_sort.h"


void build_records(Record *record_array[],
                   int int_array[],
                   void *data_array,
                   size_t data_size,
                   size_t elem_size)
{
        int len = data_size/elem_size;
        
        for (int i = 0; i < len; i++)
        {
                record_array[i] = malloc(sizeof(Record));
                record_array[i]->key = int_array[i];
                record_array[i]->data = data_array + elem_size * i;
        }
}


void delete_records(Record *record_array[], int len)
{
        for (int i = 0; i < len; i++)
        {
                free(record_array[i]);
        }
}


void print_records(Record *record_array[], int len, void (*print)(void *x))
{
        for (int i = 0; i < len; i++)
        {
                print(record_array[i]->data);
                printf(" %d   ", record_array[i]->key);
        }
        printf("\n");
}
