#ifndef TREAP_H
#define TREAP_H

#include <stdbool.h>

enum {MAX = 200};

typedef struct treap_node {
        void *key;
        int priority;
        struct treap_node *left;
        struct treap_node *right;        
}
TreapNode;


TreapNode *treap_init(void);
int priority(int max);
TreapNode *BST_make_node(void *data, size_t data_size);
void rotate_right(TreapNode **node);
void rotate_left(TreapNode **node);
void treap_delete_node(TreapNode *node);
void treap_delete(TreapNode *node);

void treap_in_order_print(TreapNode *node, void (*print)(void *x));
void treap_pre_order_print(TreapNode *node, void (*print)(void *x));
void treap_post_order_print(TreapNode *node, void (*print)(void *x));

void treap_insert(TreapNode **root,
                  void *new_data,
                  size_t data_size,
                  bool (*less_than)(void *x, void *y));

void treap_load_data(TreapNode **head,
                     void *new_data,
                     size_t data_size,
                     size_t elem_size,
                     bool (*less_than)(void *first, void *second));

bool treap_search(TreapNode **root,
                  void *data,
                  bool (*equals)(void *first, void *second),
                  bool (*less_than)(void *first, void *second));

void treap_visualise(TreapNode *node,
                     int level,
                     void (*print)(void *item));

#endif
