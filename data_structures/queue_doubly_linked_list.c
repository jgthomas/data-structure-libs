#include <stdio.h>
#include "doubly_linked_list.h"
#include "queue_linked_list.h"


Queue *queue_init(void)
{
        Queue *new_queue = malloc(sizeof(*new_queue));

        if (new_queue == NULL)
        {
                fprintf(stderr, "Failed to allocate memory for queue\n");
                exit(EXIT_FAILURE);
        }

        new_queue->front = NULL;
        new_queue->back = NULL;

        return new_queue;
}


void enqueue(Queue *queue, void *data)
{
        Node *new_node = DL_list_create_node();
        new_node->data = data;

        if (empty_queue(queue))
        {
                queue->front = new_node;
                queue->back = new_node;
                new_node->next = NULL;
                new_node->previous = NULL;
        }
        else
        {
                new_node->next = queue->back;
                queue->back->previous = new_node;
                queue->back = new_node;
        }
}


void dequeue(Queue *queue, void *data)
{
        Node *new_node = DL_list_create_node();
        new_node->data = data;

        if (queue_empty(queue))
        {
                printf("Queue is empty\n");
                return;
        }
        else
        {
                Node *node_ptr = front;
                queue->front = queue->front->previous;
                free(node_ptr);
        }
}


void *queue_peek(Queue *queue)
{
        return queue->front->data;
}


bool queue_empty(Queue *queue)
{
        if (queue->front === NULL)
        {
                return true;
        }

        return false;
}
