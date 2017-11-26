#include <stdio.h>
#include <stdbool.h>
#include <BCUnit/Basic.h>
#include <BCUnit/BCUnit.h>
#include "tools/printing.h"
#include "tools/comparison.h"
#include "tests/shared_test.h"
#include "algorithms/shared_sort.h"
#include "algorithms/bubble_sort.h"
#include "algorithms/selection_sort.h"


enum {NUM_TESTS = 3};


int test_int[] = {1,7,6,5,22,8,1,15,74};
char test_char[] = {'c','d','b','f','g','a'};
char *test_string[] = {"abacus",
                       "zebra",
                       "doggy",
                       "thinning",
                       "soldier"};

int answer_int[] = {1,1,5,6,7,8,15,22,74};
char answer_char[] = {'a','b','c','d','f','g'};
char *answer_string[] = {"abacus",
                         "doggy",
                         "soldier",
                         "thinning",
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


void testBUBBLE_SORT(void)
{
        TestCase **tests = make_tests(NUM_TESTS);

        for (int i = 0; i < NUM_TESTS; i++)
        {
                CU_ASSERT_FALSE(arrays_match(tests[i]->test, tests[i]->answer, tests[i]->data_size, tests[i]->elem_size, tests[i]->equal));
                bubble_sort(tests[i]->test, tests[i]->data_size, tests[i]->elem_size, tests[i]->compare);
                CU_ASSERT_TRUE(arrays_match(tests[i]->test, tests[i]->answer, tests[i]->data_size, tests[i]->elem_size, tests[i]->equal));
                //print_array(tests[i]->test, tests[i]->data_size, tests[i]->elem_size, tests[i]->print);
        }

        clean_tests(tests, NUM_TESTS);
}


void testSELECTION_SORT(void)
{
        TestCase **tests = make_tests(NUM_TESTS);

        for (int i = 0; i < NUM_TESTS; i++)
        {
                CU_ASSERT_FALSE(arrays_match(tests[i]->test, tests[i]->answer, tests[i]->data_size, tests[i]->elem_size, tests[i]->equal));
                selection_sort(tests[i]->test, tests[i]->data_size, tests[i]->elem_size, tests[i]->compare);
                CU_ASSERT_TRUE(arrays_match(tests[i]->test, tests[i]->answer, tests[i]->data_size, tests[i]->elem_size, tests[i]->equal));
                //print_array(tests[i]->test, tests[i]->data_size, tests[i]->elem_size, tests[i]->print);
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
        suite = CU_add_suite("Sorting Algorithms", 0, 0);
        if (NULL == suite)
        {
                CU_cleanup_registry();
                return CU_get_error();
        }

        // add tests
        if (NULL == CU_add_test(suite, "Bubble sort", testBUBBLE_SORT) ||
            NULL == CU_add_test(suite, "Selection sort", testSELECTION_SORT))
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
