#include <stdio.h>
#include <stdbool.h>
#include "tools/general.h"
#include "data_structures/binary_heap.h"
#include "heapsort.h"


void heap_sort(void *data,
               size_t data_size,
               size_t elem_size,
               bool (*compare)(void *x, void *y))
{
    BinHeap *heap = heapsort_init(data, data_size, elem_size, compare);
    
    int length = heap->len;
    
    while (heap->len > 0)
    {
        heap_swap(heap, elem_size);
        heap->len -= 1;
        sink_down(heap, elem_size, 0, compare);
    }
    
    heap_delete(heap);
}


BinHeap *heapsort_init(void *data,
                       size_t data_size,
                       size_t elem_size,
                       bool (*compare)(void *x, void *y))
{
        BinHeap *heap = make_heap();
        
        heap->len = data_size / elem_size;
        heap->array = data;
        
        heapify(heap, elem_size, compare);
        
        return heap;
}


void heap_swap(BinHeap *heap, size_t elem_size)
{
    void *first = heap->array + (elem_size * 0);
    void *last = heap->array + (elem_size * (heap->len - 1));
    swap(first, last, elem_size);
}
