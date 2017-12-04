#include <stdio.h>
#include "demo_algorithms_shared.h"


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
