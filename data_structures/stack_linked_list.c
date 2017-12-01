#include <stdio.h>
#include <stdbool.h>
#include "linked_list.h"
#include "stack_linked_list.h"


Node *stack_init()
{
        Node *top = NULL;
        return top;
}


void stack_push(Node **top, void *data)
{
        list_push(top, data);
}


void stack_add_data(Node **top,
                    void *data,
                    size_t data_size,
                    size_t elem_size)
{
        int len = data_size/elem_size;
        
        for (int i = 0; i < len; i++)
        {
                void *next_data = data + elem_size * i;
                stack_push(top, next_data);
        }
}


void stack_print(Node *top, void (*print)(void *x))
{
        list_print_visual(top, print);
}


void *stack_peek(Node *top)
{
        return top->data;
}


void *stack_pop(Node **top)
{
        void *data = (*top)->data;
        list_delete_index(top, 0);
        return data;
}


void stack_delete(Node *top)
{
        list_delete(top);
}
