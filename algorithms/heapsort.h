#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <stdio.h>
#include <stdbool.h>
#include "data_structures/binary_heap.h"

void heapsort(void *data,
              size_t data_size,
              size_t elem_size,
              bool (*compare)(void *x, void *y));
               
BinHeap *heapsort_init(void *data,
                       size_t data_size,
                       size_t elem_size,
                       bool (*compare)(void *x, void *y));

void heap_swap(BinHeap *heap, size_t elem_size);

#endif
