/**
 * Convenience functions for getting data from stdin
 *
 * */
#include <stdio.h>
#include <string.h>


int get_int(char *message)
{
        int n;
        char input[100];
        printf("%s: ", message);
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%d", &n);
        return n;
}


void get_string(char *message, char *target, int buffer_size)
{
        char buffer[buffer_size + 1];
        printf("%s: ", message);
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        strcpy(target, buffer);
}
