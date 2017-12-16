#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "queue_array.h"
#include "binary_search_tree.h"


BinTreeNode *BST_make_node(void *data, size_t data_size)
{
        BinTreeNode *new_node = malloc(sizeof(*new_node));

        if (new_node == NULL)
        {
                fprintf(stderr, "Failed to allocate memory for node\n");
                exit(EXIT_FAILURE);
        }

        new_node->data = malloc(sizeof(data_size));

        if (new_node->data == NULL)
        {
                fprintf(stderr, "Failed to allocate memory for data\n");
                exit(EXIT_FAILURE);
        }

        memcpy(new_node->data, data, data_size);

        new_node->left = NULL;
        new_node->right = NULL;

        return new_node;
}


void BST_insert(BinTreeNode **root,
                void *new_data,
                size_t data_size,
                bool (*less_than)(void *x, void *y))
{
        if ((*root) == NULL)
        {
                (*root) = BST_make_node(new_data, data_size);
        }
        else if (less_than(new_data, (*root)->data))
        {
                BST_insert(&(*root)->left, new_data, data_size, less_than);
        }
        else
        {
                BST_insert(&(*root)->right, new_data, data_size, less_than);
        }
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
                BST_insert(head, next, elem_size, less_than);
        }
}


bool BST_search(BinTreeNode **root,
                void *data,
                bool (*equals)(void *first, void *second),
                bool (*less_than)(void *first, void *second))
{
        if ((*root) != NULL)
        {
                if (equals((*root)->data, data))
                {
                        return true;
                }
                else if (less_than(data, (*root)->data))
                {
                        return BST_search(&(*root)->left, data, equals, less_than);
                }
                else
                {
                        return BST_search(&(*root)->right, data, equals, less_than);
                }
        }

        return false;
}


void BST_delete_value(BinTreeNode **root,
                      void *data,
                      size_t data_size,
                      bool (*equal)(void *x, void *y),
                      bool (*less_than)(void *x, void *y))
{
        if (equal(data, (*root)->data))
        {
                if ((*root)->left == NULL && (*root)->right == NULL)
                {
                        free((*root)->data);
                        (*root)->data = NULL;
                }
                else if ((*root)->left != NULL && (*root)->right != NULL)
                {
                        void *low_in_right = BST_min_value((*root)->right, less_than);
                        memcpy((*root)->data, low_in_right, data_size);
                        BST_delete_value(&(*root)->right, low_in_right, data_size, equal, less_than);

                        if ((*root)->right->data == NULL)
                        {
                                BST_delete_node((*root)->right);
                                (*root)->right = NULL;
                        }
                }
                else
                {
                        if ((*root)->left != NULL)
                        {
                                BinTreeNode *temp = (*root);
                                (*root) = (*root)->left;
                                BST_delete_node(temp);
                        }
                        else
                        {
                                BinTreeNode *temp = (*root);
                                (*root) = (*root)->right;
                                BST_delete_node(temp);
                        }
                }
        }
        else if (less_than(data, (*root)->data))
        {
                BST_delete_value(&(*root)->left, data, data_size, equal, less_than);

                if ((*root)->left->data == NULL)
                {
                        BST_delete_node((*root)->left);
                        (*root)->left = NULL;
                }
        }
        else
        {
                BST_delete_value(&(*root)->right, data, data_size, equal, less_than);

                if ((*root)->right->data == NULL)
                {
                        BST_delete_node((*root)->right);
                        (*root)->right = NULL;
                }
        }

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


void BST_visualise_tree(BinTreeNode *node, int level, void (*print)(void *item))
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


void BST_delete_node(BinTreeNode *node)
{
        free(node->data);
        free(node);
}


void BST_delete_tree(BinTreeNode *root)
{
        if (root != NULL)
        {
                BST_delete_tree(root->left);
                BST_delete_tree(root->right);
                BST_delete_node(root);
        }
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


void *BST_min_value(BinTreeNode *node, bool (*less_than)(void *x, void *y))
{
        void *min = node->data;

        while (node->left != NULL)
        {
                node = node->left;

                if (less_than(node->data, min))
                {
                        min = node->data;
                }
        }

        return min;
}


void *BST_max_value(BinTreeNode *node, bool (*less_than)(void *x, void *y))
{
        void *max = node->data;

        while (node->right != NULL)
        {
                node = node->right;

                if (less_than(max, node->data))
                {
                        max = node->data;
                }
        }

        return max;
}
