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

int priority(int max);
void treap_init(void);
TreapNode *treap_make_node(void *new_data);
void treap_delete(TreapNode *node);
void rotate_right(TreapNode **node);
void rotate_left(TreapNode **node);

void treap_in_order_print(TreapNode *node, void (*print)(void *x));

bool treap_search(TreapNode **root,
            void *data,
            bool (*equals)(void *first, void *second),
            bool (*less_than)(void *first, void *second));

void treap_insert(TreapNode **node,
                  void *new_data,
                  bool (*less_than)(void *first, void *second));

void treap_load_data(TreapNode **head,
                     void *new_data,
                     size_t data_size,
                     size_t elem_size,
                     bool (*less_than)(void *first, void *second));

#endif
