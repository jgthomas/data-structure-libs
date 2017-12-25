#include <stdio.h>
#include <stdbool.h>
#include <BCUnit/Basic.h>
#include <BCUnit/BCUnit.h>
#include "tools/printing.h"
#include "tools/comparison.h"
#include "tests/shared_test.h"
#include "tests/test_sort_defs.h"
#include "algorithms/bubble_sort.h"


void testBASIC_SORTING(void)
{
        TestCase **tests = basic_tests(NUM_TESTS);

        for (int i = 0; i < NUM_TESTS; i++)
        {
                CU_ASSERT_FALSE(arrays_match(tests[i]->test, tests[i]->answer, tests[i]->data_size, tests[i]->elem_size, tests[i]->equal));
                //print_sequence(tests[i]->test, tests[i]->data_size, tests[i]->elem_size, tests[i]->print);
                bubble_sort(tests[i]->test, tests[i]->data_size, tests[i]->elem_size, tests[i]->compare);
                CU_ASSERT_TRUE(arrays_match(tests[i]->test, tests[i]->answer, tests[i]->data_size, tests[i]->elem_size, tests[i]->equal));
                //print_sequence(tests[i]->test, tests[i]->data_size, tests[i]->elem_size, tests[i]->print);
        }

        clean_tests(tests, NUM_TESTS);
}


void testEMPTY_LIST(void)
{
        TestCase **tests = empty_test(NUM_TESTS);

        for (int i = 0; i < NUM_TESTS; i++)
        {
                CU_ASSERT_TRUE(arrays_match(tests[i]->test, tests[i]->answer, tests[i]->data_size, tests[i]->elem_size, tests[i]->equal));
                //print_sequence(tests[i]->test, tests[i]->data_size, tests[i]->elem_size, tests[i]->print);
                bubble_sort(tests[i]->test, tests[i]->data_size, tests[i]->elem_size, tests[i]->compare);
                CU_ASSERT_TRUE(arrays_match(tests[i]->test, tests[i]->answer, tests[i]->data_size, tests[i]->elem_size, tests[i]->equal));
                //print_sequence(tests[i]->test, tests[i]->data_size, tests[i]->elem_size, tests[i]->print);
        }

        clean_tests(tests, NUM_TESTS);
}


void testSINGLE_ELEMENT(void)
{
        TestCase **tests = single_element_test(NUM_TESTS);

        for (int i = 0; i < NUM_TESTS; i++)
        {
                CU_ASSERT_TRUE(arrays_match(tests[i]->test, tests[i]->answer, tests[i]->data_size, tests[i]->elem_size, tests[i]->equal));
                //print_sequence(tests[i]->test, tests[i]->data_size, tests[i]->elem_size, tests[i]->print);
                bubble_sort(tests[i]->test, tests[i]->data_size, tests[i]->elem_size, tests[i]->compare);
                CU_ASSERT_TRUE(arrays_match(tests[i]->test, tests[i]->answer, tests[i]->data_size, tests[i]->elem_size, tests[i]->equal));
                //print_sequence(tests[i]->test, tests[i]->data_size, tests[i]->elem_size, tests[i]->print);
        }

        clean_tests(tests, NUM_TESTS);
}


void testREPEAT_ELEMENT(void)
{
        TestCase **tests = repeat_element_test(NUM_TESTS);

        for (int i = 0; i < NUM_TESTS; i++)
        {
                CU_ASSERT_FALSE(arrays_match(tests[i]->test, tests[i]->answer, tests[i]->data_size, tests[i]->elem_size, tests[i]->equal));
                //print_sequence(tests[i]->test, tests[i]->data_size, tests[i]->elem_size, tests[i]->print);
                bubble_sort(tests[i]->test, tests[i]->data_size, tests[i]->elem_size, tests[i]->compare);
                CU_ASSERT_TRUE(arrays_match(tests[i]->test, tests[i]->answer, tests[i]->data_size, tests[i]->elem_size, tests[i]->equal));
                //print_sequence(tests[i]->test, tests[i]->data_size, tests[i]->elem_size, tests[i]->print);
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
        suite = CU_add_suite("Bubble Sort", 0, 0);
        if (NULL == suite)
        {
                CU_cleanup_registry();
                return CU_get_error();
        }

        // add tests
        if (NULL == CU_add_test(suite, "Basic sorting", testBASIC_SORTING) ||
            NULL == CU_add_test(suite, "Empty arrays", testEMPTY_LIST) ||
            NULL == CU_add_test(suite, "Single element", testSINGLE_ELEMENT) ||
            NULL == CU_add_test(suite, "Repeat elements", testREPEAT_ELEMENT))
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
