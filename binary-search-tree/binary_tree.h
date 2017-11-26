#ifndef BINARY_TREE_H
#define BINARY_TREE_H 

typedef struct new_node {
        void *data;
        struct new_node *left;
        struct new_node *right;
}
BinTreeNode;

BinTreeNode *make_node(void *new_data, size_t data_size);
void insert(BinTreeNode **head, void *new_data, size_t data_size, bool (*less)(void *first, void *second));
bool search(BinTreeNode **head, void *data, bool (*equals)(void *first, void *second), bool (*less)(void *first, void *second));
void print_tree(BinTreeNode *node, int level, void (*print_ptr)(void *item));
void delete_tree(BinTreeNode *head);

#endif
