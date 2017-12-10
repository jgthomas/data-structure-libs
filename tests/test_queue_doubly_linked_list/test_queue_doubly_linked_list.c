#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <BCUnit/Basic.h>
#include <BCUnit/BCUnit.h>
#include "tests/shared_test.h"
#include "tools/printing.h"
#include "tools/comparison.h"
#include "data_structures/doubly_linked_list.h"
#include "data_structures/queue_doubly_linked_list.h"


enum {NUM_TESTS = 3};


int test_int[] = {15,13,46,10,1};
int answer_int[] = {1,10,46,13,15};

char test_char[] = {'e','a','r','t','b'};
char answer_char[] = {'b','t','r','a','e'};

char *test_string[] = {"zebra",
                       "moose",
                       "elephant",
                       "armadillo",
                       "coyote"};

char *answer_string[] = {"coyote",
                         "armadillo",
                         "elephant",
                         "moose",
                         "zebra"};
int LENGTH = 5;


TestCase **make_tests(int num_tests)
{        
        TestCase **test_array = init_tests(num_tests);

        TestCase *testint = new_test(test_int, answer_int, sizeof(test_int), sizeof(int), equal_int, less_than_int, print_int);
        TestCase *testchar = new_test(test_char, answer_char, sizeof(test_char), sizeof(char), equal_char, less_than_char, print_char);
        TestCase *teststring = new_test(test_string, answer_string, sizeof(test_string), sizeof(char *), equal_string, less_than_string, print_string);

        test_array[0] = testint;
        test_array[1] = testchar;
        test_array[2] = teststring;

        return test_array;
}


void testQUEUE_LOAD_DATA(void)
{
        TestCase **tests = make_tests(NUM_TESTS);

        for (int i = 0; i < NUM_TESTS; i++)
        {
                Queue *queue = queue_init();
                queue_add_data(queue, tests[i]->test, tests[i]->data_size, tests[i]->elem_size);
                CU_ASSERT_TRUE(dll_array_match(queue->back, tests[i]->answer, tests[i]->data_size, tests[i]->elem_size, tests[i]->equal));

                queue_delete(queue);
        }

        clean_tests(tests, NUM_TESTS);
}


void testQUEUE_PEEK(void)
{
        TestCase **tests = make_tests(NUM_TESTS);

        for (int i = 0; i < NUM_TESTS; i++)
        {
                Queue *queue = queue_init();
                queue_add_data(queue, tests[i]->test, tests[i]->data_size, tests[i]->elem_size);
                CU_ASSERT_TRUE(dll_array_match(queue->back, tests[i]->answer, tests[i]->data_size, tests[i]->elem_size, tests[i]->equal));

                void *peeked = queue_peek(queue);
                void *should_be_front = tests[i]->test + tests[i]->elem_size * (LENGTH-LENGTH);
                CU_ASSERT_TRUE(tests[i]->equal(peeked, should_be_front));

                queue_delete(queue);
        }

        clean_tests(tests, NUM_TESTS);
}


/*void testDEQUEUE(void)
{

        TestCase **tests = make_tests(NUM_TESTS);

        for (int i = 0; i < NUM_TESTS; i++)
        {

                Queue *queue = queue_init();
                queue_add_data(queue, tests[i]->test, tests[i]->data_size, tests[i]->elem_size);
                CU_ASSERT_TRUE(match(tests[i]->test, queue->array, tests[i]->data_size, tests[i]->elem_size, tests[i]->equal));

                dequeue(queue);
                void *peeked = queue_peek(queue);
                void *should_be_front = tests[i]->test + tests[i]->elem_size * (LENGTH-(LENGTH-1));
                CU_ASSERT_TRUE(tests[i]->equal(peeked, should_be_front));
                CU_ASSERT_EQUAL(queue->front, LENGTH-(LENGTH-1));

                queue_delete(queue);
        }

        clean_tests(tests, NUM_TESTS);
}*/


int main(void)
{
        // test suite
        CU_pSuite suite = NULL;

        // initialize registry
        if (CUE_SUCCESS != CU_initialize_registry())
        {
                return CU_get_error();
        }

        // add suite
        suite = CU_add_suite("Binary heap", 0, 0);
        if (NULL == suite)
        {
                CU_cleanup_registry();
                return CU_get_error();
        }

        // add tests
        if (NULL == CU_add_test(suite, "Load data into queue", testQUEUE_LOAD_DATA) ||
            NULL == CU_add_test(suite, "Peek returns front of queue", testQUEUE_PEEK))
    //        NULL == CU_add_test(suite, "Pop removes element from top", testDEQUEUE))
        {
                CU_cleanup_registry();
                return CU_get_error();
        }

        // run tests
        CU_basic_set_mode(CU_BRM_VERBOSE);
        CU_basic_run_tests();
        CU_cleanup_registry();
        return CU_get_error();
}
