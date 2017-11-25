#include <stdint.h>

void swap(void *left, void *right, size_t elem_size);
void print_array(void *array,
                 size_t data_size,
                 size_t elem_size,
                 void (*print_ptr)(void *data));
