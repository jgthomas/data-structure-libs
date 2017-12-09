#include <stdlib.h>
#include "tools/general_distro_sort.h"
#include "radix_sort.h"


/**
 * Simple but stable version for sorting arrays of integers
 *
 * */
void radix_sort(int array[], int len, int max)
{
        for (int exp = 1; max/exp > 0; exp*=10)
        {
                counting_sort(array, len, exp);
        }
}

void counting_sort(int array[], int len, int exp)
{
        int map[BUCKETS] = {0};
        int output[len];
        int digit;

        // build map of nth significant digit
        for (int i = 0; i < len; i++)
        {
                digit = (array[i] / exp) % 10;
                map[digit]++;
        }

        // adjust for indicies for sorting to output
        for (int i = 1; i < BUCKETS; i++)
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



/**
 * Provides a stable sort of an array of key-data associations
 * 
 * The array is comprised of Record structs with two fields
 *     key  : the integer to sort
 *     data : pointer to the associated data
 *
 * */
void object_radix_sort(Record *record_array[], int len, int max)
{
        for (int exp = 1; max/exp > 0; exp*=10)
        {
                object_counting_sort(record_array, len, exp);
        }
}

void object_counting_sort(Record *record_array[], int len, int exp)
{
        int map[BUCKETS] = {0};
        Record *sorted_records[len];
        int digit;
        
        // build map of nth significant digit
        for (int i = 0; i < len; i++)
        {
                digit = (record_array[i]->key / exp) % 10;
                map[digit]++;
        }
        
        // adjust for indicies for sorting to output
        for (int i = 1; i < BUCKETS; i++)
        {
                map[i] += map[i-1];
        }
        
        // sort input based on nth significant digit
        for (int i = len-1; i >= 0; i--)
        {
                digit = (record_array[i]->key / exp) % 10;
                map[digit]--;
                sorted_records[map[digit]] = record_array[i];
        }
        
        // copy into original array
        for (int i = 0; i < len; i++)
        {
                record_array[i] = sorted_records[i];
        }
}
