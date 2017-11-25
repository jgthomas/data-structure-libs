/**
 * Functions to compare various types, useful for passing as
 * function pointers to create some basic polymorphism.
 *
 * 'less_than' functions can be inverted '!' greater than
 *
 * */
#include <string.h>
#include <stdbool.h>


bool less_than_int(void *first, void *second)
{
    return *(int *)first < *(int *)second;
}



bool less_than_char(void *first, void *second)
{
    return (int)*(char *)first < (int)*(char *)second;
}


bool less_than_string(void *first, void *second)
{
    if (strcmp(*(char **)first, *(char **)second) < 0)
    {
        return true;
    }
    
    return false;
}


bool equal_int(void *search, void *node_data)
{
        if (*(int *)search == *(int *)node_data)
        {
            return true;
        }
        
        return false;
}


bool equal_char(void *search, void *node_data)
{
        if (*(char *)search == *(char *)node_data)
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
