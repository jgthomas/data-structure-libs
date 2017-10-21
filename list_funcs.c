#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "node.h"
#include "list_funcs.h"


/**
 * Add node to front of list
 * 
 * */
void push(Node **head, void *new_data, size_t data_size)
{
    Node *new_node = malloc(sizeof(new_node));
    
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
 
    // copy each byte of *new_data* into *new_node->data*
    for (int i = 0; i < data_size; i++)
    {
        *(uint8_t *)(new_node->data + i) = *(uint8_t *)(new_data + i);
    }
 
    // set new node as the new head
    (*head) = new_node;
}


/**
 * Add node to end of list
 * 
 * */
void append(Node **head, void *new_data, size_t data_size)
{
    Node *new_node = malloc(sizeof(new_node));
    
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
    
    // copy each byte of *new_data* into *new_node->data*
    for (int i = 0; i < data_size; i++)
    {
        *(uint8_t *)(new_node->data + i) = *(uint8_t *)(new_data + i);
    }
    
    // set a 'cursor' node to head of list
    Node *node_ptr = (*head);
    
    // advance to end of list
    while (node_ptr->next != NULL)
    {
        node_ptr = node_ptr->next;
    }
    
    // if previous end node, pointold end's next to new_node
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
 * Print list sequence to screen
 * 
 * */
void print_list(Node *node, void (*fptr)(void *))
{
    while (node != NULL)
    {
        // pass contents of node data as argument to function pointer
        (*fptr)(node->data);
        
        // move to next node
        node = node->next;
        
        if (node != NULL)
        {
            printf(" --> ");
        }
    }
    printf("\n");
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
