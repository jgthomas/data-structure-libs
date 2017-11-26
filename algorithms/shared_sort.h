#ifndef SHARED_SORT_H
#define SHARED_SORT_H

#include <stdint.h>

void print_array(void *array,
                 size_t data_size,
                 size_t elem_size,
                 void (*print_ptr)(void *data));

#endif
