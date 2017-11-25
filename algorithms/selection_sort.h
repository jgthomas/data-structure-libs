#include <stdbool.h>

void selection_sort(void *array,
                    size_t data_size,
                    size_t elem_size,
                    bool (*compare)(void *x, void *y));
