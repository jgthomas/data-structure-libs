#include <stdio.h>


void merge(int array[], int low, int mid, int high)
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
}


void merge_sort(int array[], int low, int high)
{
	    if (low < high-1)
	    {
	    	    int mid = (low + high) / 2;

	    	    merge_sort(array, low, mid);
	    	    merge_sort(array, mid, high);

	    	    merge(array, low, mid, high);
	    }
}
