#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <stdbool.h>

int random_index(int low, int high);

int partition(void *data,
              size_t elem_size,
              int low,
              int high,
              bool (*less_than)(void *x, void *y));
              
void quicksort(void *data,
               size_t elem_size,
               int low,
               int high,
               bool (*less_than)(void *x, void *y));

#endif
