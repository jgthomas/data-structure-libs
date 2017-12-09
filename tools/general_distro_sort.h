#ifndef DISTRIBUTION_SORT_H
#define DISTRIBUTION_SORT_H

#include <stdbool.h>

typedef struct Record {
        int key;
        void *data;
}
Record;


void build_records(Record *record_array[],
                   int int_array[],
                   void *data_array,
                   size_t data_size,
                   size_t elem_size);

bool records_match_array(Record *record_array[],
                         void *answer_array,
                         size_t data_size,
                         size_t elem_size,
                         bool (*equal)(void *x, void *y));

void delete_records(Record *record_array[], int len);
void print_records(Record *record_array[], int len, void (*print)(void *x));

#endif
