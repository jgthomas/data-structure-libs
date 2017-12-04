#include <stdio.h>
#include <stdlib.h>
#include "demo_algorithms_shared.h"


void linear_search(int array[], int target, int len);
void binary_search(int array[], int target, int len);


int main(void)
{
        int int_array[] = {1, 2, 3, 5, 6, 7, 8, 9, 12, 
                           14, 17, 19, 34, 56, 77, 89, 100,
                           123, 211, 345, 667, 789, 999, 1000,
                           5000, 6214, 7888, 8900, 10000};
        
        int len = sizeof(int_array) / sizeof(int_array[0]); 
                   
        printf("\nComparing linear and binary search\n\n");
        print_array(int_array, len);
        
        char *msg = "\nPick a number to see how long it takes to find";
        int to_find = get_int(msg);
        
        printf("\n\nBINARY search\n\n");
        binary_search(int_array, to_find, len);
        
        printf("\n\nLINEAR search\n\n");
        linear_search(int_array, to_find, len);
}


void linear_search(int array[], int target, int len)
{
        int count = 1;

        for (int i = 0; i < len; i++)
        {
                printf("Checking position %d\n", i);

                if (array[i] == target)
                {
                        if (count == 1)
                        {
                                printf("\nFound %d at position %d after %d operation\n", target, i, count);
                        }
                        else
                        {
                                printf("\nFound %d at position %d after %d operations\n", target, i, count);
                        }
                        return;
                }
                
                count++;
        }

        printf("\nNot found %d at any position after %d operations\n", target, count);
}


void binary_search(int array[], int target, int len)
{
        int low = 0;
        int high = len - 1;
        
        int count = 1;

        while (high >= low)
        {
                int mid = (high + low) / 2;
        
                printf("Checking position %d\n", mid);

                if (target < array[mid])
                {
                        high = mid - 1;
                }
                else if (target > array[mid])
                {
                        low = mid + 1;
                }
                else
                {
                        if (count == 1)
                        {
                                printf("\nFound %d at position %d after %d operation\n", target, mid, count);
                        }
                        else
                        {
                                printf("\nFound %d at position %d after %d operations\n", target, mid, count);
                        }
                        return;
                }
                
                count++;
        }

        printf("\nNot found %d at any position after %d operations\n", target, count);
}
