#ifndef PRINTING_H
#define PRINTING_H

void print_int(void *n);
void print_float(void *f);
void print_char(void *c);
void print_string(void *s);

void print_sequence(void *sequence,
                    size_t data_size,
                    size_t elem_size,
                    void (*print)(void *data));

void print_generic_array(void *array[],
                         size_t data_size,
                         size_t elem_size,
                         void (*print)(void *data));

#endif
