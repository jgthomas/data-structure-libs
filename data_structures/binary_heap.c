#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "tools/comparison.h"
#include "tools/printing.h"
#include "tools/general.h"
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


void heap_delete_element(BinHeap *heap,
                         void *value,
                         size_t elem_size,
                         bool (*equal)(void *x, void *y),
                         bool (*compare)(void *x, void *y))
{
        int del_index = -1;

        for (int i = 0; i < heap->len; i++)
        {
                void *current = heap->array[elem_size * i];

                if (equal(current, value))
                {
                        del_index = i;
                        break;
                }
        }

        if (del_index == -1)
        {
                return;
        }

        heap->array[elem_size * del_index] = heap->array[elem_size * (heap->len -1)];
        sink_down(heap, elem_size, del_index, compare);
        heap->len -= 1;
}


void sink_down(BinHeap *heap,
               size_t elem_size,
               int index,
               bool (*compare)(void *x, void *y))
{
        while (left_child_idx(index) < heap->len)
        {
                int swap_child_idx = left_child_idx(index);
                void *swap_child = heap->array[elem_size * swap_child_idx];

                if (right_child_idx(index) < heap->len)
                {
                        void *right_child = heap->array[elem_size * right_child_idx(index)];

                        if (compare(right_child, swap_child))
                        {
                                swap_child_idx = right_child_idx(index);
                                swap_child = right_child;
                        }
                }

                void *current = heap->array[elem_size * index];

                if (compare(swap_child, current))
                {
                        swap(swap_child, current, elem_size);
                        index = swap_child_idx;
                }
                else
                {
                        index = heap->len;
                }

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
