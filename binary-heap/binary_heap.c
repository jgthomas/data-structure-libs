#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "comparison.h"
#include "printing.h"
#include "binary_heap.h"


void print_array(void *array[],
                 size_t data_size,
                 size_t elem_size,
                 void (*print_ptr)(void *data));


int main(void)
{
        int array[] = {15,13,46,10};

        BinHeap *heap = heap_init();
        heap_add_data(heap, array, sizeof(array), sizeof(array[0]), less_than_int);
        //print_array(heap->array, sizeof(array), sizeof(array[0]), print_int);
        printf("first one: %d\n", *(int *)heap->array[sizeof(array[0]) * 0]);
        printf("second one: %d\n", *(int *)heap->array[sizeof(array[0]) * 1]);
        printf("third one: %d\n", *(int *)heap->array[sizeof(array[0]) * 2]);
        printf("fourth one: %d\n", *(int *)heap->array[sizeof(array[0]) * 3]);
        printf("heap len: %d\n", heap->len);
        heap_delete(heap);
}


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


void print_array(void *array[],
                 size_t data_size,
                 size_t elem_size,
                 void (*print_ptr)(void *data))
{
        int size = data_size/elem_size;

        for (int i = 0; i < size; i++)
        {
                print_ptr(array + i*elem_size);
                printf(" ");
        }
        printf("\n");
}


void swap(void *left, void *right, size_t elem_size)
{
        uint8_t temp[elem_size];
        memcpy(temp, left, elem_size);
        memcpy(left, right, elem_size);
        memcpy(right, temp, elem_size);
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


/**
 * index = position of newly inserted element in array
 *
 * */
void bubble_up(BinHeap *heap,
               size_t elem_size,
               int child_index,
               bool (*compare)(void *x, void *y))
{
        int parent_index = parent_node(child_index);

        while (compare(heap->array[elem_size * child_index], heap->array[elem_size * parent_index]))
        {
                swap(heap->array[elem_size * parent_index], heap->array[elem_size * child_index], elem_size);
                child_index = parent_index;
                parent_index = parent_node(parent_index);
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
