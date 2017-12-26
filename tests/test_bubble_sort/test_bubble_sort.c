#include <stdio.h>
#include <stdbool.h>
#include <BCUnit/Basic.h>
#include <BCUnit/BCUnit.h>
#include "tools/printing.h"
#include "tools/comparison.h"
#include "tests/shared_test.h"
#include "tests/comparison_sort_tests.h"
#include "algorithms/bubble_sort.h"


void testODD_NO_ELEMENTS(void)
{
        TestCase **tests = odd_test(NUM_TESTS);

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


void testEVEN_NO_ELEMENTS(void)
{
        TestCase **tests = even_test(NUM_TESTS);

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


void testREPEAT_SINGLE_ELEMENT(void)
{
        TestCase **tests = single_rep_test(NUM_TESTS);

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


void testSORTED(void)
{
        TestCase **tests = sorted_test(NUM_TESTS);

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
        if (NULL == CU_add_test(suite, "Odd number of elements", testODD_NO_ELEMENTS) ||
            NULL == CU_add_test(suite, "Even number of elements", testEVEN_NO_ELEMENTS) ||
            NULL == CU_add_test(suite, "Empty arrays", testEMPTY_LIST) ||
            NULL == CU_add_test(suite, "Single element", testSINGLE_ELEMENT) ||
            NULL == CU_add_test(suite, "Repeat elements", testREPEAT_ELEMENT) ||
            NULL == CU_add_test(suite, "Len 2, all the same", testREPEAT_SINGLE_ELEMENT) ||
            NULL == CU_add_test(suite, "Already sorted", testSORTED))
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
