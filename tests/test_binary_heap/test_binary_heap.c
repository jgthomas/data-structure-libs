#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <BCUnit/Basic.h>
#include <BCUnit/BCUnit.h>
#include "tests/shared_test.h"
#include "tools/printing.h"
#include "tools/comparison.h"
#include "data_structures/binary_heap.h"


enum {NUM_TESTS = 3};


int test_int[] = {15,13,46,10,1,23,5};
int answer_int[] = {1,10,5,15,13,46,23};

char test_char[] = {'e','a','r','t','b'};
char answer_char[] = {'a','b','r','t','e'};

char *test_string[] = {"zebra",
                       "moose",
                       "elephant",
                       "armadillo",
                       "coyote"};

char *answer_string[] = {"armadillo",
                         "coyote",
                         "moose",
                         "zebra",
                         "elephant"};


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


bool all_items_match(void *answer,
                     void *guess[],
                     size_t data_size,
                     size_t elem_size,
                     bool (*equal)(void *x, void *y))
{
        int length = data_size/elem_size;

        for (int i = 0; i < length; i++)
        {
                void *first = answer + elem_size * i;
                void *second = guess[elem_size * i];

                if (!equal(first, second))
                {
                        return false;
                }
        }
        return true;
}


void testBINARY_HEAP(void)
{
        TestCase **tests = make_tests(NUM_TESTS);

        for (int i = 0; i < NUM_TESTS; i++)
        {
                CU_ASSERT_FALSE(arrays_match(tests[i]->test, tests[i]->answer, tests[i]->data_size, tests[i]->elem_size, tests[i]->equal));
                BinHeap *heap = heap_init();
                heap_add_data(heap, tests[i]->test, tests[i]->data_size, tests[i]->elem_size, tests[i]->compare);
                CU_ASSERT_TRUE(all_items_match(tests[i]->answer, heap->array, tests[i]->data_size, tests[i]->elem_size, tests[i]->equal));
                //heap_print_array(heap, tests[i]->elem_size, tests[i]->print);
                heap_delete(heap);
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
        if (NULL == CU_add_test(suite, "Min heap integer", testBINARY_HEAP)) 
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
