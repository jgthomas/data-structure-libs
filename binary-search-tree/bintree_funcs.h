Node *make_node(void *new_data, size_t data_size);
void insert(Node **head, void *new_data, size_t data_size, bool (*less)(void *first, void *second));
bool search(Node **head, void *data, bool (*equals)(void *first, void *second), bool (*less)(void *first, void *second));
void print_tree(Node *node, int level, void (*print_ptr)(void *item));
void delete_tree(Node *head);
