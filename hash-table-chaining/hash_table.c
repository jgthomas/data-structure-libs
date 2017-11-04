#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linked_list.h"
#include "hash_table.h"
#include "hash_functions.h"
#include "printing.h"
#include "comparison.h"


TypeData String = { .hash = hash_string,
                    .compare = equal_string,
                    .print = print_string,
                    .size = sizeof(char *)};


TypeData Integer = { .hash = hash_int,
                     .compare = equal_int,
                     .print = print_int,
                     .size = sizeof(int) };


HashTable *create_hashtable(int hashtable_size)
{
        HashTable *hashtable = malloc(sizeof(*hashtable));

        if (hashtable == NULL)
        {
                fprintf(stderr, "Failed to allocate memory for hashtable\n");
                exit(EXIT_FAILURE);
        }

        hashtable->buckets = malloc(sizeof(Node *) * hashtable_size);

        if (hashtable->buckets == NULL)
        {
                fprintf(stderr, "Failed to allocate memory for buckets\n");
                exit(EXIT_FAILURE);
        }

        for (int bucket = 0; bucket < hashtable_size; bucket++)
        {
                hashtable->buckets[bucket] = NULL;
        }

        hashtable->hashtable_size = hashtable_size;

        return hashtable;
}


void insert_record(HashTable *hashtable, void *key, TypeData *data_type)
{
        unsigned int bucket = data_type->hash(key) % hashtable->hashtable_size;
        push(&hashtable->buckets[bucket], key, data_type->size);
}


bool search(HashTable *hashtable, void *key, TypeData *data_type)
{
        unsigned int bucket = data_type->hash(key) % hashtable->hashtable_size;

        if (list_contains(hashtable->buckets[bucket], key, data_type->compare))
        {
                return true;
        }

        return false;
}


void delete_hashtable(HashTable *hashtable)
{
        for (int bucket = 0; bucket < hashtable->hashtable_size; bucket++)
        {
                delete_list(hashtable->buckets[bucket]);
        }
        free(hashtable->buckets);
        free(hashtable);
}
