#include <stdio.h>
#include <stdbool.h>
#include "demo_algorithms_shared.h"


void insertion_sort(int array[], int len);


int main(void)
{
        printf("\nInput array\n");
        print_array(ARRAY, LEN);
        
        insertion_sort(ARRAY, LEN);
        
        printf("\nSorted array\n");
        print_array(ARRAY, LEN);
        
        printf("\nINSERTION SORT\n");
        printf("Run time: O(n^2)\n");
        printf("Average operations: 2 * (n^2)/4\n");
        printf("Input n: %d\n", LEN);
        printf("Average operations for this n: %d\n", 2 * ((LEN*LEN)/4));
        printf("Actual operations for this input: %d\n", operations);
}


void insertion_sort(int array[], int len)
{
        for (int current = 1; current < len; current++)
        {
                int current_value = array[current];
                int previous = current - 1;

                while (previous >= 0 && less_than(current_value, array[previous]))
                {
                        swap(&array[previous+1], &array[previous]);
                        previous--;
                }
                
                printf("\nInserting %d (from index %d) into index %d\n\n",
                       current_value, current, previous+1);
                
                printf("New state of array\n");
                print_array(array, len);
        }
}
