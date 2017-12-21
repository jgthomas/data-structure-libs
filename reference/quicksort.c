#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "shared_sort.h"
#include "quicksort.h"


/**
 * QUICKSORT
 *
 * Recursively divide the array in half,
 * select a pivot and sort lower and higher 
 * elements to either side of the pivot
 *
 * */
void quicksort(int array[], int low, int high)
{
        // base case: array of one element
        if (low < high)
        {
                int last_pivot = partition(array, low, high);
                quicksort(array, low, last_pivot);
                quicksort(array, last_pivot+1, high);
        }
}


/**
 * Divide the array around the selected pivot
 *
 * */
int partition(int array[], int low, int high)
{
        // select pivot
        int pivot_index = random_index(low, high);
        int pivot = array[pivot_index];

        // swap pivot and first element so everything works the same
        swap(&array[low], &array[pivot_index]);

        // keep track of the border between lower and higher elements
        int low_index = (low - 1);

        // move elements less than the pivot to the left, larger elements to the right
        for (int i = low; i < high; i++)
        {
                if (array[i] <= pivot)
                {
                        low_index++;
                        swap(&array[i], &array[low_index]);
                }
        }

        // swap pivot with the last smaller element, placing it between the two groups
        swap(&array[low_index], &array[low]);

        return low_index;
}


/**
 * Select random pivot to avoid worst-case O(n^2)
 *
 * */
int random_index(int low, int high)
{
        srand(time(NULL));
        return rand() % (high - low) + low;
}
