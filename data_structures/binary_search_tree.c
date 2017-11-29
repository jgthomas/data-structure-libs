#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "binary_tree.h"


/**
 * Create new node, capable of taking any data type
 *
 * new_data   :  pointer to data to add to node
 * data_size  :  size of node data type
 *
 * */
BinTreeNode *make_node(void *new_data, size_t data_size)
{
        BinTreeNode *new_node = malloc(sizeof(*new_node));

        if (new_node == NULL)
        {
                fprintf(stderr, "Failed to allocate memory\n");
                exit(EXIT_FAILURE);
        }

        new_node->left = NULL;
        new_node->right = NULL;
        
        new_node->data = malloc(sizeof(data_size));
        
        if (new_node->data == NULL)
        {
                fprintf(stderr, "Failed to allocate memory\n");
                exit(EXIT_FAILURE);
        }

        for (unsigned int i = 0; i < data_size; i++)
        {
                *(uint8_t *)(new_node->data + i) = *(uint8_t *)(new_data + i);
        }

        return new_node;
}


/**
 * Insert new node into the tree
 *
 * head       :  current root of the tree
 * new_data   :  data to add to inserted node
 * data_size  :  size of node data type
 * less_than  :  function checks first item is less than second
 *
 * */
void insert(BinTreeNode **head,
            void *new_data,
            size_t data_size,
            bool (*less_than)(void *first, void *second))
{
        if ((*head) == NULL)
        {
                (*head) = make_node(new_data, data_size);
        }
        else if (less_than(new_data, (*head)->data))
        {
                insert(&(*head)->left, new_data, data_size, less_than);
        }
        else
        {
                insert(&(*head)->right, new_data, data_size, less_than);
        }
}


/**
 * Search tree for value
 *
 * head       :  current root of the tree
 * data       :  value to find
 * equals     :  function checks two items are equal
 * less_than  :  function checks first item is less than second
 *
 * */
bool search(BinTreeNode **head,
            void *data,
            bool (*equals)(void *first, void *second),
            bool (*less_than)(void *first, void *second))
{
        if ((*head) != NULL)
        {
                if (equals((*head)->data, data))
                {
                        return true;
                }
                else if (less_than(data, (*head)->data))
                {
                        return search(&(*head)->left, data, equals, less_than);
                }
                else
                {
                        return search(&(*head)->right, data, equals, less_than);
                }
        }

        return false;
}


void visualise_tree(BinTreeNode *node, int level, void (*print_ptr)(void *item))
{
	    if (node == NULL)
	    {
                return;
	    }

	    visualise_tree(node->right, level+1, print_ptr);

	    for (int i = 0; i < level; i++)
	    {
	            printf("     ");
	    }
	    print_ptr(node->data);
	    printf("\n");

	    visualise_tree(node->left, level+1, print_ptr);
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
void in_order_print(BinTreeNode *node, void (*print)(void *x))
{
        if (node == NULL)
	    {
	            return;
	    }

        in_order_print(node->left, print);
        print(node->data);
        printf(" ");
        in_order_print(node->right, print);
}


/**
 * PreOrder traversal
 *
 * Traverse the tree from the 'top down'
 *
 * root -> left subtree -> right subtree
 *
 * */
void pre_order_print(BinTreeNode *node, void (*print)(void *x))
{
        if (node == NULL)
	    {
                return;
	    }

        print(node->data);
        printf(" ");
        pre_order_print(node->left, print);
        pre_order_print(node->right, print);
}


/**
 * PostOrder traversal
 *
 * Traverse the tree from the 'bottom up'
 *
 * left subtree -> right subtree -> root
 *
 * */
void post_order_print(BinTreeNode *node, void (*print)(void *x))
{
        if (node == NULL)
        {
                return;
        }
        
        post_order_print(node->left, print);
        post_order_print(node->right, print);
        print(node->data);
        printf(" ");
}


int total_nodes(BinTreeNode *node)
{
        if (node == NULL)
        {
                return 0;
        }
        return total_nodes(node->left) + 1 + total_nodes(node->right);
}


void delete_tree(BinTreeNode *head)
{
        if (head != NULL)
        {
                delete_tree(head->left);
                delete_tree(head->right);
                free(head->data);
                free(head);
        }
}
