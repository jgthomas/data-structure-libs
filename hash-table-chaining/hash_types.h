#include <stdlib.h>
#include <stdbool.h>
#include "node.h"


typedef struct TypeData {
    unsigned int (*hash)(void *node_data);
    bool (*compare)(void *search, void *node_data);
    void (*print)(void *node_data);
    size_t data_size;
}
TypeData;


extern TypeData String;
extern TypeData Integer;
