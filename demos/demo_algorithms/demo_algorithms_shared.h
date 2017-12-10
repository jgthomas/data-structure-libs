#ifndef DEMO_ALGO_SHARED_H
#define DEMO_ALGO_SHARED_H

#include <stdbool.h>

extern int ARRAY[];
extern int LEN;
extern int operations;

void print_array(int array[], int len);
int to_int(char *string);
int get_int(char *message);
void swap(int *a, int *b);
bool less_than(int a, int b);

#endif
