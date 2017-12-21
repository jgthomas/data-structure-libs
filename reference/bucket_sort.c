#include <stdio.h>
#include <stdlib.h>
#include "shared_sort.h"
#include "bucket_sort.h"


/**
 * BUCKET SORT
 *
 * Create a number of buckets proportional to input size and range
 * Distribute each element to the relevant buckets
 * Each bucket uses a linked list to hold multiple values
 * Linked list is ordered using insertion sort
 * Pull all the buckets together to produce sorted list
 *
 * */
void bucket_sort(int array[], int len)
{
        Node *buckets[len];
        init_buckets(buckets, len);
        scatter(buckets, array, len);
        gather(buckets, array, len);
        delete_buckets(buckets, len);
}


void init_buckets(Node *buckets[], int len)
{
        for (int bucket = 0; bucket < len; bucket++)
        {
                buckets[bucket] = NULL;
        }
}


void scatter(Node *buckets[], int array[], int len)
{
        int max = find_max(array, len);
        
        for (int i = 0; i < len; i++)
        {
                int bucket = pick_bucket(array[i], max, len);
                insert(&buckets[bucket], array[i]);
        }
}


void gather(Node *buckets[], int array[], int len)
{
        int index = 0;

        for (int i = 0; i < len; i++)
        {
                Node *node_ptr = buckets[i];

                while (node_ptr != NULL)
                {
                        array[index] = node_ptr->n;
                        index++;
                        node_ptr = node_ptr->next;
                }
        }
}


void delete_buckets(Node *buckets[], int len)
{
        for (int i = 0; i < len; i++)
        {
                delete_bucket(buckets[i]);
        }
}


/**
 * Add to bucket
 *
 * If bucket empty just add element
 * Else If element lower than current top of bucket, make element top
 * Else move through bucket and insert value at correct location
 *
 * */
void insert(Node **head, int val)
{
        Node *new_node = make_node(val);

        if ((*head) == NULL)
        {
                (*head) = new_node;
        }
        else if (new_node->n < (*head)->n)
        {
                new_node->next = (*head);
                (*head) = new_node;
        }
        else
        {
                Node *current = (*head);
                Node *previous;

                while (current != NULL && new_node->n >= current->n)
                {
                        previous = current;
                        current = current->next;
                }

                previous->next = new_node;

                if (current != NULL)
                {
                        new_node->next = current;
                }
        }
}


int pick_bucket(int n, int max, int len)
{
        return (n * len) / (max + 1);
}


Node *make_node(int val)
{
        Node *new_node = malloc(sizeof(*new_node));

        if (new_node == NULL)
        {
                fprintf(stderr, "Failed to allocate memory for node.\n");
                exit(EXIT_FAILURE);
        }

        new_node->n = val;
        new_node->next = NULL;

        return new_node;
}


void print_bucket(Node *node_ptr)
{
      while (node_ptr != NULL)
      {
             printf("%d", node_ptr->n);
             node_ptr = node_ptr->next;

             if(node_ptr != NULL)
             {
                     printf("-->");
             }
      }
      printf("\n");
}


void print_all_buckets(Node *buckets[], int len)
{
        for (int i = 0; i < len; i++)
        {
                if (buckets[i] != NULL)
                {
                        print_bucket(buckets[i]);
                }
        }
}


void delete_bucket(Node *node)
{
        while (node != NULL)
        {
                Node *temp = node;
                node = node->next;
                free(temp);
        }
}
