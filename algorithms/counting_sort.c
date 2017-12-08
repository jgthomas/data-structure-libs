/**
 * Algorithm for sorting small integers, either directly in an array
 * or as keys associated with some other data.
 *
 * */
#include <stdio.h>
#include "distribution_sort.h"
#include "counting_sort.h"


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


/**
 * Stable version of algorithm that maintains the position
 * of equal elements, although not strictly required for integers
 *
 * */
void counting_sort(int array[], int len, int max)
{
        int map[max];
        int sorted[len];

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

        // adjust map to show output indicies
        for (int i = 1; i < max; i++)
        {
                map[i] += map[i-1];
        }

        // walk back through original array, buliding sorted
        // maintains stable ordering
        for (int i = len-1; i >= 0; i--)
        {
                map[array[i]]--;
                sorted[map[array[i]]] = array[i];
        }

        // copy sorted into original array
        for (int i = 0; i < len; i++)
        {
                array[i] = sorted[i];
        }
}


/**
 * Provides a stable sort of an array of key-data associations.
 *
 * The array is comprised of Record structs with two fields
 *     key  : the integer to sort
 *     data : pointer to the associated data
 *
 * */
void object_counting_sort(Record *record_array[], int len, int max)
{
        int map[max];
        Record *sorted_records[len];

        // initialise map
        for (int i = 0; i < max; i++)
        {
                map[i] = 0;
        }

        // build map of input array
        for (int i = 0; i < len; i++)
        {
                map[record_array[i]->key]++;
        }

        // adjust map to show output indicies
        for (int i = 1; i < max; i++)
        {
                map[i] += map[i-1];
        }

        // walk back through original array, buliding sorted
        for (int i = len-1; i >= 0; i--)
        {
                map[record_array[i]->key]--;
                sorted_records[map[record_array[i]->key]] = record_array[i];
        }

        // copy sorted into original array
        for (int i = 0; i < len; i++)
        {
                record_array[i] = sorted_records[i];
        }
}
