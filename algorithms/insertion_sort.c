#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "tools/general.h"
#include "insertion_sort.h"


void insertion_sort(void *array,
                    size_t data_size,
                    size_t elem_size,
                    bool (*compare)(void *x, void *y))
{
        int len = data_size/elem_size;

        for (int current = 1; current < len; current++)
        {
                int previous = current - 1;
                void *current_value = array + elem_size * current;
                void *previous_value = array + elem_size * previous;

                while (previous >= 0 && compare(current_value, previous_value))
                {
                        swap(current_value, previous_value, elem_size);
                        previous--;
                        current--;

                        if (previous >= 0)
                        {
                                current_value = array + elem_size * current;
                                previous_value = array + elem_size * previous;
                        }
                }
        }
}
