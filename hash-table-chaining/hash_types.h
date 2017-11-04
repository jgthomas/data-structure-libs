#ifndef HASH_TYPES_H
#define HASH_TYPES_H

#include <stdlib.h>
#include <stdbool.h>


typedef struct TypeData {
    unsigned int (*hash)(void *node_data);
    bool (*compare)(void *search, void *node_data);
    void (*print)(void *node_data);
    size_t size;
}
TypeData;


extern TypeData String;
extern TypeData Integer;

#endif
