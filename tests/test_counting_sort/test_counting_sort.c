#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <BCUnit/Basic.h>
#include <BCUnit/BCUnit.h>
#include "tests/shared_test.h"
#include "tools/printing.h"
#include "tools/comparison.h"
#include "algorithms/counting_sort.h"




void print_array(int array[], int len)
{
        for (int i = 0; i < len; i++)
        {
                printf("%d ", array[i]);
        }
        printf("\n");
}


bool int_arrays_match(int array1[], int array2[], int len)
{
        for (int i = 0; i < len; i++)
        {
                if (array1[i] != array2[i])
                {
                        return false;
                }
        }
        return true;
}


void testSIMPLE_COUNTING_SORT_BASIC(void)
{
        int input[] = {3,2,5,7,9,12,3,56,7,23,14,8,9,13,17,8,25,32,12,21,6,11,42,12,6};
        int sorted[] = {2,3,3,5,6,6,7,7,8,8,9,9,11,12,12,12,13,14,17,21,23,25,32,42,56};
        int len = sizeof(input) / sizeof(input[0]);
        int max = 57;

        CU_ASSERT_FALSE(int_arrays_match(input, sorted, len));
        simple_counting_sort(input, len, max);
        CU_ASSERT_TRUE(int_arrays_match(input, sorted, len));
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
        suite = CU_add_suite("Counting Sort", 0, 0);
        if (NULL == suite)
        {
                CU_cleanup_registry();
                return CU_get_error();
        }

        // add tests
        if (NULL == CU_add_test(suite, "Simple counting sort basic", testSIMPLE_COUNTING_SORT_BASIC)) 
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
