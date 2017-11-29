#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tools/hash_functions.h"
#include "tools/printing.h"
#include "tools/comparison.h"
#include "data_structures/linked_list.h"
#include "hash_table.h"


TypeData String = { .hash = hash_string,
                    .compare = equal_string,
                    .print = print_string,
                    .size = sizeof(char *)};


TypeData Integer = { .hash = hash_int,
                     .compare = equal_int,
                     .print = print_int,
                     .size = sizeof(int) };


HashTable *hashtable_create(int hashtable_size)
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


void hashtable_insert(HashTable *hashtable, void *key, TypeData *data_type)
{
        unsigned int bucket = data_type->hash(key) % hashtable->hashtable_size;
        list_push(&hashtable->buckets[bucket], key, data_type->size);
}


void hashtable_key_delete(HashTable *hashtable, void *key, TypeData *data_type)
{
        unsigned int bucket = data_type->hash(key) % hashtable->hashtable_size;
        list_delete_value(&hashtable->buckets[bucket], key, data_type->compare);
}


bool hashtable_search(HashTable *hashtable, void *key, TypeData *data_type)
{
        unsigned int bucket = data_type->hash(key) % hashtable->hashtable_size;

        if (list_contains(hashtable->buckets[bucket], key, data_type->compare))
        {
                return true;
        }

        return false;
}


bool hashtable_search_promote(HashTable *hashtable, void *key, TypeData *data_type)
{
        unsigned int bucket = data_type->hash(key) % hashtable->hashtable_size;

        if (list_find_and_move(&hashtable->buckets[bucket], key, data_type->compare))
        {
                return true;
        }

        return false;
}


void hashtable_delete(HashTable *hashtable)
{
        for (int bucket = 0; bucket < hashtable->hashtable_size; bucket++)
        {
                list_delete(hashtable->buckets[bucket]);
        }
        free(hashtable->buckets);
        free(hashtable);
}


void hashtable_print_chain(HashTable *hashtable, void *key, TypeData *data_type)
{
        unsigned int bucket = data_type->hash(key) % hashtable->hashtable_size;

        if (!list_is_empty(hashtable->buckets[bucket]))
        {
                list_print_visual(hashtable->buckets[bucket], data_type->print);
        }
}
