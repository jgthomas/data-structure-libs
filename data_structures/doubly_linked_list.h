#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H 

typedef struct new_node {
    void *data;
    struct new_node *next;
    struct new_node *previous;
}
Node;

Node *create_node(void *new_data);
void list_push(Node **head, void *new_data, size_t data_size);
void append(Node **node, void *new_data, size_t data_size);
void print_from_head(Node *node, void (*print)(void *x));
void print_from_tail(Node *node, void (*print)(void *x));
void delete_list(Node *node);
void dl_list_reverse(Node **head);

#endif
