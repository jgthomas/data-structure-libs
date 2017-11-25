#include <stdio.h>
#include <stdbool.h>
#include "linked_list.h"
#include "hash_table.h"


int main()
{
        // TEST: initialize hash table
        int hashtable_size = 65536;
        HashTable *hashtable = hashtable_create(hashtable_size);
        printf("hash table size: %d\n", hashtable_size);
        printf("hash table location %p\n", (void *)hashtable);

        // TEST: load data into hash table
        int arr_len = 6;
        char *arr[] = {"hello",
                       "everyone",
                       "of",
                       "jr",
                       "functionality",
                       "house"};

        for (int i = 0; i < arr_len; i++)
        {
                hashtable_insert(hashtable, &arr[i], &String);
        }

        // TEST: basic searching
        char *to_find = "house";
        hashtable_print_chain(hashtable, &to_find, &String);
        if (hashtable_search(hashtable, &to_find, &String))
        {
                printf("yes %s is found\n", to_find);
        }
        else
        {
                printf("%s not found\n", to_find);
        }

        // TEST: search and move found item to front of list
        char *to_promote = "functionality";
        printf("promoting 'functionality' to front of list\n");
        if (hashtable_search_promote(hashtable, &to_promote, &String))
        {
                printf("switching...\n");
        }
        hashtable_print_chain(hashtable, &to_promote, &String);

        // TEST: delete a key
        printf("deleting %s...\n", to_find);
        hashtable_key_delete(hashtable, &to_find, &String);
        if (hashtable_search(hashtable, &to_find, &String))
        {
                printf("yes %s is found\n", to_find);
        }
        else
        {
                printf("%s not found\n", to_find);
        }

        // TEST: delete hash table
        hashtable_delete(hashtable);

        return 0;
}
