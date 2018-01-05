#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <BCUnit/Basic.h>
#include <BCUnit/BCUnit.h>
#include "tools/printing.h"
#include "tools/comparison.h"
#include "algorithms/binary_search.h"


enum {NOT_FOUND = -1,
      NUM_ARRAYS = 8,
      ELEMENT_MAX = 8};

int even_num_elem[8][4] = {{1,1,1,1},
                           {1,1,1,3},
                           {1,1,3,3},
                           {1,1,3,5},
                           {1,3,3,3},
                           {1,3,3,5},
                           {1,3,5,5},
                           {1,3,5,7}};

int even_num_elem_answers[8][4] = {{1,NOT_FOUND,NOT_FOUND,NOT_FOUND},
                                   {1,3,NOT_FOUND,NOT_FOUND},
                                   {1,2,NOT_FOUND,NOT_FOUND},
                                   {1,2,3,NOT_FOUND},
                                   {0,1,NOT_FOUND,NOT_FOUND},
                                   {0,1,3,NOT_FOUND},
                                   {0,1,2,NOT_FOUND},
                                   {0,1,2,3}};


int odd_num_elem[8][5] = {{1,1,1,1,1},
                          {1,1,1,3,3},
                          {1,3,3,3,3},
                          {1,3,3,3,5},
                          {1,3,3,3,3},
                          {1,3,3,5,7},
                          {1,3,5,5,7},
                          {1,3,5,7,5}};

int odd_num_elem_answers[8][5] = {{2,NOT_FOUND,NOT_FOUND,NOT_FOUND},
                                  {2,3,NOT_FOUND,NOT_FOUND},
                                  {0,2,NOT_FOUND,NOT_FOUND},
                                  {0,2,4,NOT_FOUND},
                                  {0,2,NOT_FOUND,NOT_FOUND},
                                  {0,2,3,4},
                                  {0,1,2,4},
                                  {0,1,2,3}};



void testBASIC_SEARCH(void)
{
        int test_int[] = {1,4,4,6,7,7,12,12,12,15,19,23,24,29,63,66,77,77,80};
        char test_char[] = {'a','b','c','d','e','f','g','h'};

        int int_present = 19;
        int int_present_index = binary_search(test_int, &int_present, sizeof(test_int), sizeof(int), more_than_int);
        CU_ASSERT_TRUE(int_present_index == 10);

        int int_not_present = 5;
        int int_not_present_index = binary_search(test_int, &int_not_present, sizeof(test_int), sizeof(int), more_than_int);
        CU_ASSERT_TRUE(int_not_present_index == NOT_FOUND);

        char char_present = 'h';
        int char_present_index = binary_search(test_char, &char_present, sizeof(test_char), sizeof(char), more_than_char);
        CU_ASSERT_TRUE(char_present_index == 7);

        char char_not_present = 'z';
        int char_not_present_index = binary_search(test_char, &char_not_present, sizeof(test_char), sizeof(char), more_than_char);
        CU_ASSERT_TRUE(char_not_present_index == NOT_FOUND);
}


void testFOUR_ELEMENT_EXHAUSTIVE(void)
{
        int answer_key;

        for (int i = 0; i < NUM_ARRAYS; i++)
        {
                answer_key = 0;

                for (int j = 0; j <= ELEMENT_MAX; j++)
                {
                       int result = binary_search(even_num_elem[i],
                                                  &j,
                                                  sizeof(even_num_elem[i]),
                                                  sizeof(int),
                                                  more_than_int);

                       if (j == 0 || j % 2 == 0)
                       {
                               CU_ASSERT_TRUE(result == NOT_FOUND);
                       }
                       else
                       {
                               CU_ASSERT_TRUE(result == even_num_elem_answers[i][answer_key]);
                               answer_key++;
                       }
                }
        }
}


void testFIVE_ELEMENT_EXHAUSTIVE(void)
{
        int answer_key;

        for (int i = 0; i < NUM_ARRAYS; i++)
        {
                answer_key = 0;

                for (int j = 0; j <= ELEMENT_MAX; j++)
                {
                       int result = binary_search(odd_num_elem[i],
                                                  &j,
                                                  sizeof(odd_num_elem[i]),
                                                  sizeof(int),
                                                  more_than_int);

                       if (j == 0 || j % 2 == 0)
                       {
                               CU_ASSERT_TRUE(result == NOT_FOUND);
                       }
                       else
                       {
                               CU_ASSERT_TRUE(result == odd_num_elem_answers[i][answer_key]);
                               answer_key++;
                       }
                }
        }

}


void testEMPTY_ARRAY(void)
{
        int empty[] = {};
        int to_find = 8;
        int result = binary_search(empty,
                                   &to_find,
                                   sizeof(empty),
                                   sizeof(int),
                                   more_than_int);

        CU_ASSERT_TRUE(result == NOT_FOUND);
}


void testSINGLE_ELEMENT_ARRAY(void)
{
        int single[1] = {5};
        int to_find = 5;
        int to_not_find = 6;

        int result_1 = binary_search(single,
                                     &to_find,
                                     sizeof(single),
                                     sizeof(int),
                                     more_than_int);

        CU_ASSERT_TRUE(result_1 == 0);

        int result_2 = binary_search(single,
                                     &to_not_find,
                                     sizeof(single),
                                     sizeof(int),
                                     more_than_int);

        CU_ASSERT_TRUE(result_2 == NOT_FOUND);
}


void testTWO_ELEMENT_ARRAY(void)
{
        int two[2] = {5,6};

        for (int i = 0; i < 7; i++)
        {
                int result = binary_search(two,
                                           &i,
                                           sizeof(two),
                                           sizeof(int),
                                           more_than_int);

                if (i == 5)
                {
                        CU_ASSERT_TRUE(result == 0);
                }
                else if (i == 6)
                {
                        CU_ASSERT_TRUE(result == 1);
                }
                else
                {
                        CU_ASSERT_TRUE(result == NOT_FOUND);
                }
        }
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
        if (NULL == CU_add_test(suite, "Basic searching for integers, chars and strings", testBASIC_SEARCH) ||
            NULL == CU_add_test(suite, "Exhaustive test of even number of elements", testFOUR_ELEMENT_EXHAUSTIVE) ||
            NULL == CU_add_test(suite, "Exhaustive test of odd number of elements", testFIVE_ELEMENT_EXHAUSTIVE) ||
            NULL == CU_add_test(suite, "Empty array", testEMPTY_ARRAY) ||
            NULL == CU_add_test(suite, "Single element array", testSINGLE_ELEMENT_ARRAY) ||
            NULL == CU_add_test(suite, "Two element array", testTWO_ELEMENT_ARRAY))
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
