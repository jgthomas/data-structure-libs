#include <stdio.h>


void swap(int *a, int *b)
{
        int t = *a;
        *a = *b;
        *b = t;
}


void print_array(int array[], int len)
{
        for (int i = 0; i < len; i++)
        {
                printf("%d ", array[i]);
        }
}


int find_max(int array[], int len)
{

        int max = array[0];

        for (int i = 1; i < len; i++)
        {
            if (array[i] > max)
            {
                max = array[i];
            }
        }

        return max;
}
