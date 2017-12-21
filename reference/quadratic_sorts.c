#include <stdbool.h>
#include "shared_sort.h"
#include "quadratic_sort.h"


/**
 * BUBBLE SORT with early exit
 *
 * Compare each element with its adjacent element,
 * if the adjacent element is larger, swap the elements.
 *
 * Continue until a full pass has been made with no swaps
 *
 * */
void bubble_sort(int array[], int len)
{
        // keep track of whether a swap has occurred
        bool swapped = true;

        while (swapped)
        {
                // assume no swaps until one occurs
                swapped = false;

                // compare adjacent elements
                for (int i = 0; i < len - 1; i++)
                {
                        // swap if out of order, and note a swap occurred
                        if (array[i+1] < array[i])
                        {
                                swap(&array[i+1], &array[i]);
                                swapped = true;
                        }
                }
        }
}


/**
 * INSERTION SORT
 *
 * Take the first element to be 'sorted', then for each
 * other element, insert it into the correct location 
 * relative to that first element.
 *
 * */
void insertion_sort(int array[], int len)
{
        // for each element in turn, from the second position onwards
        for (int current = 1; current < len; current++)
        {
                int current_value = array[current];
                int previous = current - 1;

                // compare with the previous element
                while (previous >= 0 && current_value < array[previous])
                {
                        // and swap if out of order
                        swap(&array[previous+1], &array[previous]);

                        // continue until it is correctly positioned relative to 
                        // the initial 'sorted' element and other elements
                        // that have already been sorted in the same way
                        previous--;
                }
        }
}


/**
 * SELECTION SORT
 *
 * Select the smallest element and place it at the start of the array
 * then find the smallest of the remaining elements and place in the
 * second position, and so on until all elements are sorted.
 *
 * */
void selection_sort(int array[], int len)
{
        // start position of the unsorted portion of array
        int start = 0;

        while (start < len)
        {
                // find the smallest element
                int low_index = start;

                for (int i = start+1; i < len; i++)
                {
                        if (array[i] < array[low_index])
                        {
                                low_index = i;
                        }
                }

                // swap the smallest element with the first unsorted element
                swap(&array[start], &array[low_index]);

                // increment location at which unsorted list starts
                start++;
        }
}
