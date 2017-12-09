#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <BCUnit/Basic.h>
#include <BCUnit/BCUnit.h>
#include "tests/shared_test.h"
#include "tools/printing.h"
#include "tools/comparison.h"
#include "tools/general.h"
#include "tools/general_distro_sort.h"
#include "algorithms/radix_sort.h"


/**
 * Radix sort of a simple integer array
 *
 * */
void testRADIX_SORT_BASIC(void)
{
        int input[] = {2022,2022,1001,500,1243,500,2390,3211};
        int sorted[] = {500,500,1001,1243,2022,2022,2390,3211};
        int len = sizeof(input) / sizeof(input[0]);
        int max = find_max_integer(input, len) + 1;

        CU_ASSERT_FALSE(matching_sequences(input, sorted, sizeof(input), sizeof(input[0]), equal_int));
        radix_sort(input, len, max);
        CU_ASSERT_TRUE(matching_sequences(input, sorted, sizeof(input), sizeof(input[0]), equal_int));
}


/**
 * Radix sort of an array of structs with integer keys 
 *
 * */
void testOBJECT_RADIX_SORT_BASIC(void)
{
        int int_array[] = {2022,2022,1001,500,1243,500};

        char *data_array[] = {"steve",
                              "jane",
                              "simon",
                              "james",
                              "jack",
                              "dave"};

        char *answer_array[] = {"james",
                                "dave",
                                "simon",
                                "jack",
                                "steve",
                                "jane"};

        int len = sizeof(int_array) / sizeof(int_array[0]);
        int max = find_max_integer(int_array, len) + 1;

        Record *record_array[len];

        build_records(record_array,
                      int_array,
                      data_array,
                      sizeof(data_array),
                      sizeof(data_array[0]));

        CU_ASSERT_FALSE(records_match_array(record_array, answer_array, sizeof(answer_array), sizeof(answer_array[0]), equal_string));
        object_radix_sort(record_array, len, max);
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
        if (NULL == CU_add_test(suite, "Radix sort basic", testRADIX_SORT_BASIC) ||
            NULL == CU_add_test(suite, "Object radix sort basic", testOBJECT_RADIX_SORT_BASIC))
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
