#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "comparison.h"
#include "hash_table.h"
#include "hash_functions.h"


// pull hash function from library
unsigned int (*hash_func)(unsigned int n) = dumb_hash;
//unsigned int (*hash_func)(const char *str) = simple_string_hash;

unsigned int hash_int(void *data)
{
        return hash_func(*(int *)data);
}

/*unsigned int hash_string(void *data)
{
        return hash_func(*(char **)data);
}*/


int main()
{
    int hashtable_size = 65536;

    //Record **hashtable = malloc(sizeof(Record *) * hashtable_size);
    Record **hashtable = new_hashtable(hashtable_size);

    // ints to hash
    int k = 1920;
    int value = 2345;
    int k2 = 1066;
    int value2 = 9000;

    Record *r = new_record(&k, &value);
    Record *r2 = new_record(&k2, &value2);

    insert(hashtable, r, hashtable_size, hash_int);
    insert(hashtable, r2, hashtable_size, hash_int);

    print_hash_table(hashtable, hashtable_size, print_int);

    Record *found = search(hashtable, hashtable_size, &k, equal_int, hash_int);
    print_int(found);
    printf("%d\n", hash_int(found->key));

    // string to hash
    /*const char *key_s = "hello";
    const char *val_s = "tool";
    printf("%u\n", hash(key_s));

    // add strings
    Record *r = new_record(&key_s, &val_s);
    insert(hashtable, r, hashtable_size);
    print_hash_table(hashtable, hashtable_size, print_string);*/

    delete_table(hashtable, hashtable_size);
}
