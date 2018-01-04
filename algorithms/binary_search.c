#include <stdio.h>
#include <stdbool.h>
#include "binary_search.h"


int binary_search(void *array,
                  void *target,
                  size_t data_size,
                  size_t elem_size,
                  bool (*is_larger)(void *x, void *y))
{
        int low = 0;
        int high = (data_size/elem_size) - 1;

        int not_found = -1;

        while (high >= low)
        {
                int mid = (high + low) / 2;
                void *current_focus = array + elem_size * mid;

                if (is_larger(current_focus, target))
                {
                        high = mid - 1;
                }
                else if (is_larger(target, current_focus))
                {
                        low = mid + 1;
                }
                else
                {
                        return mid;
                }
        }

        return not_found;
}
