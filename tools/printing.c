/**
 * Functions to print various types
 *
 * */
#include <stdio.h>
#include "printing.h"


/**
 * Cast void pointer, n, to integer pointer
 * ===> (int *)n = int *n
 * 
 * Dereference to get value (i.e. the int)
 * ===> *(int *) = n (i.e. an int)
 * 
 * printf then uses "%d" format to display integer
 * 
 * */
void print_int(void *n)
{
        printf("%d", *(int *)n);
}


/**
 * Cast void pointer, f, to float pointer
 * ===> (float *)f = float *f
 * 
 * Dereference to get value (i.e. the float)
 * ===> *(float *) = f (i.e. a float)
 * 
 * printf then uses "%f" format to display float
 * 
 * */
void print_float(void *f)
{
        printf("%f", *(float *)f);
}


/**
 * Cast void pointer, c,  to char pointer
 * ===> (char *)c = char *c
 * 
 * Dereference to get value (i.e. the char)
 * ===> *(char *) = c (i.e. a char)
 * 
 * printf then uses "%c" format to display char
 * 
 * */
void print_char(void *c)
{
        printf("%c", *(char *)c);
}


/**
 * Cast void pointer, s, to pointer-to-a-char-pointer
 * ===> (char **)s = char **s
 * 
 * Dereference to get value (i.e. the char pointer)
 * ===> *(char **) = char*
 * 
 * printf then uses "%s" format for string from char pointer
 * 
 * */
void print_string(void *s)
{
        printf("%s", *(char **)s);
}


/**
 * Print values, of any type, stored in an adjacent sequence of
 * memory loctations.
 *
 * Requires a type-specific function pointer.
 *
 * */
void print_sequence(void *sequence,
                    size_t data_size,
                    size_t elem_size,
                    void (*print)(void *data))
{
        int size = data_size/elem_size;

        for (int i = 0; i < size; i++)
        {
                print(sequence + elem_size * i);
                printf(" ");
        }
        printf("\n");
}


/**
 * Print values, of any type, stored in a sequence
 *
 * */
void print_sequence(void *data,
                    size_t data_size,
                    size_t elem_size,
                    void (*print)(void *x))
{
        int len = data_size/elem_size;

        for (int i = 0; i < len; i++)
        {
                print(data + elem_size * i);
                printf(" ");
        }
        printf("\n");
}
