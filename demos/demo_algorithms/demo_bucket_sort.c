#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "demo_algorithms_shared.h"


int pick_bucket(int n, int max, int len);
void init_buckets(Node *buckets[], int len);
void print_bucket(Node *node_ptr);
void print_all_buckets(Node *buckets[], int len);
Node *make_node(int val);
void bucket_sort(int array[], int len, int max);
void scatter(Node *buckets[], int array[], int len, int max);
void gather(Node *buckets[], int array[], int len);
void insert(Node **head, int val);
void delete_bucket(Node *node);
void delete_buckets(Node *buckets[], int len);


int main(void)
{
        int array[] = {123,643,901,456,540,167,376,643,267,471,
                       347,1000,199,55,509,157,209,714,90,324,
                       1,777,462};
        int len = sizeof(array) / sizeof(array[0]);
        int max = find_max_integer(array, len);

        printf("\nInitial array\n");
        print_array(array, len);
        printf("\n\nArray length: %d\n", len);

        bucket_sort(array, len, max);

        printf("\nSorted array\n");
        print_array(array, len);
        
        printf("\n\nBUCKET SORT\n");
        printf("Time complexity: O(n+k)\n");
}


void bucket_sort(int array[], int len, int max)
{
        Node *buckets[len];

        init_buckets(buckets, len);

        scatter(buckets, array, len, max);

        printf("\nBucketed values\n");
        print_all_buckets(buckets, len);

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


void scatter(Node *buckets[], int array[], int len, int max)
{
        for (int i = 0; i < len; i++)
        {
                int bucket = pick_bucket(array[i], max, len);
                insert(&buckets[bucket], array[i]);
        }
}


void gather(Node *buckets[], int array[], int len)
{
        int index = 0;
        Node *node_ptr;

        for (int i = 0; i < len; i++)
        {
                node_ptr = buckets[i];

                while (node_ptr != NULL)
                {
                        array[index] = node_ptr->n;
                        index++;
                        node_ptr = node_ptr->next;
                }
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


void delete_buckets(Node *buckets[], int len)
{
        for (int i = 0; i < len; i++)
        {
                delete_bucket(buckets[i]);
        }
}
