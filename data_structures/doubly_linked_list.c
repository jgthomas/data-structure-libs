#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "doubly_linked_list.h"


DllNode *DL_list_init()
{
        DllNode *head = NULL;
        return head;
}


DllNode *DL_list_create_node(void)
{
        DllNode *new_node = malloc(sizeof(*new_node));

        if (new_node == NULL)
        {
            fprintf(stderr, "Failed to allocate memory for node\n");
            exit(EXIT_FAILURE);
        }
 
        return new_node;
}


void DL_list_push(DllNode **head, void *new_data)
{
        DllNode *new_node = DL_list_create_node();

        new_node->data = new_data;
        new_node->next = (*head);
        new_node->previous = NULL;

        if ((*head) != NULL)
        {
                (*head)->previous = new_node;
        }
 
        (*head) = new_node;
}


void DL_list_append(DllNode **node, void *new_data)
{
        DllNode *new_node = DL_list_create_node();;
        new_node->data = new_data;
        new_node->next = NULL;
        new_node->previous = NULL;

        if ((*node) == NULL)
        {
                (*node) = new_node;
                return;
        }

        // set up cursor
        DllNode *node_ptr = (*node);

        // advance to end of list
        while (node_ptr->next != NULL)
        {
                node_ptr = node_ptr->next;
        }

        // set previous to current end node
        new_node->previous = node_ptr;

        // if end node exists, point next to new node
        if (node_ptr != NULL)
        {
                node_ptr->next = new_node;
        }
}


void DL_list_add_data(DllNode **head,
                      void *data,
                      size_t data_size,
                      size_t elem_size,
                      void (*add_to_list)(DllNode **head, void *new_data))
{
        int len = data_size/elem_size;

        for (int i = 0; i < len; i++)
        {
                void *new_data = data + elem_size * i;
                add_to_list(head, new_data);
        }
}


int DL_list_length(DllNode *node)
{
        int count = 0;

        while (node != NULL)
        {
                node = node->next;
                count++;
        }

        return count;
}


bool DL_list_contains(DllNode *node,
                      void *search,
                      bool (*equal)(void *, void *))
{
        while (node != NULL)
        {
            if (equal(search, node->data))
            {
                return true;
            }
            node = node->next;
        }

        return false;
}


bool DL_list_is_empty(DllNode *node)
{
        if (node == NULL)
        {
            return true;
        }

        return false;
}


void DL_print_from_head(DllNode *node, void (*print)(void *x))
{
        while (node != NULL)
        {
                print(node->data);
                printf(" ");
                node = node->next;
        }

        printf("\n");
}


void DL_print_from_tail(DllNode *node, void (*print)(void *x))
{
        while (node->next != NULL)
        {
                node = node->next;
        }

        while (node != NULL)
        {
                print(node->data);
                printf(" ");
                node = node->previous;
        }

        printf("\n");
}


void DL_list_delete_node(DllNode *node)
{
        free(node);
}


void DL_list_delete(DllNode *node)
{
        while (node != NULL)
        {
                DllNode *temp = node;
                node = node->next;
                DL_list_delete_node(temp);
        }
}


void DL_list_reverse(DllNode **head)
{
        DllNode *temp = NULL;

        while ((*head) != NULL)
        {
                // store previous in temporary variable
                temp = (*head)->previous;

                // swap previous for next
                (*head)->previous = (*head)->next;

                // point next to the stored, old previous
                (*head)->next = temp;

                // as we swapped next and previous,
                // previous moves us to next in list
                (*head) = (*head)->previous;
        }
    
        if (temp != NULL)
        {
                (*head) = temp->previous;
        }
}


void DL_list_delete_value(DllNode **node,
                          void *val,
                          bool (*equal)(void *x, void *y))
{
        DllNode *original_head = (*node);
        DllNode *before = NULL;
        bool first_elem_deleted = true;

        while ((*node) != NULL)
        {
                if (equal(val, (*node)->data))
                {
                        DllNode *temp = (*node);

                        if (first_elem_deleted)
                        {
                                (*node) = (*node)->next;
                                (*node)->previous = NULL;
                        }
                        else
                        {
                                before->next = (*node)->next;

                                if ((*node)->next != NULL)
                                {
                                        (*node)->next->previous = before;
                                }
                        }

                        DL_list_delete_node(temp);
                        break;
                }

                before = (*node);
                (*node) = (*node)->next;
                first_elem_deleted = false;
        }

        if (!first_elem_deleted)
        {
                (*node) = original_head;
        }
}


/**
 * Search and move the found node to the front of the list
 *
 * */
bool DL_list_find_and_move(DllNode **node,
                           void *search,
                           bool (*equal)(void *, void *))
{
        DllNode *original_head = (*node);
        DllNode *node_ptr = (*node);
        DllNode *before;
        DllNode *after;

        if (equal(search, node_ptr->data))
        {
                return true;
        }

        while (node_ptr->next != NULL)
        {
                before = node_ptr;
                node_ptr = node_ptr->next;
                after = node_ptr->next;

                if (equal(search, node_ptr->data))
                {
                        if (node_ptr->next != NULL)
                        {
                                before->next = after;
                                after->previous = before;
                        }
                        else
                        {
                                before->next = NULL;
                        }

                        node_ptr->next = original_head;
                        original_head->previous = node_ptr;

                        node_ptr->previous = NULL;
                        (*node) = node_ptr;

                        return true;
                }
        }

        node_ptr = original_head;

        return false;
}


void DL_list_insert(DllNode **node, void *new_data, int pos)
{
        DllNode *new_node = DL_list_create_node();
        new_node->data = new_data;
        new_node->next = NULL;
        new_node->previous = NULL;

        if (pos == 0)
        {
                new_node->next = (*node);
                (*node) = new_node;
                return;
        }

        int index = 0;
        DllNode *old_head = (*node);
        DllNode *before = NULL;

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
                (*node)->previous = new_node;
                new_node->previous = before;
        }

        (*node) = old_head;
}


void DL_list_delete_index(DllNode **node, int index)
{
        DllNode *old_head = (*node);
        DllNode *before = NULL;
        int count = 0;

        while ((*node) != NULL && count != index)
        {
                before = (*node);
                (*node) = (*node)->next;
                count++;
        }

        if ((*node) != NULL && count == index)
        {
                DllNode *temp = (*node);

                if (index == 0)
                {
                        (*node) = (*node)->next;
                }
                else
                {
                        before->next = (*node)->next;

                        if ((*node)->next != NULL)
                        {
                                (*node)->next->previous = before;
                        }
                }

                DL_list_delete_node(temp);
        }

        if (index > 0)
        {
                (*node) = old_head;
        }
}
