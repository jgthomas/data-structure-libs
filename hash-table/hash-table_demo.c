#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "comparison.h"
#include "hash_table.h"
#include "hash_functions.h"


// pull hash function from library
unsigned int (*hash_func_int)(unsigned int n) = dumb_hash;
// wrapper for type
unsigned int hash_int(void *data)
{
        return hash_func_int(*(int *)data);
}

// same for strings
unsigned int (*hash_func_string)(const char *str) = simple_string_hash;
unsigned int hash_string(void *data)
{
        return hash_func_string(*(char **)data);
}


int main()
{
    /**
     * Integers
     *
     **/
    int hashtable_size = 65536;
    Record **hashtable = new_hashtable(hashtable_size);

    // ints to hash
    int k = 1920;
    int value = 2345;
    int k2 = 1066;
    int value2 = 9000;

    // make new records
    Record *r = new_record(&k, &value);
    Record *r2 = new_record(&k2, &value2);

    // insert into table
    insert(hashtable, r, hashtable_size, hash_int);
    insert(hashtable, r2, hashtable_size, hash_int);

    // print all key-value pairs
    print_hash_table(hashtable, hashtable_size, print_int_kv);

    // perform search and print results
    Record *found = search(hashtable, hashtable_size, &k, equal_int, hash_int);
    print_int_kv(found);

    // clean up hashtable
    delete_table(hashtable, hashtable_size);


    /**
     * Strings
     *
     **/
    Record **hashtable2 = new_hashtable(hashtable_size);

    char *key_s1 = "England";
    char *val_s1 = "London";
    char *key_s2 = "Scotland";
    char *val_s2 = "Edinburgh";

    Record *r3 = new_record(&key_s1, &val_s1);
    Record *r4 = new_record(&key_s2, &val_s2);

    insert(hashtable2, r3, hashtable_size, hash_string);
    insert(hashtable2, r4, hashtable_size, hash_string);

    print_hash_table(hashtable2, hashtable_size, print_string_kv);

    Record *found2 = search(hashtable2, hashtable_size, &key_s1, equal_string, hash_string);
    print_string_kv(found2);

    delete_table(hashtable2, hashtable_size);
}
