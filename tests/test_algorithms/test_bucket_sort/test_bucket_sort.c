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
#include "algorithms/bucket_sort.h"



/**
 * Bucket sort of an array of structs with integer keys
 *
 * */
void testOBJECT_BUCKET_SORT_BASIC(void)
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
        int max = find_max_integer(int_array, len) + 1;

        Record *record_array[len];

        build_records(record_array,
                      int_array,
                      data_array,
                      sizeof(data_array),
                      sizeof(data_array[0]));

        CU_ASSERT_FALSE(records_match_array(record_array, answer_array, sizeof(answer_array), sizeof(answer_array[0]), equal_string));
        bucket_sort(record_array, len, max);
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
        if (NULL == CU_add_test(suite, "Object bucket sort basic", testOBJECT_BUCKET_SORT_BASIC))
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
