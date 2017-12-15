#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "treap.h"


TreapNode *treap_init(void)
{
        time_t t;
        TreapNode *root = NULL;

        // seed random number for priority
        srand((unsigned) time(&t));

        return root;
}


int priority(int max)
{
        return rand() % max;
}


TreapNode *treap_make_node(void *data, size_t data_size)
{
        TreapNode *new_node = malloc(sizeof(*new_node));

        if (new_node == NULL)
        {
                fprintf(stderr, "Failed to allocate memory for node\n");
                exit(EXIT_FAILURE);
        }

        new_node->key = malloc(data_size);

        if (new_node->key == NULL)
        {
                fprintf(stderr, "Failed to allocate memory for data\n");
                exit(EXIT_FAILURE);
        }

        memcpy(new_node->key, data, data_size);

        new_node->priority = priority(MAX);

        new_node->left = NULL;
        new_node->right = NULL;

        return new_node;
}


void treap_insert(TreapNode **root,
                  void *new_data,
                  size_t data_size,
                  bool (*less_than)(void *x, void *y))
{
        if ((*root) == NULL)
        {
                (*root) = treap_make_node(new_data, data_size);
        }
        else if (less_than(new_data, (*root)->key))
        {
                treap_insert(&(*root)->left, new_data, data_size, less_than);

                if ((*root)->left->priority > (*root)->priority)
                {
                        rotate_right(root);
                }
        }
        else
        {
                treap_insert(&(*root)->right, new_data, data_size, less_than);

                if ((*root)->right->priority > (*root)->priority)
                {
                        rotate_left(root);
                }
        }
}

/**
 * Store the LEFT child as the new_parent
 * Store the new parent's original RIGHT node
 *
 * Set the old parent as the new parent's RIGHT node
 * Set the stored RIGHT node as old parent's LEFT node
 * Set the new parent as the parent node
 *
 * */
void rotate_right(TreapNode **node)
{
        TreapNode *new_parent = (*node)->left;
        TreapNode *old_child_right = new_parent->right;

        new_parent->right = (*node);
        (*node)->left = old_child_right;
        (*node) = new_parent;
}


/**
 * Store the RIGHT child as the new_parent
 * Store the new parent's original LEFT node
 *
 * Set the old parent as the new parent's LEFT node
 * Set the stored LEFT node as old parent's RIGHT node
 * Set the new parent as the parent node
 *
 * */
void rotate_left(TreapNode **node)
{
        TreapNode *new_parent = (*node)->right;
        TreapNode *old_child_left = new_parent->left;

        new_parent->left = (*node);
        (*node)->right = old_child_left;
        (*node) = new_parent;
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
                treap_insert(head, next, data_size, less_than);
        }
}


bool treap_search(TreapNode **root,
                  void *data,
                  bool (*equals)(void *first, void *second),
                  bool (*less_than)(void *first, void *second))
{
        if ((*root) != NULL)
        {
                if (equals((*root)->key, data))
                {
                        return true;
                }
                else if (less_than(data, (*root)->key))
                {
                        return treap_search(&(*root)->left, data, equals, less_than);
                }
                else
                {
                        return treap_search(&(*root)->right, data, equals, less_than);
                }
        }

        return false;
}


void treap_delete_node(TreapNode *node)
{
        free(node->key);
        free(node);
}


void treap_delete(TreapNode *node)
{
        if (node != NULL)
        {
                treap_delete(node->left);
                treap_delete(node->right);
                treap_delete_node(node);
        }
}


void treap_visualise(TreapNode *node,
                     int level,
                     void (*print)(void *item))
{
	    if (node == NULL)
	    {
                return;
	    }

	    treap_visualise(node->right, level+1, print);

	    for (int i = 0; i < level; i++)
	    {
	            printf("       ");
	    }
	    print(node->key);
            printf("(%d)", node->priority);
	    printf("\n\n");

	    treap_visualise(node->left, level+1, print);
}


/**
 * InOrder traversal
 *
 * Traverse the tree from 'left to right' with root in the middle
 *
 * left subtree -> root -> right subtree
 *
 * Prints all values in tree in ascending order
 *
 * */
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


/**
 * PreOrder traversal
 *
 * Traverse the tree from the 'top down'
 *
 * root -> left subtree -> right subtree
 *
 * */
void treap_pre_order_print(TreapNode *node, void (*print)(void *x))
{
        if (node == NULL)
	{
	        return;
	}

        print(node->key);
        printf(" ");
        treap_pre_order_print(node->left, print);
        treap_pre_order_print(node->right, print);
}


/**
 * PostOrder traversal
 *
 * Traverse the tree from the 'bottom up'
 *
 * left subtree -> right subtree -> root
 *
 * */
void treap_post_order_print(TreapNode *node, void (*print)(void *x))
{
        if (node == NULL)
        {
                return;
        }

        treap_post_order_print(node->left, print);
        treap_post_order_print(node->right, print);
        print(node->key);
        printf(" ");
}
