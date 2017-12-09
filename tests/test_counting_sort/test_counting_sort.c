#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <BCUnit/Basic.h>
#include <BCUnit/BCUnit.h>
#include "tests/shared_test.h"
#include "tools/printing.h"
#include "tools/comparison.h"
#include "tools/general_distro_sort.h"
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


void testCOUNTING_SORT_BASIC(void)
{
        int input[] = {3,2,5,7,9,12,3,56,7,23,14,8,9,13,17,8,25,32,12,21,6,11,42,12,6};
        int sorted[] = {2,3,3,5,6,6,7,7,8,8,9,9,11,12,12,12,13,14,17,21,23,25,32,42,56};
        int len = sizeof(input) / sizeof(input[0]);
        int max = 57;

        CU_ASSERT_FALSE(int_arrays_match(input, sorted, len));
        counting_sort(input, len, max);
        CU_ASSERT_TRUE(int_arrays_match(input, sorted, len));
}


void testOBJECT_COUNTING_SORT_BASIC(void)
{
        int int_array[] = {2,2,1,5,12,5};

        char *data_array[] = {"steve",
                              "jane",
                              "simon",
                              "james",
                              "jack",
                              "dave"};

        char *answer_array[] = {"simon",
                                "steve",
                                "jane",
                                "james",
                                "dave",
                                "jack"};

        int len = sizeof(int_array) / sizeof(int_array[0]);
        int max = 13;

        Record *record_array[len];

        build_records(record_array,
                      int_array,
                      data_array,
                      sizeof(data_array),
                      sizeof(data_array[0]));

        CU_ASSERT_FALSE(records_match_array(record_array, answer_array, sizeof(answer_array), sizeof(answer_array[0]), equal_string));
        object_counting_sort(record_array, len, max);
        CU_ASSERT_TRUE(records_match_array(record_array, answer_array, sizeof(answer_array), sizeof(answer_array[0]), equal_string));

        delete_records(record_array, len);
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
        if (NULL == CU_add_test(suite, "Simple counting sort basic", testSIMPLE_COUNTING_SORT_BASIC) ||
            NULL == CU_add_test(suite, "Counting sort basic", testCOUNTING_SORT_BASIC) ||
            NULL == CU_add_test(suite, "Object counting sort basic", testOBJECT_COUNTING_SORT_BASIC))
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
