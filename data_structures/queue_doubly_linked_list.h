#include "doubly_linked_list.h"

typedef struct Queue {
        Node *front;
        Node *back;
}
Queue;

Queue *queue_init(void);
bool queue_empty(Queue *queue);
void enqueue(Queue *queue, void *data);
void dequeue(Queue *queue, void *data);
