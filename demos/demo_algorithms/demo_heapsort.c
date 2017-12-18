#include <stdio.h>
#include "demo_algorithms_shared.h"


void heapsort(int heap[], int heap_len);
void heap_swap(int heap[], int heap_len);
void heap_swap(int heap[], int heap_len);
void bubble_up(int heap[], int child_index);
void sink_down(int heap[], int heap_len, int index);
void heapify(int heap[], int heap_len);
int left_child_idx(int pos);
int right_child_idx(int pos);
int parent_node(int pos);


int main(void)
{
        int heap[] = {5,4,66,7,1,23,9,109,12};
        int heap_len = sizeof(heap) / sizeof(heap[0]);
        
        printf("\nINPUT\n");
        print_array(heap, heap_len);
        printf("\n\n");
        
        heapsort(heap, heap_len);
        
        printf("\nSORTED\n");
        print_array(heap, heap_len);
        printf("\n\n");
        
        printf("HEAPSORT\n");
        printf("Complexity: O(n log n)\n");
}


void heapsort(int heap[], int heap_len)
{
        heapify(heap, heap_len);
        
        printf("heapify\n");
        print_array(heap, heap_len);
        printf("\n\n");
        
        int orig_len = heap_len;
        int len_min = 0;
    
        while (heap_len > 0)
        {
                heap_swap(heap, heap_len);
                
                printf("swap largest with last\n");
                print_array(heap, heap_len);
                printf("\n\nre-heapify len-1\n");
                
                heap_len -= 1;
                sink_down(heap, heap_len, 0);
                len_min++;
                
                print_array(heap, heap_len);
                printf("   ");
                print_partial_array(heap, orig_len-len_min, orig_len);
                printf("\n\n");
        }
}


void heap_swap(int heap[], int heap_len)
{
        swap(&heap[0], &heap[heap_len-1]);
}


void bubble_up(int heap[], int child_index)
{
        while (heap[child_index] > heap[parent_node(child_index)])
        {
                swap(&heap[child_index], &heap[parent_node(child_index)]);
                child_index = parent_node(child_index);
        }
}


void sink_down(int heap[], int heap_len, int index)
{
        // find largest child
        while (left_child_idx(index) < heap_len)
        {
                int swap_child = left_child_idx(index);

                if (right_child_idx(index) < heap_len)
                {
                        int right_child = right_child_idx(index);

                        if (heap[right_child] > heap[swap_child])
                        {
                                swap_child = right_child;
                        }
                }

                // swap with parent
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


void heapify(int heap[], int heap_len)
{
    for (int i = 0; i < heap_len; i++)
    {
        bubble_up(heap, i);
    }
}


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
