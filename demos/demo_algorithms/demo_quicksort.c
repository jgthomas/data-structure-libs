#include <stdio.h>
#include "demo_algorithms_shared.h"


int partition(int array[], int low, int high);
void quicksort(int array[], int low, int high);
int middle_index(int low, int high);


int main()
{
        int int_array[] = {27,31,15,8,12,39,33,11,14,42,23,41,
                           25,13,16,15,16,18,2,33};
        
        int ARRAY_LEN = sizeof(int_array) / sizeof(int_array[0]);

        printf("\n");
        quicksort(int_array, 0, ARRAY_LEN);

        printf("Sorted array\n");
        print_array(int_array, ARRAY_LEN);
        
        printf("\nQUICKSORT\n");
        printf("Time complexity (Best) : O(n log n)\n");
        printf("Time complexity (Worst): O(n**2)\n");
}


void quicksort(int array[], int low, int high)
{
        if (low < high)
        {
                int pivot_index = partition(array, low, high);
                quicksort(array, low, pivot_index);
                quicksort(array, pivot_index+1, high);
        }
}


int partition(int array[], int low, int high)
{
        int p_index = middle_index(low, high);
        int pivot = array[p_index];
        int low_index = (low - 1);
        
        print_partial_array(array, low, high);
        printf("\n");
        
        printf("Pivot: %d\n", array[p_index]);
        
        swap(&array[low], &array[p_index]);

        for (int i = low; i < high; i++)
        {
                if (array[i] <= pivot)
                {
                        low_index++;
                        swap(&array[i], &array[low_index]);
                }
        }

        swap(&array[low_index], &array[low]);

        if (low == low_index)
        {
                printf("Base Case\n");
        }

        print_partial_array(array, low, low_index);
        printf("<·· %d ··> ", array[low_index]);

        print_partial_array(array, low_index+1, high);
        printf("\n\n");

        return low_index;
}


int middle_index(int low, int high)
{
        return low + (high - low) / 2;
}
