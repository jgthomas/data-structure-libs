#ifndef MERGE_SORT_H
#define MERGE_SORT_H

void merge_sort(void *data,
                size_t elem_size,
                int low,
                int high,
                bool (*less_than)(void *x, void *y));
                
void merge(void *data,
           size_t elem_size,
           int low,
           int mid,
           int high,
           bool (*less_than)(void *x, void *y));

#endif
