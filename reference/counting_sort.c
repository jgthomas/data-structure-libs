#include "counting_sort.h"


/**
 * COUNTING SORT
 *
 * input = [1,3,1,2,4]
 *
 * Build an intermediate array with k+1 slots,
 * where k = the maximum value in the input
 *
 * map = [0,0,0,0,0]
 *
 * For each element in the input, increment the counter
 * in the slot corresponding to that element's value.
 *
 * map = [0,2,1,1,1]
 *
 * Adjust map to reflect cumulative indicies
 *
 * map = [0,2,3,4,5]
 *
 * Build a sorted version of the array, based on the map of indicies
 * by walking back through the original array
 *
 * */
void counting_sort(int array[], int len, int max)
{
        int map[max];
        int sorted[len];

        // initialise intermediate array 
        for (int i = 0; i < max; i++)
        {
                map[i] = 0;
        }

        // build map of input array
        for (int i = 0; i < len; i++)
        {
                map[array[i]]++;
        }

        // adjust map to show output indicies
        for (int i = 1; i < max; i++)
        {
                map[i] += map[i-1];
        }

        // walk back through original array, building the sorted array
        for (int i = len-1; i >= 0; i--)
        {
                map[array[i]]--;
                sorted[map[array[i]]] = array[i];
        }

        // copy elements in sorted array into original array
        for (int i = 0; i < len; i++)
        {
                array[i] = sorted[i];
        }
}
