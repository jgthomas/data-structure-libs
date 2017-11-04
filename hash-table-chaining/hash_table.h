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


HashTable *create_hashtable(int hashtable_size);
void insert_record(HashTable *hashtable, void *new_data, TypeData *data);
bool search(HashTable *hashtable, void *key, TypeData *data_type);

#endif
