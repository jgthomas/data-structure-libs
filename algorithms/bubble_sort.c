#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "shared_sort.h"
#include "bubble_sort.h"


void bubble_sort(void *array,
                 size_t data_size,
                 size_t elem_size,
                 bool (*compare)(void *x, void *y))
{
        size_t length = data_size/elem_size;
        int unsorted = length - 1;

        while (unsorted > 0)
        {
                int last_swap = 0;

                for (int j = 0; j < unsorted; j++)
                {
                        void *left = array + elem_size * j;
                        void *right = array + elem_size * (j+1);

                        if (compare(right, left))
                        {
                                swap(left, right, elem_size);
                                last_swap = j;
                        };
                }
                unsorted = last_swap;
        }
}
