#include <stdio.h>
#include "radix_sort.h"


/**
 * RADIX SORT
 *
 * Perform counting sort first by units, then tens, then hundreds, etc.
 *
 * */
void radix_sort(int array[], int len, int max)
{
        for (int exp = 1; max/exp > 0; exp*=10)
        {
                // perform counting sort for each place value
                count_sort(array, len, exp);
        }
}


void count_sort(int array[], int len, int exp)
{
        int map[10] = {0};
        int output[len];
        int digit;

        // build map of nth significant digit
        for (int i = 0; i < len; i++)
        {
                digit = (array[i] / exp) % 10;
                map[digit]++;
        }

        // adjust for indicies for sorting to output
        for (int i = 1; i < 10; i++)
        {
                map[i] += map[i-1];
        }

        // sort input based on nth significant digit
        for (int i = len-1; i >= 0; i--)
        {
                digit = (array[i] / exp) % 10;
                map[digit]--;
                output[map[digit]] = array[i];
        }

        // copy into original array
        for (int i = 0; i < len; i++)
        {
                array[i] = output[i];
        }
}
