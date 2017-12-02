#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "shared_test.h"
#include "../data_structures/linked_list.h"


TestCase **init_tests(int num_tests)
{
        TestCase **test_array = malloc(sizeof(TestCase *) * num_tests);

        if (test_array == NULL)
        {
                fprintf(stderr, "Failed to allocate memory for test array\n");
                exit(EXIT_FAILURE);
        }

        return test_array;
}


TestCase *new_test(void *test,
                   void *answer,
                   size_t data_size,
                   size_t elem_size,
                   bool (*equal)(void *x, void *y),
                   bool (*compare)(void *x, void *y),
                   void (*print)(void *x))
{
        TestCase *test_case = malloc(sizeof(*test_case));
        if (test_case == NULL)
        {
                fprintf(stderr, "Failed to allocate memory for test case\n");
                exit(EXIT_FAILURE);
        }

        test_case->test = malloc(sizeof(elem_size) * data_size/elem_size);
        if (test_case->test == NULL)
        {
                fprintf(stderr, "Failed to allocate memory for test case TEST\n");
                exit(EXIT_FAILURE);
        }
        copy_data(test_case->test, test, data_size, elem_size);

        test_case->answer = malloc(sizeof(elem_size) * data_size/elem_size);
        if (test_case->answer == NULL)
        {
                fprintf(stderr, "Failed to allocate memory for test case ANSWER\n");
                exit(EXIT_FAILURE);
        }
        copy_data(test_case->answer, answer, data_size, elem_size);
        
        test_case->data_size = data_size;
        test_case->elem_size = elem_size;
        test_case->equal = equal;
        test_case->compare = compare;
        test_case->print = print;

        return test_case;
}


void copy_data(void *test, void *data, size_t data_size, size_t elem_size)
{
        int len = data_size / elem_size;

        for (int i = 0; i < len; i++)
        {
               void *test_item = test + elem_size*i;
               void *data_item = data + elem_size*i;
               memcpy(test_item, data_item, elem_size);
        }
}


void clean_tests(TestCase **test_array, int num_tests)
{
        for (int i = 0; i < num_tests; i++)
        {
                free(test_array[i]->test);
                free(test_array[i]->answer);
                free(test_array[i]);
        }
        free(test_array);
}


bool arrays_match(void *array1,
                  void *array2,
                  size_t data_size,
                  size_t elem_size,
                  bool (*equal)(void *x, void *y))
{
        int length = data_size/elem_size;

        for (int i = 0; i < length; i++)
        {
                void *first = array1 + elem_size * i;
                void *second = array2 + elem_size * i;

                if (!equal(first, second))
                {
                        return false;
                }
        }
        return true;
}


bool match(void *array1,
           void *array2[],
           size_t data_size,
           size_t elem_size,
           bool (*equal)(void *x, void *y))
{
        int length = data_size/elem_size;

        for (int i = 0; i < length; i++)
        {
                void *first = array1 + elem_size * i;
                void *second = array2[i];

                if (!equal(first, second))
                {
                        return false;
                }
        }
        return true;
}


bool ll_array_match(Node *node,
                    void *array2,
                    size_t data_size,
                    size_t elem_size,
                    bool (*equal)(void *x, void *y))
{
        int length = data_size/elem_size;

        for (int i = 0; i < length; i++)
        {
                void *first = node->data;
                void *second = array2 + elem_size * i;

                if (!equal(first, second))
                {
                        return false;
                }

                node = node->next;
        }

        return true;
}
