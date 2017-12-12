#include <stdio.h>
#include <stdbool.h>
#include "demo_algorithms_shared.h"


int ARRAY[] = {71,3,5,8,12,90,33,1,5,76,32,67,12,34,3,7,45,23,12,89};
int LEN = sizeof(ARRAY) / sizeof(ARRAY[0]);
int operations = 0;


void print_array(int array[], int len)
{
        for (int i = 0; i < len; i++)
        {
                printf("%d ", array[i]);
        }
        printf("\n");
}


int to_int(char *string)
{
    int n;
    sscanf(string, "%d", &n);
    return n;
}


int get_int(char *message)
{
    char input[100];
    printf("%s: ", message);
    fgets(input, sizeof(input), stdin);

    int n = to_int(input);

    return n;
}


void swap(int *a, int *b)
{
    operations++;

    int t = *a;
    *a = *b;
    *b = t;
}


bool less_than(int a, int b)
{
        operations++;

        if (a < b)
        {
                return true;
        }
        return false;
}


int find_max_integer(int array[], int len)
{
        int max = 0;

        if (len >= 1)
        {
                max = array[0];

                for (int i = 1; i < len; i++)
                {
                        if (array[i] > max)
                        {
                                max = array[i];
                        }
                }
        }

        return max;
}
