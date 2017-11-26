#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "comparison.h"
#include "printing.h"
#include "general.h"
#include "binary_heap.h"


BinHeap *heap_init(void)
{
        BinHeap *heap = malloc(sizeof(*heap));

        if (heap == NULL)
        {
                fprintf(stderr, "Failed to allocate memory for heap\n");
                exit(EXIT_FAILURE);
        }

        heap->len = 0;

        return heap;
}


void heap_delete(BinHeap *heap)
{
        free(heap);
}


void heap_print_array(BinHeap *heap, size_t elem_size, void (*print_ptr)(void *data))
{
        for (int i = 0; i < heap->len; i++)
        {
                print_ptr(heap->array[elem_size * i]);
                printf(" ");
        }
        printf("\n");
}


void heap_display(BinHeap *heap, size_t elem_size, void (*print_ptr)(void *data))
{
        heap_print_array(heap, elem_size, print_ptr);

        for (int i = 0; i < heap->len; i++)
        {
                if (left_child_idx(i) < heap->len)
                {
                        printf("parent node: ");
                        print_ptr(heap->array[elem_size * i]);
                        printf("\n");
                        printf("---> left child: ");
                        print_ptr(heap->array[elem_size * left_child_idx(i)]);
                        printf("\n");
                }

                if (right_child_idx(i) < heap->len)
                {
                        printf("---> right child: ");
                        print_ptr(heap->array[elem_size * right_child_idx(i)]);
                        printf("\n");
                }
        }
        printf("\n");
}


void heap_add_data(BinHeap *heap,
                   void *data,
                   size_t data_size,
                   size_t elem_size,
                   bool (*compare)(void *x, void *y))
{
        int length = data_size/elem_size;

        for (int i = 0; i < length; i++)
        {
                void *data_current = data + elem_size * i;
                heap_insert(heap, elem_size, data_current, compare);
        }
}


void heap_insert(BinHeap *heap,
                 size_t elem_size,
                 void *data,
                 bool (*compare)(void *x, void *y))
{
        heap->array[elem_size * heap->len] = data;
        bubble_up(heap, elem_size, heap->len, compare);
        heap->len += 1;
}


void bubble_up(BinHeap *heap,
               size_t elem_size,
               int child_index,
               bool (*compare)(void *x, void *y))
{
        void *child = heap->array[elem_size * child_index];
        void *parent = heap->array[elem_size * parent_node(child_index)];

        while (compare(child, parent))
        {
                swap(child, parent, elem_size);
                child_index = parent_node(child_index);
                child = heap->array[elem_size * child_index];
                parent = heap->array[elem_size * parent_node(child_index)];
        }
}


/**
 * Functions for locating position of parent and child nodes
 * assumes that the binary heap starts at index 0 of an array
 * 
 * */
int left_child_idx(int pos)
{
        return (pos*2) + 1;
}

int right_child_idx(int pos)
{
        return (pos*2) + 2;
}

int parent_node(int pos)
{
        return ((pos-1) / 2);
}
