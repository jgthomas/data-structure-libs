#include <stdio.h>
#include <stdbool.h>


int linear_search(void *array,
                   void *target,
                   size_t data_size,
                   size_t elem_size,
                   bool (*equal)(void *x, void *y))
{
        const int len = data_size/elem_size;

        for (int i = 0; i < len; i++)
        {
                void *current_focus = array + elem_size * i;

                if (equal(target, current_focus))
                {
                        return i;
                }
        }
        
        return -1;
}
