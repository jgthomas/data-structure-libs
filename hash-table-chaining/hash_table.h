#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdbool.h>
#include "node.h"
#include "hash_types.h"

typedef struct HashTable {
        Node **buckets;
        int hashtable_size;
}
HashTable;

HashTable *create_hashtable(int hashtable_size);
void insert_record(HashTable *hashtable, void *new_data, TypeData *data);
bool search(HashTable *hashtable, void *key, TypeData *data_type);

#endif
