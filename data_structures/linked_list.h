#ifndef LIST_FUNCS_H
#define LIST_FUNCS_H

typedef struct new_node {
    void *data;
    struct new_node *next;
}
Node;


typedef struct List {
    struct Node *next;
}
List;


Node *list_init();
Node *create_node();
void list_push(Node **head_ref, void *new_data);
unsigned int list_length(Node *node);
bool list_is_empty(Node *node);
void list_print_values(Node *node, void (*fptr)(void *));
void list_print_visual(Node *node, void(*fptr)(void *));
void list_delete(Node *node);
void list_append(Node **head, void *new_data);
void list_reverse(Node **current_node);
bool list_contains(Node *node, void *search, bool (*fptr)(void *, void *));
bool list_find_and_move(Node **node, void *search, bool (*fptr)(void *, void *));
void list_insert(Node **node, void *new_data, int pos);
void list_delete_index(Node **node, int index);
void list_delete_value(Node **node, void *val, bool (*fptr)(void *, void *));

void list_add_data(Node **head,
                   void *data,
                   size_t data_size,
                   size_t elem_size,
                   void (*add_to_list)(Node **head, void *new_data));

#endif
