#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "queue_array.h"
#include "binary_search_tree.h"


/**
 * Create new node, capable of taking any data type
 *
 * new_data   :  pointer to data to add to node
 * data_size  :  size of node data type
 *
 * */
BinTreeNode *BST_make_node(void *new_data)
{
        BinTreeNode *new_node = malloc(sizeof(*new_node));

        if (new_node == NULL)
        {
                fprintf(stderr, "Failed to allocate memory\n");
                exit(EXIT_FAILURE);
        }

        new_node->data = new_data;
        new_node->left = NULL;
        new_node->right = NULL;

        return new_node;
}


/**
 * Convenience function for loading data into BST
 *
 * */
void BST_load_data(BinTreeNode **head,
                   void *new_data,
                   size_t data_size,
                   size_t elem_size,
                   bool (*less_than)(void *first, void *second))
{
        int len = data_size/elem_size;

        for (int i = 0; i < len; i++)
        {
                void *next = new_data + elem_size * i;
                BST_insert(head, next, less_than);
        }
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
void BST_insert(BinTreeNode **head,
            void *new_data,
            bool (*less_than)(void *first, void *second))
{
        if ((*head) == NULL)
        {
                (*head) = BST_make_node(new_data);
        }
        else if (less_than(new_data, (*head)->data))
        {
                BST_insert(&(*head)->left, new_data, less_than);
        }
        else
        {
                BST_insert(&(*head)->right, new_data, less_than);
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
bool BST_search(BinTreeNode **head,
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
                        return BST_search(&(*head)->left, data, equals, less_than);
                }
                else
                {
                        return BST_search(&(*head)->right, data, equals, less_than);
                }
        }

        return false;
}


void BST_visualise_tree(BinTreeNode *node,
                        int level,
                        void (*print)(void *item))
{
	    if (node == NULL)
	    {
                return;
	    }

	    BST_visualise_tree(node->right, level+1, print);

	    for (int i = 0; i < level; i++)
	    {
	            printf("     ");
	    }
	    print(node->data);
	    printf("\n\n");

	    BST_visualise_tree(node->left, level+1, print);
}


void BST_breadth_first_print(BinTreeNode *node, void (*print)(void *x))
{
        Queue *queue = queue_init();
        enqueue(queue, node);
        BinTreeNode *current_front = node;

        while (current_front != NULL)
        {
                if (current_front->left != NULL)
                {
                        enqueue(queue, current_front->left);
                }

                if (current_front->right != NULL)
                {
                        enqueue(queue, current_front->right);
                }

                BinTreeNode *front = dequeue(queue);
                print(front->data);
                printf(" ");

                current_front = queue_peek(queue);
        }

        queue_delete(queue);
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
void BST_in_order_print(BinTreeNode *node, void (*print)(void *x))
{
        if (node == NULL)
        {
	            return;
        }

        BST_in_order_print(node->left, print);
        print(node->data);
        printf(" ");
        BST_in_order_print(node->right, print);
}


/**
 * PreOrder traversal
 *
 * Traverse the tree from the 'top down'
 *
 * root -> left subtree -> right subtree
 *
 * */
void BST_pre_order_print(BinTreeNode *node, void (*print)(void *x))
{
        if (node == NULL)
	    {
                return;
	    }

        print(node->data);
        printf(" ");
        BST_pre_order_print(node->left, print);
        BST_pre_order_print(node->right, print);
}


/**
 * PostOrder traversal
 *
 * Traverse the tree from the 'bottom up'
 *
 * left subtree -> right subtree -> root
 *
 * */
void BST_post_order_print(BinTreeNode *node, void (*print)(void *x))
{
        if (node == NULL)
        {
                return;
        }

        BST_post_order_print(node->left, print);
        BST_post_order_print(node->right, print);
        print(node->data);
        printf(" ");
}


int BST_total_nodes(BinTreeNode *node)
{
        if (node == NULL)
        {
                return 0;
        }

        return BST_total_nodes(node->left) + 1 + BST_total_nodes(node->right);
}


int BST_max_depth(BinTreeNode *node)
{
        if (node == NULL)
        {
                return 0;
        }

        int left_depth = BST_max_depth(node->left) + 1;
        int right_depth = BST_max_depth(node->right) + 1;

        if (left_depth > right_depth)
        {
                return left_depth;
        }

        return right_depth;
}


void *BST_min_value(BinTreeNode *node)
{
        while (node->left != NULL)
        {
                node = node->left;
        }

        return node->data;
}


void *BST_max_value(BinTreeNode *node)
{
        while (node->right != NULL)
        {
                node = node->right;
        }

        return node->data;
}


void BST_delete_tree(BinTreeNode *head)
{
        if (head != NULL)
        {
                BST_delete_tree(head->left);
                BST_delete_tree(head->right);
                free(head);
        }
}
