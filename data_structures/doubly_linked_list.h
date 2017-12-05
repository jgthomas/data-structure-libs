#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H 

typedef struct new_dll_node {
    void *data;
    struct new_dll_node *next;
    struct new_dll_node *previous;
}
DllNode;

DllNode *DL_list_init();
DllNode *DL_list_create_node(void);
int DL_list_length(DllNode *node);
bool DL_list_is_empty(DllNode *node);
void DL_list_push(DllNode **head, void *new_data);
void DL_list_append(DllNode **node, void *new_data);
void DL_print_from_head(DllNode *node, void (*print)(void *x));
void DL_print_from_tail(DllNode *node, void (*print)(void *x));
void DL_list_delete(DllNode *node);
void DL_list_delete_node(DllNode *node);
void DL_list_reverse(DllNode **head);
void DL_list_insert(DllNode **node, void *new_data, int pos);
void DL_list_delete_index(DllNode **node, int index);

void DL_list_delete_value(DllNode **node,
                          void *val,
                          bool (*equal)(void *x, void *y));

bool DL_list_find_and_move(DllNode **node,
                           void *search,
                           bool (*equal)(void *, void *));

void DL_list_add_data(DllNode **head,
                      void *data,
                      size_t data_size,
                      size_t elem_size,
                      void (*add_to_list)(DllNode **head, void *new_data));

#endif
