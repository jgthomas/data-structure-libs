#include <stdio.h>
#include <stdlib.h>
#include "data_structures/linked_list.h"
#include "tools/general_distro_sort.h"
#include "bucket_sort.h"


void bucket_sort(Record *record_array[], int len, int max)
{
        Node *buckets[len];
        init_buckets(buckets, len);
        scatter(buckets, record_array, len, max);
        gather(buckets, record_array, len);
        delete_buckets(buckets, len);
}


void init_buckets(Node *buckets[], int len)
{
        for (int bucket = 0; bucket < len; bucket++)
        {
                buckets[bucket] = NULL;
        }
}


void scatter(Node *buckets[],
             Record *record_array[],
             int len,
             int max)
{
        for (int i = 0; i < len; i++)
        {
                int bucket = pick_bucket(record_array[i]->key, max, len);
                insert(&buckets[bucket], record_array[i]);
        }
}


void gather(Node *buckets[],
            Record *record_array[],
            int len)
{
        int index = 0;

        for (int i = 0; i < len; i++)
        {
                Node *node_ptr = buckets[i];

                while (node_ptr != NULL)
                {
                        record_array[index] = node_ptr->data;
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


void delete_bucket(Node *node)
{
        while (node != NULL)
        {
                Node *temp = node;
                node = node->next;
                free(temp);
        }
}


Node *make_node(Record *record)
{
        Node *new_node = malloc(sizeof(*new_node));

        if (new_node == NULL)
        {
                fprintf(stderr, "Failed to allocate memory for node.\n");
                exit(EXIT_FAILURE);
        }

        new_node->data = record;
        new_node->next = NULL;

        return new_node;
}


void insert(Node **head, Record *record)
{
        Node *new_node = make_node(record);

        if ((*head) == NULL)
        {
                (*head) = new_node;
                return;
        }

        Node *current = (*head);
        Node *previous;
        Record *current_data = (Record *)current->data;

        if (record->key < current_data->key)
        {
                new_node->next = (*head);
                (*head) = new_node;
        }
        else
        {

                while (current != NULL && record->key >= current_data->key)
                {
                        previous = current;
                        current = current->next;

                        if (current != NULL)
                        {
                                current_data = (Record *)current->data;
                        }
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
