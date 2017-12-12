#include <stdio.h>
#include <stdbool.h>
#include "demo_algorithms_shared.h"


void radix_sort(int array[], int len, int max);
void counting_sort(int array[], int len, int exp);


int main(void)
{
        printf("\nInput array\n");
        print_array(RADIX_ARRAY, RADIX_LEN);
        int max = find_max_integer(RADIX_ARRAY, RADIX_LEN) + 1;
        int digits = num_digits(max);
        
        radix_sort(RADIX_ARRAY, RADIX_LEN, max);
        
        printf("\nSorted array\n");
        print_array(RADIX_ARRAY, RADIX_LEN);
        
        printf("\nRADIX SORT\n");
        printf("Time complexity: O(d(n+b))\n");
        printf("Where 'd' is number of digits, 'n' the length of the input, and 'b' the base used\n");
        printf("Operations: digits * (5*n + 3*base)\n");
        printf("Input n: %d\n", RADIX_LEN);
        printf("Digits: %d\n", digits);
        printf("Base: %d\n", BUCKETS);
        printf("Operations for this input: %d\n", digits * (5*RADIX_LEN + 3*BUCKETS));
}


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

        printf("\nBuild map\n");
        
        // READ n input
        // WRITE b map
        for (int i = 0; i < len; i++)
        {
                digit = (array[i] / exp) % 10;
                map[digit]++;
        }
        
        print_array(map, BUCKETS);
        
        printf("Cumulative indicies\n");
        
        // WRITE b map
        for (int i = 1; i < BUCKETS; i++)
        {
                map[i] += map[i-1];
        }
        
        print_array(map, BUCKETS);

        // READ n input
        // WRITE b map
        // WRITE n output
        for (int i = len-1; i >= 0; i--)
        {
                digit = (array[i] / exp) % 10;
                map[digit]--;
                output[map[digit]] = array[i];
        }
        
        // WRITE n input
        // READ n output
        for (int i = 0; i < len; i++)
        {
                array[i] = output[i];
        }
        
        printf("Sorted by %ds\n", exp);
        print_array(array, len);
        printf("\n");
}
