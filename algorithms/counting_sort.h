#ifndef COUNTING_SORT_H
#define COUNTING_SORT_H

#include "distribution_sort.h"

void simple_counting_sort(int array[], int len, int max);
void counting_sort(int array[], int len, int max);
void object_counting_sort(Record *record_array[], int len, int max);

#endif
