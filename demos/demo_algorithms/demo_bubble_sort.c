#include <stdio.h>
#include <stdbool.h>
#include "demo_algorithms_shared.h"


void bubble_sort(int array[], int len);


int main(void)
{
        printf("\nInput array\n");
        print_array(ARRAY, LEN);

        bubble_sort(ARRAY, LEN);

        printf("\nSorted array\n");
        print_array(ARRAY, LEN);

        printf("\nBUBBLE SORT\n");
        printf("Run time: O(n^2)\n");
        printf("Average operations: 2 * n(n-1)/2\n");
        printf("Input n: %d\n", LEN);
        printf("Average operations for this n: %d\n", 2 * (LEN*((LEN-1)/2)));
        printf("Actual operations for this input: %d\n", operations);
}


void bubble_sort(int array[], int len)
{
        bool swapped = true;

        while (swapped)
        {
                swapped = false;

                for (int i = 0; i < len - 1; i++)
                {
                        if (less_than(array[i+1], array[i]))
                        {
                                int temp = array[i+1];

                                swap(&array[i+1], &array[i]);
                                swapped = true;

                                printf("\nSwap %d (pos %d) with %d (pos %d)\n\n",
                                       temp, i+1, array[i+1], i); 
                                printf("Array now:\n");
                                print_array(array, len);
                        }
                }
        }
}
