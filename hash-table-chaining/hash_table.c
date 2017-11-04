#include <stdlib.h>
#include <stdbool.h>
#include "node.h"
#include "list_funcs.h"
#include "hash_table.h"
#include "hash_types.h"


HashTable *create_hashtable(int hashtable_size)
{
        HashTable *hashtable = malloc(sizeof(*hashtable));
        hashtable->buckets = malloc(sizeof(Node *) * hashtable_size);
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
