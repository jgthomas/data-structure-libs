#include "linked_list.h"

Node *stack_init();
bool stack_empty(Node *top);
void stack_push(Node **top, void *data);
void stack_print(Node *top, void (*print)(void *x));
void *stack_peek(Node *top);
void *stack_pop(Node **top);
void stack_delete(Node *top);
void stack_add_data(Node **top,
                    void *data,
                    size_t data_size,
                    size_t elem_size);
