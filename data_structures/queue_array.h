#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H

enum {QUEUE_BUFFER = 2048};

typedef struct Queue {
        void *array[QUEUE_BUFFER];
        int front;
        int back;
}
Queue;

Queue *queue_init(void);
void enqueue(Queue *queue, void *data);
void *dequeue(Queue *queue);
void *queue_peek(Queue *queue);
void queue_delete(Queue *queue);
void queue_print(Queue *queue, void (*print)(void *x));

void queue_add_data(Queue *queue,
                    void *data,
                    size_t data_size,
                    size_t elem_size);

#endif
