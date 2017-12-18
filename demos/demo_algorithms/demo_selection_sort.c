#include <stdio.h>
#include <stdbool.h>
#include "demo_algorithms_shared.h"


void selection_sort(int array[], int len);
int get_low_index(int array[], int start, int end);


int main(void)
{
        printf("\nInput array\n");
        print_array(ARRAY, LEN);
        printf("\n");

        selection_sort(ARRAY, LEN);
        
        printf("\nSorted array\n");
        print_array(ARRAY, LEN);
        
        printf("\n\nSELECTION SORT\n");
        printf("Run time: O(n^2)\n");
        printf("Average operations: (n-1) + n(n-1)/2\n");
        printf("Input n: %d\n", LEN);
        printf("Average operations for this n: %d\n", (LEN-1) + (LEN*((LEN-1)/2)));
        printf("Actual operations for this input: %d\n\n", operations);
}


void selection_sort(int array[], int len)
{
        int start = 0;

        while (start < len)
        {
                int low_index = get_low_index(array, start, len);
                swap(&array[start], &array[low_index]);
                
                printf("\nSwapped element %d (%d) with element %d (%d)\n\n", 
                       low_index, array[start], start, array[low_index]);
                printf("New state of array\n");
                print_array(array, len);
                printf("\n");
                
                start++;
        }
}


int get_low_index(int array[], int start, int end)
{
        int low_index = start;
        int low_value = array[start];

        for (int i = start+1; i < end; i++)
        {
                if (less_than(array[i], low_value))
                {
                        low_value = array[i];
                        low_index = i;
                }
        }
        return low_index;
}
