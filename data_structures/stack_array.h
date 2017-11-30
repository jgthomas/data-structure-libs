#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include <stdbool.h>

enum {STACK_BUFFER = 2048};

typedef struct Stack {
        void *array[STACK_BUFFER];
        int top;
}
Stack;

Stack *stack_init(void);
void stack_push(Stack *stack, void *data);
void stack_pop(Stack *stack);
void *stack_peek(Stack *stack);
void stack_delete(Stack *stack);
bool stack_empty(Stack *stack);
void stack_print(Stack *stack, void (*print)(void *x));

void stack_add_data(Stack *stack,
                    void *data,
                    size_t data_size,
                    size_t elem_size);

#endif
