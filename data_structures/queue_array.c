#include <stdio.h>
#include <stdlib.h>
#include "queue_array.h"


Queue *queue_init(void)
{
        Queue *new_queue = malloc(sizeof(*new_queue));

        if (new_queue == NULL)
        {
                fprintf(stderr, "Failed to allocate memory for queue\n");
                exit(EXIT_FAILURE);
        }

        new_queue->front = 0;
        new_queue->back = 0;

        return new_queue;
}


void enqueue(Queue *queue, void *data)
{
        queue->array[queue->back] = data;
        queue->back += 1;
}


void queue_add_data(Queue *queue,
                    void *data,
                    size_t data_size,
                    size_t elem_size)
{
        int len = data_size/elem_size;

        for (int i = 0; i < len; i++)
        {
                void *new_data = data + elem_size * i;
                enqueue(queue, new_data);
        }
}


void dequeue(Queue *queue)
{
        queue->front += 1;
}


void *queue_peek(Queue *queue)
{
        return queue->array[queue->front];
}


void queue_delete(Queue *queue)
{
        free(queue);
}


void queue_print(Queue *queue, void (*print)(void *x))
{
        for (int i = queue->front; i < queue->back; i++)
        {
                print(queue->array[i]);
                printf(" ");
        }

        printf("\n");
}
