#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "general_distro_sort.h"


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


void print_record(Record *record, void (*print)(void *x))
{
        print(record->data);
        printf(" %d   ", record->key);
}


void print_records(Record *record_array[], int len, void (*print)(void *x))
{
        for (int i = 0; i < len; i++)
        {
                print_record(record_array[i], print);
        }
        printf("\n");
}


bool records_match_array(Record *record_array[],
                         void *answer_array,
                         size_t data_size,
                         size_t elem_size,
                         bool (*equal)(void *x, void *y))
{
        int len = data_size/elem_size;

        for (int i = 0; i < len; i++)
        {
                void *next_elem = answer_array + elem_size * i;

                if (!equal(next_elem, record_array[i]->data))
                {
                        return false;
                }
        }
        return true;
}
