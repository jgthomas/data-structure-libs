#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "general.h"


void swap(void *left, void *right, size_t elem_size)
{
        uint8_t temp[elem_size];
        memcpy(temp, left, elem_size);
        memcpy(left, right, elem_size);
        memcpy(right, temp, elem_size);
}


void copy(void *target, void *data, size_t elem_size)
{
        memcpy(target, data, elem_size);
}


int find_max_integer(int array[], int len)
{
        int max = 0;

        if (len >= 1)
        {
                max = array[0];

                for (int i = 1; i < len; i++)
                {
                        if (array[i] > max)
                        {
                                max = array[i];
                        }
                }
        }

        return max;
}
