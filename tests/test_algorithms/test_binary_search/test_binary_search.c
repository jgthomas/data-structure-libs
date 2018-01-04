#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <BCUnit/Basic.h>
#include <BCUnit/BCUnit.h>
#include "tools/printing.h"
#include "tools/comparison.h"
#include "algorithms/binary_search.h"


void testBASIC_SEARCH(void)
{
        int test_int[] = {1,4,4,6,7,7,12,12,12,15,19,23,24,29,63,66,77,77,80};
        char test_char[] = {'a','b','c','d','e','f','g','h'};

        int int_present = 19;
        int int_present_index = binary_search(test_int, &int_present, sizeof(test_int), sizeof(int), more_than_int);
        CU_ASSERT_TRUE(int_present_index == 10);

        int int_not_present = 5;
        int int_not_present_index = binary_search(test_int, &int_not_present, sizeof(test_int), sizeof(int), more_than_int);
        CU_ASSERT_TRUE(int_not_present_index == -1);

        char char_present = 'h';
        int char_present_index = binary_search(test_char, &char_present, sizeof(test_char), sizeof(char), more_than_char);
        CU_ASSERT_TRUE(char_present_index == 7);

        char char_not_present = 'z';
        int char_not_present_index = binary_search(test_char, &char_not_present, sizeof(test_char), sizeof(char), more_than_char);
        CU_ASSERT_TRUE(char_not_present_index == -1);
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
        suite = CU_add_suite("Binary Search", 0, 0);
        if (NULL == suite)
        {
                CU_cleanup_registry();
                return CU_get_error();
        }

        // add tests
        if (NULL == CU_add_test(suite, "Elements present and not present", testBASIC_SEARCH))
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
