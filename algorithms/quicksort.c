#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "tools.h"
#include "quicksort.h"


void quicksort(void *data,
               size_t elem_size,
               int low,
               int high,
               bool (*less_than)(void *x, void *y))
{
        if (low < high)
        {
                int last_pivot = partition(data, elem_size, low, high, less_than);
                quicksort(data, elem_size, low, last_pivot, less_than);
                quicksort(data, elem_size, last_pivot+1, high, less_than);
        }
}


int partition(void *data,
              size_t elem_size,
              int low,
              int high,
              bool (*less_than)(void *x, void *y))
{
        int pivot_index = random_index(low, high);
        
        void *first = data + elem_size * low;
        void *pivot = data + elem_size * pivot_index;
        
        swap(first, pivot, elem_size);

        pivot = data + elem_size * low;
        
        int low_index = low;

        for (int i = low; i < high; i++)
        {
                void *tested = data + elem_size * i;
                
                if (less_than(tested, pivot))
                {
                        low_index++;
                        void *to_swap = data + elem_size * low_index;
                        swap(tested, to_swap, elem_size);
                        
                }
        }
        
        first = data + elem_size * low;
        void *just_used_pivot = data + elem_size * low_index;
        swap(first, just_used_pivot, elem_size);

        return low_index;
}


int random_index(int low, int high)
{
        srand(time(NULL));
        int r = rand() % (high - low) + low;
        return r;
}
