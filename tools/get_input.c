/**
 * Convenience functions for getting data from stdin
 *
 * */
#include <stdio.h>


int get_int(char *message)
{
        int n;
        char input[100];
        printf("%s", message);
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%d", &n);
        return n;
}
