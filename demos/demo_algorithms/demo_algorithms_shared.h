#ifndef DEMO_ALGO_SHARED_H
#define DEMO_ALGO_SHARED_H

#include <stdbool.h>

typedef struct new_node {
    int n;
    struct new_node *next;
}
Node;

enum {BUCKETS = 10};

extern int ARRAY[];
extern int LEN;
extern int operations;

extern int RADIX_ARRAY[];
extern int RADIX_LEN;

void print_array(int array[], int len);
int to_int(char *string);
int get_int(char *message);
void swap(int *a, int *b);
bool less_than(int a, int b);
int find_max_integer(int array[], int len);
int num_digits(int n);
void print_partial_array(int array[], int low, int high);

#endif
