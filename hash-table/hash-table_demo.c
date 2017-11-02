#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "comparison.h"
#include "hash_nodes.h"
#include "hash_funcs.h"


Record *new_record(void *key, void *value);
void insert(Record **hashtable, Record *r, int hashtable_size, unsigned int (*hash_ptr)(void *));
Record *search(Record **hashtable, int hashtable_size, void *key, bool (*cmp_ptr)(void *, void *), unsigned int (*hash_ptr)(void *));
void print_hash_table(Record **hashtable, int hashtable_size, void (*print_fptr)(Record *r));
void delete_table(Record **hashtable, int hashtable_size);
void print_int(Record *r);
void print_string(Record *r);
Record **new_hashtable(int hashtable_size);
unsigned int hash_int(void *data);
unsigned int hash_string(void *data);


// pull hash function from library
unsigned int (*hash_func)(unsigned int n) = dumb_hash;
//unsigned int (*hash_func)(const char *str) = simple_string_hash;




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


Record **new_hashtable(int hashtable_size)
{
    Record **hashtable = malloc(sizeof(Record *) * hashtable_size);

    for (int record = 0; record < hashtable_size; record++)
    {
            hashtable[record] = NULL;
    }

    return hashtable;
}


Record *new_record(void *key, void *value)
{
    Record *r = malloc(sizeof(*r));

    if (r == NULL)
    {
        printf("Failed to allocate memory\n");
        exit(1);
    }

    r->key = key;
    r->value = value;

    return r;
}


void insert(Record **hashtable,
            Record *r,
            int hashtable_size,
            unsigned int (*hash_ptr)(void *))
{
    unsigned int i = hash_ptr(r->key) % hashtable_size;
    
    while (hashtable[i] != NULL)
    {
        i = (i + 1) % hashtable_size;
    }
    hashtable[i] = r;
}


Record *search(Record **hashtable,
               int hashtable_size,
               void *key,
               bool (*cmp_ptr)(void *, void *),
               unsigned int (*hash_ptr)(void *)) 
{
    unsigned int i = hash_ptr(key) % hashtable_size;

    while (hashtable[i] != NULL)
    {
        if (cmp_ptr(key, hashtable[i]->key))
        {
            return hashtable[i];
        }        
        else
        {
            i = (i + 1) % hashtable_size;
        }
   }

   return NULL;
}


void delete_table(Record **hashtable, int hashtable_size)
{
    for (int i = 0; i < hashtable_size; i++)
    {
        free(hashtable[i]);
    }
    free(hashtable);
}


void print_hash_table(Record **hashtable,
                      int hashtable_size,
                      void (*print_fptr)(Record *r))
{
    for (int i = 0; i < hashtable_size; i++)
    {
        if (hashtable[i] != NULL)
        {
            print_fptr(hashtable[i]);
        }
    }
}


void print_int(Record *r)
{
    printf("key: %d, value: %d\n", *(int *)r->key, *(int *)r->value);
}


void print_string(Record *r)
{
    printf("key: %s, value: %s\n", *(char **)r->key, *(char **)r->value);
}


unsigned int hash_int(void *data)
{
        return hash_func(*(int *)data);
}

/*unsigned int hash_string(void *data)
{
        return hash_func(*(char **)data);
}*/
