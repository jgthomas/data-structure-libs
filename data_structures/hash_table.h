#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdbool.h>
#include "linked_list.h"

typedef struct HashTable {
        Node **buckets;
        int hashtable_size;
}
HashTable;


typedef struct TypeData {
    unsigned int (*hash)(void *node_data);
    bool (*compare)(void *search, void *node_data);
    void (*print)(void *node_data);
    size_t size;
}
TypeData;


extern TypeData String;
extern TypeData Integer;


HashTable *hashtable_create(int hashtable_size);
void hashtable_insert(HashTable *hashtable, void *new_data, TypeData *data);
bool hashtable_search(HashTable *hashtable, void *key, TypeData *data_type);
bool hashtable_search_promote(HashTable *hashtable, void *key, TypeData *data_type);
void hashtable_delete(HashTable *hashtable);
void hashtable_key_delete(HashTable *hashtable, void *key, TypeData *data_type);
void hashtable_print_chain(HashTable *hashtable, void *key, TypeData *data_type);
void hashtable_add_data(HashTable *hashtable, void *data, size_t data_size, TypeData *data_type);
Node *hashtable_get_bucket(HashTable *hashtable, void *key, TypeData *data_type);

#endif
