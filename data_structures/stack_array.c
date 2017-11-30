#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack_array.h"


Stack *stack_init(void)
{
        Stack *new_stack = malloc(sizeof(*new_stack));

        if (new_stack == NULL)
        {
                fprintf(stderr, "Failed to allocate memory for stack\n");
                exit(EXIT_FAILURE);
        }

        new_stack->top = -1;

        return new_stack;
}


void stack_push(Stack *stack, void *data)
{
        stack->array[stack->top+1] = data;
        stack->top += 1;
}


void stack_pop(Stack *stack)
{
        stack->top -= 1;
}


void *stack_peek(Stack *stack)
{
       return stack->array[stack->top];
}


void stack_delete(Stack *stack)
{
        free(stack);
}


void stack_add_data(Stack *stack,
                    void *data,
                    size_t data_size,
                    size_t elem_size)
{
        int len = data_size/elem_size;

        for (int i = 0; i < len; i++)
        {
                void *new_data = data + elem_size * i;
                stack_push(stack, new_data);
        }
}


bool stack_empty(Stack *stack)
{
        if (stack->top < 0)
        {
                return true;
        }

        return false;
}


void stack_print(Stack *stack, void (*print)(void *x))
{
        for (int i = 0; i <= stack->top; i++)
        {
                print(stack->array[i]);
                printf(" ");
        }

        printf("\n");
}
