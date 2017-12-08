/**
 * Algorithm for sorting small integers, either directly in an array
 * or as keys associated with some other data.
 *
 * */
#include <stdio.h>


/**
 * Simplest possible implementation for sorting array of integers
 *
 * */
void simple_counting_sort(int array[], int len, int max)
{
        int map[max];

        // initialise map
        for (int i = 0; i < max; i++)
        {
                map[i] = 0;
        }

        // build map of input array
        for (int i = 0; i < len; i++)
        {
                map[array[i]]++;
        }

        // overwrite input array based on map
        int index = 0;
        for (int i = 0; i < max; i++)
        {
                while (map[i] > 0)
                {
                        array[index] = i;
                        index++;
                        map[i]--;
                }
        }
}


