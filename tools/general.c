#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "general.h"


void swap(void *left, void *right, size_t elem_size)
{
        uint8_t temp[elem_size];
        memcpy(temp, left, elem_size);
        memcpy(left, right, elem_size);
        memcpy(right, temp, elem_size);
}
