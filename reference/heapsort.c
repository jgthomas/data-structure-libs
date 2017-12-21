#include "shared_sort.h"
#include "heapsort.h"


/**
 * Turn the array into a max-heap
 * Swap the top element with the element at end of the array
 * Sink that swapped element down the heap, so next largest rises to top
 * Repeat until there are no more elements to sort
 * 
 * */
void heapsort(int heap[], int heap_len)
{
        // turn input into a heap
        heapify(heap, heap_len);

        while (heap_len > 0)
        {
                // swap largest element with last element
                swap(&heap[0], &heap[heap_len-1]);

                // reduce size of heap
                heap_len -= 1;

                // re-heapify to bring next largest element to top
                sink_down(heap, heap_len, 0);
        }
}


/**
 * Move an element UP the heap while it is larger than its parents
 * 
 * */
void bubble_up(int heap[], int child_index)
{
        while (heap[child_index] > heap[parent_node(child_index)])
        {
                swap(&heap[child_index], &heap[parent_node(child_index)]);
                child_index = parent_node(child_index);
        }
}


/**
 * Move an element DOWN the heap while it is smaller than its children
 * 
 * */
void sink_down(int heap[], int heap_len, int index)
{
        // check all valid children
        while (left_child_idx(index) < heap_len)
        {
                // find largest child
                int swap_child = left_child_idx(index);

                if (right_child_idx(index) < heap_len)
                {
                        int right_child = right_child_idx(index);

                        if (heap[right_child] > heap[swap_child])
                        {
                                swap_child = right_child;
                        }
                }

                // swap largest child with parent
                if (heap[swap_child] > heap[index])
                {
                        swap(&heap[swap_child], &heap[index]);
                        index = swap_child;
                }
                else
                {
                        index = heap_len;
                }
        }
}


/**
 * Turn the input array into a heap
 * 
 * */
void heapify(int heap[], int heap_len)
{
    for (int i = 0; i < heap_len; i++)
    {
        bubble_up(heap, i);
    }
}


/**
 * Calculate the position of children or parent nodes
 * given a position in the heap
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
