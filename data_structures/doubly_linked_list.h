#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H 

typedef struct new_node {
    void *data;
    struct new_node *next;
    struct new_node *previous;
}
Node;

Node *DL_list_create_node(void);
void DL_list_push(Node **head, void *new_data, size_t data_size);
void DL_list_append(Node **node, void *new_data, size_t data_size);
void DL_print_from_head(Node *node, void (*print)(void *x));
void DL_print_from_tail(Node *node, void (*print)(void *x));
void DL_list_delete(Node *node);
void DL_list_reverse(Node **head);
void DL_list_insert(Node **node, void *new_data, int pos);
void DL_list_delete_index(Node **node, int index);

void DL_list_delete_value(Node **node,
                          void *val,
                          bool (*equal)(void *x, void *y));

bool DL_list_find_and_move(Node **node,
                           void *search,
                           bool (*equal)(void *, void *));

#endif
