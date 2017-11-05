#include <stdio.h>
#include <stdbool.h>
#include "linked_list.h"
#include "hash_table.h"


int main()
{
        int hashtable_size = 65536;

        HashTable *hashtable = hashtable_create(hashtable_size);

        printf("hash table size: %d\n", hashtable_size);
        printf("hash table location %p\n", (void *)hashtable);

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


        hashtable_delete(hashtable);

        return 0;
}
