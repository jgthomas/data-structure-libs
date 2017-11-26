#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "general.h"
#include "shared_sort.h"
#include "selection_sort.h"


void selection_sort(void *array,
                    size_t data_size,
                    size_t elem_size,
                    bool (*compare)(void *x, void *y))
{
        int length = data_size/elem_size;
        int start = 0;

        while (start < length)
        {
                void *first_unsorted = array + elem_size * start;
                void *lowest = first_unsorted;

                for (int i = start+1; i < length; i++)
                {
                        void *next = array + elem_size * i;

                        if (compare(next, lowest))
                        {
                                lowest = next;
                        }

                }
                start++;
                swap(first_unsorted, lowest, elem_size);
        }
}
