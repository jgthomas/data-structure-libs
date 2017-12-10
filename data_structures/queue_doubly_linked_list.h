#include "doubly_linked_list.h"

typedef struct Queue {
        DllNode *front;
        DllNode *back;
}
Queue;

Queue *queue_init(void);
bool queue_empty(Queue *queue);
void queue_delete(Queue *queue);
void enqueue(Queue *queue, void *data);
void *dequeue(Queue *queue);
void *queue_peek(Queue *queue);
void queue_print_from_back(Queue *queue, void (*print)(void *x));
void queue_print_from_front(Queue *queue, void (*print)(void *x));
void queue_add_data(Queue *queue,
                    void *data,
                    size_t data_size,
                    size_t elem_size);
