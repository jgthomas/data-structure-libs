#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linked_list.h"
#include "comparison.h"
#include "printing.h"


int main()
{
        Node *start = NULL;
        if (!list_is_empty(start))
        {
            printf("List length: %d\n", list_length(start));
            printf("\n");
        }
        
        /**
         * INTEGERS
         * 
         * */
        unsigned int_size = sizeof(int);
        int arr[] = {10, 20, 30, 40, 50};
        
        for (int i = 4; i >= 0; i--)
        {
            list_push(&start, &arr[i], int_size);
        }
        printf("Integer linked list: \n");
        list_print_visual(start, print_int);
        printf("List length: %d\n", list_length(start));
        int newer_i = 22;
        list_append(&start, &newer_i, int_size);
        list_print_visual(start, print_int);
        printf("List length: %d\n", list_length(start));
        list_reverse(&start);
        list_print_visual(start, print_int);
        int find_i = 30;
        if (list_contains(start, &find_i, equal_int))
        {
            printf("yes\n");
        }

        int find_i_m = 40;
        if (list_find_and_move(&start, &find_i_m, equal_int))
        {
                printf("found '%d' and moved to front of list\n", find_i_m);
        }
        list_print_visual(start, print_int);
        

        int to_insert = 100;
        int pos = 3;
        list_insert(&start, &to_insert, int_size, pos);
        list_print_visual(start, print_int);

        int to_del_idx = 2;
        list_delete_index(&start, to_del_idx);
        printf("deleted node with index %d\n", to_del_idx);
        list_print_visual(start, print_int);

        int to_del_val = 100;
        list_delete_value(&start, &to_del_val, equal_int);
        printf("deleted node with value %d\n", to_del_val);
        list_print_visual(start, print_int);

        printf("\n");
        
        list_delete(start);
        start = NULL;
        
        
        /**
        * FLOATS
        * 
        * */
        unsigned float_size = sizeof(float);
        float arr2[] = {10.1, 20.2, 30.3, 40.4, 50.5};
        
        for (int i = 4; i >= 0; i--)
        {
           list_push(&start, &arr2[i], float_size);
        }
        printf("Float linked list: \n");
        list_print_visual(start, print_float);
        printf("List length: %d\n", list_length(start));
        float newer_f = 22.22;
        list_append(&start, &newer_f, float_size);
        list_print_visual(start, print_float);
        printf("List length: %d\n", list_length(start));
        list_reverse(&start);
        list_print_visual(start, print_float);
        printf("\n");
        
        list_delete(start);
        start = NULL;
        
        
        /**
        * CHARS
        * 
        * */
        unsigned char_size = sizeof(char);
        char arr3[] = {'a', 'b', 'c', 'd', 'e'};
        
        for (int i = 4; i >= 0; i--)
        {
            list_push(&start, &arr3[i], char_size);
        }
        printf("Char linked list: \n");
        list_print_visual(start, print_char);
        printf("List length: %d\n", list_length(start));
        char newer_c = 'W';
        list_append(&start, &newer_c, char_size);
        list_print_visual(start, print_char);
        printf("List length: %d\n", list_length(start));
        list_reverse(&start);
        list_print_visual(start, print_char);
        printf("\n");
        
        list_delete(start);
        start = NULL;
        
        
        /**
        * STRINGS
        * 
        * */
        unsigned string_size = sizeof(char *);
        char *arr4[] = {"hello", "everyone"};
        
        for (int i = 1; i >= 0; i--)
        {
            list_push(&start, &arr4[i], string_size);
        }
        
        printf("String linked list: \n");
        list_print_visual(start, print_string);
        printf("List length: %d\n", list_length(start));
        char *newer_s = "Hippo";
        list_append(&start, &newer_s, string_size);
        list_print_visual(start, print_string);
        printf("List length: %d\n", list_length(start));
        list_reverse(&start);
        list_print_visual(start, print_string);
        char *find_s = "Hippo";
        if (list_contains(start, &find_s, equal_string))
        {
            printf("yes\n");
        }
        printf("\n");
        
        list_delete(start);
        start = NULL;
 
        return 0;
}

