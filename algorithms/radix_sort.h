#ifndef RADIX_SORT_H
#define RADIX_SORT_H

#include "tools/general_distro_sort.h"

enum {BUCKETS = 10};

void radix_sort(int array[], int len, int max);
void counting_sort(int array[], int len, int exp);
void object_radix_sort(Record *record_array[], int len, int max);
void object_counting_sort(Record *record_array[], int len, int exp);

#endif
