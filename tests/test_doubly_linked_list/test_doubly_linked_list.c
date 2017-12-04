#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <BCUnit/Basic.h>
#include <BCUnit/BCUnit.h>
#include "tests/shared_test.h"
#include "tools/printing.h"
#include "tools/comparison.h"
#include "data_structures/doubly_linked_list.h"


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


void testDL_LIST_PUSH(void)
{
        TestCase **tests = make_tests(NUM_TESTS);

        for (int i = 0; i < NUM_TESTS; i++)
        {
                DllNode *head = DL_list_init();
                DL_list_add_data(&head, tests[i]->test, tests[i]->data_size, tests[i]->elem_size, DL_list_push);
                CU_ASSERT_TRUE(dll_array_match(head, tests[i]->answer, tests[i]->data_size, tests[i]->elem_size, tests[i]->equal));
                DL_list_delete(head);
        }

        clean_tests(tests, NUM_TESTS);
}


void testDL_LIST_APPEND(void)
{
        TestCase **tests = make_tests(NUM_TESTS);

        for (int i = 0; i < NUM_TESTS; i++)
        {
                DllNode *head = DL_list_init();
                DL_list_add_data(&head, tests[i]->test, tests[i]->data_size, tests[i]->elem_size, DL_list_append);
                CU_ASSERT_TRUE(dll_array_match(head, tests[i]->test, tests[i]->data_size, tests[i]->elem_size, tests[i]->equal));
                DL_list_delete(head);
        }

        clean_tests(tests, NUM_TESTS);
}


void testDL_LIST_REVERSE(void)
{
        TestCase **tests = make_tests(NUM_TESTS);

        for (int i = 0; i < NUM_TESTS; i++)
        {
                DllNode *head = DL_list_init();
                DL_list_add_data(&head, tests[i]->test, tests[i]->data_size, tests[i]->elem_size, DL_list_push);
                DL_list_reverse(&head);
                CU_ASSERT_TRUE(dll_array_match(head, tests[i]->test, tests[i]->data_size, tests[i]->elem_size, tests[i]->equal));
                DL_list_delete(head);
        }

        clean_tests(tests, NUM_TESTS);
}


void testDL_LIST_DELETE_FIRST_ELEMENT(void)
{
        TestCase **tests = make_tests(NUM_TESTS);

        int new_answer_int[] = {10,46,13,15};
        char new_answer_char[] = {'t','r','a','e'};
        char *new_answer_string[] = {"armadillo",
                                     "elephant",
                                     "moose",
                                     "zebra"};

        for (int i = 0; i < NUM_TESTS; i++)
        {
                DllNode *head = DL_list_init();
                DL_list_add_data(&head, tests[i]->test, tests[i]->data_size, tests[i]->elem_size, DL_list_push);

                CU_ASSERT_TRUE(dll_array_match(head, tests[i]->answer, tests[i]->data_size, tests[i]->elem_size, tests[i]->equal));

                DL_list_delete_index(&head, 0);

                if (i == 0)
                {
                        tests[i]->answer = new_answer_int;
                        tests[i]->data_size = sizeof(new_answer_int);
                }
                else if (i == 1)
                {
                        tests[i]->answer = new_answer_char;
                        tests[i]->data_size = sizeof(new_answer_char);
                }
                else if (i == 2)
                {
                        tests[i]->answer = new_answer_string;
                        tests[i]->data_size = sizeof(new_answer_string);
                }

                CU_ASSERT_TRUE(dll_array_match(head, tests[i]->answer, tests[i]->data_size, tests[i]->elem_size, tests[i]->equal));
                DL_list_delete(head);
        }

        clean_tests(tests, NUM_TESTS);
}


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
        if (NULL == CU_add_test(suite, "Pushing to list", testDL_LIST_PUSH) ||
            NULL == CU_add_test(suite, "Appending to list", testDL_LIST_APPEND) ||
            NULL == CU_add_test(suite, "Reverse list", testDL_LIST_REVERSE) ||
            NULL == CU_add_test(suite, "Delete first element", testDL_LIST_DELETE_FIRST_ELEMENT))
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
