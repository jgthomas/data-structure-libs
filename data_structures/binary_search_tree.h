#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

typedef struct new_node {
        void *data;
        struct new_node *left;
        struct new_node *right;
}
BinTreeNode;

BinTreeNode *BST_make_node(void *new_data);

void BST_insert(BinTreeNode **head,
            void *new_data,
            bool (*less)(void *first, void *second));

void BST_load_data(BinTreeNode **head,
                   void *new_data,
                   size_t data_size,
                   size_t elem_size,
                   bool (*less_than)(void *first, void *second));

bool BST_search(BinTreeNode **head,
            void *data,
            bool (*equals)(void *first, void *second),
            bool (*less)(void *first, void *second));

void BST_visualise_tree(BinTreeNode *node,
                        int level,
                        void (*print)(void *item));

void delete_tree(BinTreeNode *head);
int total_nodes(BinTreeNode *node);
void post_order_print(BinTreeNode *node, void (*print)(void *x));
void pre_order_print(BinTreeNode *node, void (*print)(void *x));
void in_order_print(BinTreeNode *node, void (*print)(void *x));
int max_depth(BinTreeNode *node);
void *min_value(BinTreeNode *node);
void *max_value(BinTreeNode *node);

#endif
