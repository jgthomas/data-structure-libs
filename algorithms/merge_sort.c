#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "merge_sort.h"


void merge(void *data,
           size_t elem_size,
           int low,
           int mid,
           int high,
           bool (*less_than)(void *x, void *y))
{
        int left_len = mid - low;
	    int right_len = high - mid;

	    void *left = malloc(elem_size * left_len);

	    for (int i = low; i < mid; i++)
	    {
	            void *data_item = data + elem_size * i;
	            void *left_item = left + elem_size * (i - low);
	            memcpy(left_item, data_item, elem_size);
	    }

	    void *right = malloc(elem_size * right_len);

	    for (int i = mid; i < high; i++)
	    {
	            void *data_item = data + elem_size * i;
	            void *right_item = right + elem_size * (i - mid);
	            memcpy(right_item, data_item, elem_size);
	    }

	    int left_index = 0;
	    int right_index = 0;
	    int merged_index = low;

	    while (left_index < left_len && right_index < right_len)
	    {
	            void *left_item = left + elem_size * left_index;
	            void *right_item = right + elem_size * right_index;
	            void *merged_item = data + elem_size * merged_index;

	            if (less_than(left_item, right_item))
	            {
	                    memcpy(merged_item, left_item, elem_size);
	                    left_index++;
	            }
	            else
	            {
	                    memcpy(merged_item, right_item, elem_size);
	                    right_index++;
	            }
	            merged_index++;
	    }

	    while (left_index < left_len)
	    {
	            void *left_item = left + elem_size * left_index;
	            void *merged_item = data + elem_size * merged_index;
	            memcpy(merged_item, left_item, elem_size);
	            left_index++;
	            merged_index++;
	    }

	    while (right_index < right_len)
	    {
	            void *right_item = right + elem_size * right_index;
	            void *merged_item = data + elem_size * merged_index;
	            memcpy(merged_item, right_item, elem_size);
	            right_index++;
	            merged_index++;
	    }

	    free(left);
	    free(right);
}


void merge_sort(void *data,
                size_t elem_size,
                int low,
                int high,
                bool (*less_than)(void *x, void *y))
{
        if (low < high-1) 
	{
		    int mid = (low + high) / 2;

		    merge_sort(data, elem_size, low, mid, less_than);
		    merge_sort(data, elem_size, mid, high, less_than);

		    merge(data, elem_size, low, mid, high, less_than);
	}
}
