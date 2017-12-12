#include <stdio.h>
#include <stdbool.h>
#include "demo_algorithms_shared.h"


void counting_sort(int array[], int len, int max);


int main(void)
{
        printf("\nInput array\n");
        print_array(ARRAY, LEN);
        int max = find_max_integer(ARRAY, LEN) + 1;
        
        counting_sort(ARRAY, LEN, max);
        
        printf("\nSorted array\n");
        print_array(ARRAY, LEN);
        
        printf("\nCOUNTING SORT\n");
        printf("Time complexity: O(n+k)\n");
        printf("Where 'n' is length of input and 'k' the range of values\n");
        printf("Operations: 5n + 3k\n");
        printf("Input n: %d\n", LEN);
        printf("Input k: %d\n", max);
        printf("Operations for this input: %d\n", 5*LEN + 3*max);
}


void counting_sort(int array[], int len, int max)
{
        int map[max];
        int sorted[len];
        
        // init map
        for (int i = 0; i < max; i++)
        {
                map[i] = 0;
        }
        
        printf("\nBuild map\n");
        
        // READ n input
        // WRITE k map (including init above)
        for (int i = 0; i < len; i++)
        {
                map[array[i]]++;
        }
        
        print_array(map, max);

        // WRITE k map
        for (int i = 1; i < max; i++)
        {
                map[i] += map[i-1];
        }

        printf("\nCumulative indicies\n");
        
        // READ k map
        // READ n input
        // WRITE n output
        for (int i = len-1; i >= 0; i--)
        {
                map[array[i]]--;
                sorted[map[array[i]]] = array[i];
        }
        
        print_array(map, max);

        // READ n input
        // WRITE n output
        for (int i = 0; i < len; i++)
        {
                array[i] = sorted[i];
        }
}
