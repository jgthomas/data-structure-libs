#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <BCUnit/Basic.h>
#include <BCUnit/BCUnit.h>
#include "tests/shared_test.h"
#include "tools/printing.h"
#include "tools/comparison.h"
#include "tools/convertors.h"
#include "data_structures/stack_array.h"


enum {NUM_TESTS = 3};


bool match(void *array1,
           void *array2[],
           size_t data_size,
           size_t elem_size,
           bool (*equal)(void *x, void *y))
{
        int length = data_size/elem_size;

        for (int i = 0; i < length; i++)
        {
                void *first = array1 + elem_size * i;
                void *second = array2[i];

                if (!equal(first, second))
                {
                        return false;
                }
        }
        return true;
}


void testBASIC_STACK_OPERATIONS(void)
{
        // test stack_empty
        int array[] = {12,3,45,67,87,89,9};
        Stack *stack = stack_init();
        CU_ASSERT_TRUE(stack_empty(stack));

        // test initial data load
        stack_add_data(stack, array, sizeof(array), sizeof(array[0]));
        stack_print(stack, print_int);
        CU_ASSERT_TRUE(match(array, stack->array, sizeof(array), sizeof(array[0]), equal_int));
        
        // test stack_peek
        int top_of_stack = 9;
        CU_ASSERT_EQUAL(top_of_stack, to_int(stack_peek(stack)));

        // test stack_pop
        top_of_stack = 89;
        stack_pop(stack);
        CU_ASSERT_EQUAL(top_of_stack, to_int(stack_peek(stack)));
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
        if (NULL == CU_add_test(suite, "Basic operations", testBASIC_STACK_OPERATIONS))
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
