#include <stdio.h>
#include "demo_algorithms_shared.h"


void merge(int array[], int low, int mid, int high, int level);
void merge_sort(int array[], int low, int high, int level);
void level_print(int level);


int main(void)
{
        int int_array[] = {71,3,5,8,12,90,33,1,5,76,23,4,55,89,9,15,61};
        int ARRAY_LEN = sizeof(int_array) / sizeof(int_array[0]);

        printf("\n");
        merge_sort(int_array, 0, ARRAY_LEN, 0);
        
        printf("\nMERGE SORT\n");
        printf("Time complexity: O(n log n)\n");
}


void merge(int array[], int low, int mid, int high, int level)
{
	    int left_len = mid - low;
	    int right_len = high - mid;
	    int left_part[left_len];
	    int right_part[right_len];

	    for (int i = low; i < mid; i++)
	    {
                left_part[i - low] = array[i];
	    }

	    for (int i = mid; i < high; i++)
	    {
                right_part[i - mid] = array[i];
	    }

	    int left_index = 0;
	    int right_index = 0;
	    int merged_index = low;

	    while (left_index < left_len && right_index < right_len)
	    {
                if (left_part[left_index] <= right_part[right_index])
                {
                        array[merged_index] = left_part[left_index];
                        left_index++;
                }
                else
                {
                        array[merged_index] = right_part[right_index];
                        right_index++;
                }
                merged_index++;
	    }

	    while (left_index < left_len)
	    {
                array[merged_index] = left_part[left_index];
                left_index++;
                merged_index++;
	    }

	    while (right_index < right_len)
	    {
                array[merged_index] = right_part[right_index];
                right_index++;
                merged_index++;
	    }
	    
	    level_print(level);
	    printf("MERGED: ");
	    print_partial_array(array, low, high);
        printf("\n");
}


void merge_sort(int array[], int low, int high, int level)
{
	if (low < high-1)
	{
		int mid = (low + high) / 2;
		
		level_print(level);
		printf("ARRAY: ");
		print_partial_array(array, low, high);
        printf("\n");

		merge_sort(array, low, mid, level+1);
		
		level_print(level);
		printf("LEFT: ");
		print_partial_array(array, low, mid);
        printf("\n");
		    
		merge_sort(array, mid, high, level+1);
		
		level_print(level);
		printf("RIGHT: ");
		print_partial_array(array, mid, high);
        printf("\n");

		merge(array, low, mid, high, level);
	}
}


void level_print(int level)
{
        for (int i = 0; i < level; i++)
        {
                printf("······");
        }
}
