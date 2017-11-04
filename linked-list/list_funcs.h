#ifndef LIST_FUNCS_H
#define LIST_FUNCS_H

void push(Node **head_ref, void *new_data, size_t data_size);
unsigned int list_length(Node *node);
bool is_empty(Node *node);
void print_list(Node *node, void (*fptr)(void *), const char *sep);
void print_values(Node *node, void (*fptr)(void *));
void print_list_visual(Node *node, void(*fptr)(void *));
void delete_list(Node *node);
void append(Node **head, void *new_data, size_t data_size);
void reverse(Node **current_node);
bool list_contains(Node *node, void *search, bool (*fptr)(void *, void *));
bool find_and_move(Node **node, void *search, bool (*fptr)(void *, void *));
void insert(Node **node, void *new_data, size_t data_size, int pos);
void del_index(Node **node, int index);
void del_val(Node **node, void *val, bool (*fptr)(void *, void *));
void copy_by_byte(Node **node, void *new_data, size_t data_size);
void free_node(Node *node);

#endif
