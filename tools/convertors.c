#include <stdio.h>
#include "convertors.h"


enum {LOWER_BASE = 97, UPPER_BASE = 65};


/**
 * INTEGERS
 *
 * */
int convert_to_int(void *input, int (* fptr)(void *input))
{
        return fptr(input);
}

int string_to_int(void *input)
{
    char *string = *(char **)input;
    int n;
    sscanf(string, "%d", &n);
    return n;
}

int char_to_int(void *input)
{
        return (int)*(char *)input;
}

int float_to_int(void *input)
{
        return (int)*(float *)input;
}


/**
 * Convert lowercase letter, a-z, to equivalent index, 0-25
 *
 * */
int lower_char_to_index(void *input)
{
        char c = *(char *)input;
        return (int)(c - LOWER_BASE);
}

/**
 * Convert uppercase letter, a-z, to equivalent index, 0-25
 *
 * */
int upper_char_to_index(void *input)
{
        char c = *(char *)input;
        return (int)(c - UPPER_BASE);
}


/**
 * CHARS
 *
 * */
char convert_to_char(void *input, char (* fptr)(void *input))
{
        return fptr(input);
}

char int_to_char(void *input)
{
        return (char)*(int *)input;
}

char float_to_char(void *input)
{
        int from_float = (int)*(float *)input;
        return (char)from_float;
}

/**
 * Convert integer, 0-25, to equivalent lowercase character
 *
 * */
char index_to_lower_char(void *input)
{
        int index = *(int *)input;
        return (char)(index + LOWER_BASE);
}

/**
 * Convert integer, 0-25, to equivalent uppercase character
 *
 * */
char index_to_upper_char(void *input)
{
        int index = *(int *)input;
        return (char)(index + UPPER_BASE);
}
