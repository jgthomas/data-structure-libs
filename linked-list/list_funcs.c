#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "node.h"
#include "list_funcs.h"
#include "utilities.h"


/**
 * Add node to front of list
 * 
 * */
void push(Node **head, void *new_data, size_t data_size)
{
        Node *new_node = malloc(sizeof(*new_node));
        
        if (new_node == NULL)
        {
            printf("Failed to allocate memory\n");
            exit(1);
        }
 
        new_node->data = malloc(data_size);
        
        if (new_node->data == NULL)
        {
            printf("Failed to allocate memory\n");
            exit(1);
        }
        
        new_node->next = (*head);
 
        // copy data into new_node
        copy_by_byte(&new_node, new_data, data_size);
 
        // set new node as the new head
        (*head) = new_node;
}


/**
 * Add node to end of list
 * 
 * */
void append(Node **head, void *new_data, size_t data_size)
{
        Node *new_node = malloc(sizeof(*new_node));
        
        if (new_node == NULL)
        {
            printf("Failed to allocate memory\n");
            exit(1);
        }
        
        new_node->data  = malloc(data_size);
        
        if (new_node->data == NULL)
        {
            printf("Failed to allocate memory\n");
            exit(1);
        }
        
        new_node->next = NULL;
        
        // copy data into new_node
        copy_by_byte(&new_node, new_data, data_size);

        // set a 'cursor' node to head of list
        Node *node_ptr = (*head);
        
        // advance to end of list
        while (node_ptr->next != NULL)
        {
            node_ptr = node_ptr->next;
        }
        
        // if previous end node, point it's next to new_node
        if (node_ptr != NULL)
        {
            node_ptr->next = new_node;
        }
}




/**
 * Return length of list
 * 
 * */
unsigned int list_length(Node *node)
{
        unsigned int count = 0;
        
        while (node != NULL)
        {
            node = node->next;
            count++;
        }
        
        return count;
}


/**
 * Check if list is empty
 * 
 * */
bool is_empty(Node *node)
{
        if (node == NULL)
        {
            return true;
        }

        return false;
}


/**
 * Print list sequence to screen with visualising arrows
 * 
 * */
void print_list(Node *node, void (*fptr)(void *), const char *sep)
{
        while (node != NULL)
        {
            (*fptr)(node->data);
            node = node->next;
            
            if (sep != NULL)
            {
                    if (node != NULL)
                    {
                            printf("%s", sep);
                    }
            }
        }
        printf("\n");
}


/**
 * Print just list values
 *
 * */
void print_values(Node *node, void (*fptr)(void *))
{
        const char *sep = NULL;
        print_list(node, fptr, sep);
}


void print_list_visual(Node *node, void(*fptr)(void *))
{
        const char *sep = " --> ";
        print_list(node, fptr, sep);
}


/**
 * Check if list contains an element
 * 
 * */
bool list_contains(Node *node, void *search, bool (*fptr)(void *, void *))
{
        while (node != NULL)
        {
            if ((*fptr)(search, node->data))
            {
                return true;
            }
            node = node->next;
        }
        
        return false;
}



/**
 * Insert data at specified index, if index longer than list append data
 *
 * */
void insert(Node **node, void *new_data, size_t data_size, int pos)
{
        Node *new_node = malloc(sizeof(*new_node));

        if (new_node == NULL)
        {
            printf("Failed to allocate memory\n");
            exit(1);
        }

        new_node->data = malloc(sizeof(data_size));

        if (new_node->data == NULL)
        {
            printf("Failed to allocate memory\n");
            exit(1);
        }

        new_node->next = NULL;
        copy_by_byte(&new_node, new_data, data_size);

        int index = 0;
        Node *old_head = (*node);
        Node *before = NULL;

        while ((*node) != NULL && index != pos)
        {
                before = (*node);
                (*node) = (*node)->next;
                index++;
        }

        before->next = new_node;

        if (index == pos)
        {
                new_node->next = (*node);
        }

        (*node) = old_head;
}


/**
 * Delete the specified index from the list
 *
 * */
void del_index(Node **node, int index)
{
        Node *old_head = (*node);
        Node *before = NULL;
        Node *temp = NULL;
        int count = 0;

        while ((*node) != NULL && count != index)
        {
                before = (*node);
                (*node) = (*node)->next;
                count++;
        }

        if ((*node) != NULL && count == index)
        {
                temp = (*node);

                if (index == 0)
                {
                        (*node) = (*node)->next;
                }
                else
                {
                        before->next = (*node)->next;
                }

                free_node(temp);
        }

        if (index > 0)
        {
                (*node) = old_head;
        }
}



void del_val(Node **node, void *val, bool (*fptr)(void *, void *))
{
        Node *old_head = (*node);
        Node *before = NULL;
        Node *temp = NULL;
        int count = 0;

        while ((*node) != NULL)
        {
                if (fptr(val, (*node)->data))
                {
                        temp = (*node);

                        if (count == 0)
                        {
                                (*node) = (*node)->next;
                        }
                        else
                        {
                                before->next = (*node)->next;
                        }

                        free_node(temp);
                        break;
                }

                before = (*node);
                (*node) = (*node)->next;
                count++;
        }

        if (count > 0)
        {
                (*node) = old_head;
        }
}



/**
 * Search and move the found node to the front of the list
 *
 * */
bool find_and_move(Node **node, void *search, bool (*fptr)(void *, void *))
{
        // if item found is already in first position, do nothing
        if ((*fptr)(search, (*node)->data))
        {
                return true;
        }

        // save old head node
        Node *old_head = (*node);

        Node *before = NULL;
        Node *after = NULL;

        while ((*node) != NULL)
        {
                before = (*node);
                (*node) = (*node)->next;

                if ((*node) != NULL)
                {
                        after = (*node)->next;

                        if ((*fptr)(search, (*node)->data))
                        {
                                before->next = after;
                                (*node)->next = old_head;
                                return true;
                        }
                }
        }
        // if not found, restore list to initial state
        (*node) = old_head;
        return false;
}


/**
 * Delete list, freeing all memory
 * 
 * */
void delete_list(Node *node)
{
        while (node != NULL)
        {
            Node *temp = node;
            node = node->next;
            free(temp->data);
            free(temp);
        }
}


/**
 * Reverse the list
 * 
 * */
void reverse(Node **current_node)
{
        // declare two temporary variables
        Node *next_node = NULL;
        Node *previous_node = NULL;
        
        while ((*current_node) != NULL)
        {
            // store the present next node in first temporary variable
            next_node = (*current_node)->next;
            
            // change next to the other temporary variable
            (*current_node)->next = previous_node;
            
            // point the new next to the current node
            previous_node = (*current_node);
            
            // move current node to the stored next node
            (*current_node) = next_node;
        }
        
        // return head to the last non-null node
        (*current_node) = previous_node;
}
