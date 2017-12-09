#ifndef BUCKET_SORT_H
#define BUCKET_SORT_H

#include "data_structures/linked_list.h"
#include "tools/general_distro_sort.h"

void bucket_sort(Record *record_array[], int len, int max);
void init_buckets(Node *buckets[], int len);

void scatter(Node *buckets[],
             Record *record_array[],
             int len,
             int max);

void gather(Node *buckets[],
            Record *record_array[],
            int len);

void delete_buckets(Node *buckets[], int len);
void delete_bucket(Node *node);
void insert(Node **head, Record *record);
int pick_bucket(int n, int max, int len);

#endif
