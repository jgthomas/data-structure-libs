#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

typedef struct new_node {
        void *data;
        struct new_node *left;
        struct new_node *right;
}
BinTreeNode;

BinTreeNode *BST_make_node(void *data, size_t data_size);

void BST_insert(BinTreeNode **root,
                void *new_data,
                size_t data_size,
                bool (*less_than)(void *x, void *y));

void BST_load_data(BinTreeNode **head,
                   void *new_data,
                   size_t data_size,
                   size_t elem_size,
                   bool (*less_than)(void *first, void *second));

bool BST_search(BinTreeNode **root,
                void *data,
                bool (*equals)(void *first, void *second),
                bool (*less_than)(void *first, void *second));

void BST_breadth_first_print(BinTreeNode *node, void (*print)(void *x));
void BST_visualise_tree(BinTreeNode *node, int level, void (*print)(void *item));
void BST_in_order_print(BinTreeNode *node, void (*print)(void *x));
void BST_pre_order_print(BinTreeNode *node, void (*print)(void *x));
void BST_post_order_print(BinTreeNode *node, void (*print)(void *x));

int BST_total_nodes(BinTreeNode *node);
int BST_max_depth(BinTreeNode *node);

void BST_delete_node(BinTreeNode *node);
void BST_delete_tree(BinTreeNode *root);

void BST_delete_value(BinTreeNode **root,
                      void *data,
                      bool (*equal)(void *x, void *y),
                      bool (*less_than)(void *x, void *y));

void *BST_min_value(BinTreeNode *node, bool (*less_than)(void *x, void *y));
void *BST_max_value(BinTreeNode *node, bool (*greater_than)(void *x, void *y));

#endif
