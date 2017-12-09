/**
 * Functions to compare various types, useful for passing as
 * function pointers to create some basic polymorphism.
 *
 * */
#include <string.h>
#include <stdbool.h>


/**
 * Integers
 *
 * */
bool less_than_int(void *first, void *second)
{
    return *(int *)first < *(int *)second;
}

bool more_than_int(void *first, void *second)
{
    return *(int *)first > *(int *)second;
}

bool equal_int(void *search, void *node_data)
{
        if (*(int *)search == *(int *)node_data)
        {
            return true;
        }
        return false;
}


/**
 * Chars
 *
 * */
bool less_than_char(void *first, void *second)
{
    return (int)*(char *)first < (int)*(char *)second;
}

bool more_than_char(void *first, void *second)
{
    return (int)*(char *)first > (int)*(char *)second;
}

bool equal_char(void *search, void *node_data)
{
        if (*(char *)search == *(char *)node_data)
        {
            return true;
        }
        return false;
}


/**
 * Strings
 *
 * */
bool less_than_string(void *first, void *second)
{
    if (strcmp(*(char **)first, *(char **)second) < 0)
    {
        return true;
    }
    return false;
}

bool more_than_string(void *first, void *second)
{
    if (strcmp(*(char **)second, *(char **)first) < 0)
    {
        return true;
    }
    return false;
}

bool equal_string(void *search, void *node_data)
{
        if (*(char **)search == *(char **)node_data)
        {
            return true;
        }
        return false;
}


/**
 * Sequences of elements
 *
 * */
bool matching_sequences(void *first,
                        void *second,
                        size_t data_size,
                        size_t elem_size,
                        bool (*equal)(void *x, void *y))
{
        int len = data_size/elem_size;

        for (int i = 0; i < len; i++)
        {
                void *first_data = first + elem_size * i;
                void *second_data = second + elem_size * i;

                if (!equal(first_data, second_data))
                {
                        return false;
                }
        }

        return true;
}
