#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "treap.h"


void treap_init(void)
{
        time_t t;
        srand((unsigned) time(&t));
}


TreapNode *treap_make_node(void *new_data)
{
        TreapNode *new_node = malloc(sizeof(*new_node));

        if (new_node == NULL)
        {
                fprintf(stderr, "Failed to allocate memory\n");
                exit(EXIT_FAILURE);
        }

        new_node->key = new_data;
        new_node->priority = priority(MAX);
        new_node->left = NULL;
        new_node->right = NULL;

        return new_node;
}


void treap_load_data(TreapNode **head,
                     void *new_data,
                     size_t data_size,
                     size_t elem_size,
                     bool (*less_than)(void *first, void *second))
{
        int len = data_size/elem_size;

        for (int i = 0; i < len; i++)
        {
                void *next = new_data + elem_size * i;
                treap_insert(head, next, less_than);
        }
}


void treap_insert(TreapNode **node,
                  void *new_data,
                  bool (*less_than)(void *first, void *second))
{
        if ((*node) == NULL)
        {
                (*node) = treap_make_node(new_data);
        }
        else if (less_than(new_data, (*node)->key))
        {
                treap_insert(&(*node)->left, new_data, less_than);

                if ((*node)->left->priority > (*node)->priority)
                {
                        rotate_right(node);
                }
        }
        else
        {
                treap_insert(&(*node)->right, new_data, less_than);

                if ((*node)->right->priority > (*node)->priority)
                {
                        rotate_left(node);
                }
        }
}


void rotate_right(TreapNode **node)
{
        TreapNode *new_parent = (*node)->left;
        TreapNode *tmp = new_parent->right;

        new_parent->right = (*node);
        (*node)->left = tmp;
        (*node) = new_parent;
}


void rotate_left(TreapNode **node)
{
        TreapNode *new_parent = (*node)->right;
        TreapNode *tmp = new_parent->left;

        new_parent->left = (*node);
        (*node)->right = tmp;
        (*node) = new_parent;
}


bool treap_search(TreapNode **node,
                  void *data,
                  bool (*equals)(void *first, void *second),
                  bool (*less_than)(void *first, void *second))
{
        if ((*node) != NULL)
        {
                if (equals((*node)->key, data))
                {
                        return true;
                }
                else if (less_than(data, (*node)->key))
                {
                        return treap_search(&(*node)->left, data, equals, less_than);
                }
                else
                {
                        return treap_search(&(*node)->right, data, equals, less_than);
                }
        }

        return false;
}


void treap_delete(TreapNode *node)
{
        if (node != NULL)
        {
                treap_delete(node->left);
                treap_delete(node->right);
                free(node);
        }
}


int priority(int max)
{
        return rand() % max;
}


void treap_in_order_print(TreapNode *node, void (*print)(void *x))
{
        if (node == NULL)
        {
                return;
        }

        treap_in_order_print(node->left, print);
        print(node->key);
        printf(" ");
        treap_in_order_print(node->right, print);
}
