#include <stdio.h>
#include <stdbool.h>
#include "node.h"
#include "list_funcs.h"
#include "hash_table.h"


int main()
{
        int hashtable_size = 65536;

        HashTable *hashtable = create_hashtable(hashtable_size);

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
                insert_record(hashtable, &arr[i], &String);
        }

        char *to_find = "house";

        if (search(hashtable, &to_find, &String))
        {
                printf("yes\n");
        }

        return 0;
}
