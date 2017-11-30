#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hash_table_probing.h"


Record **new_hashtable(int hashtable_size)
{
    Record **hashtable = malloc(sizeof(Record *) * hashtable_size);

    if (hashtable == NULL)
    {
        fprintf(stderr, "Failed to allocate memory for hashtable\n");
        exit(1);
    }

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
        fprintf(stderr, "Failed to allocate memory for record\n");
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


void delete_key(Record **hashtable,
                int hashtable_size,
                void *key,
                bool (*cmp_ptr)(void *, void *),
                unsigned int (*hash_ptr)(void *))
{
    unsigned int pos = hash_ptr(key) % hashtable_size;

    while (hashtable[pos] != NULL)
    {
            if(cmp_ptr(key, hashtable[pos]->key))
            {
                    break;
            }
            else
            {
                    pos = (pos + 1) % hashtable_size;
            }

            if (hashtable[pos] == NULL)
            {
                    return;
            }

            free(hashtable[pos]);
            hashtable[pos] = NULL;
    }

    // re-insert elements so no empty cells for probing
    // slow, so consider switching to a flag "empty but deleted"
    // http://www.cs.rmit.edu.au/online/blackboard/chapter/05/documents/contribute/chapter/05/chaining.html
    for (pos = (pos + 1) % hashtable_size;
         hashtable[pos] != NULL;
         pos = (pos + 1) % hashtable_size)
    {
            Record *r = hashtable[pos];
            hashtable[pos] = NULL;
            insert(hashtable, r, hashtable_size, hash_ptr);
    }
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


void print_int_kv(Record *r)
{
    printf("key: %d, value: %d\n", *(int *)r->key, *(int *)r->value);
}


void print_string_kv(Record *r)
{
    printf("key: %s, value: %s\n", *(char **)r->key, *(char **)r->value);
}
