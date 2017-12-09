#ifndef COMPARISON_H
#define COMPARISON_H

#include <stdbool.h>

bool less_than_int(void *first, void *second);
bool more_than_int(void *first, void *second);
bool equal_int(void *search, void *node_data);
bool less_than_char(void *first, void *second);
bool more_than_char(void *first, void *second);
bool equal_char(void *search, void *node_data);
bool less_than_string(void *first, void *second);
bool more_than_string(void *first, void *second);
bool equal_string(void *search, void *node_data);

bool matching_sequences(void *first,
                        void *second,
                        size_t data_size,
                        size_t elem_size,
                        bool (*equal)(void *x, void *y));

#endif
