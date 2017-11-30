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


void testBASIC_STACK_OPERATIONS(void)
{
        // test stack_empty
        int array[] = {12,3,45,67,87,89,9};
        Stack *stack = stack_init();
        CU_ASSERT_TRUE(stack_empty(stack));

        // test initial data load
        stack_add_data(stack, array, sizeof(array), sizeof(array[0]));
        CU_ASSERT_TRUE(match(array, stack->array, sizeof(array), sizeof(array[0]), equal_int));
        
        // test stack_peek
        int top_of_stack = 9;
        CU_ASSERT_EQUAL(top_of_stack, to_int(stack_peek(stack)));

        // test stack_pop
        top_of_stack = 89;
        stack_pop(stack);
        CU_ASSERT_EQUAL(top_of_stack, to_int(stack_peek(stack)));

        stack_delete(stack);
}


void testMULTIPLE_TYPES(void)
{
        int array[] = {15,13,46,10,1,23,5};
        char char_array[] = {'e','a','r','t','b'};
        char *string_array[] = {"zebra",
                                "moose",
                                "elephant",
                                "armadillo",
                                "coyote"};

        // integer
        Stack *stack = stack_init();
        CU_ASSERT_TRUE(stack_empty(stack));
        stack_add_data(stack, array, sizeof(array), sizeof(array[0]));
        CU_ASSERT_TRUE(match(array, stack->array, sizeof(array), sizeof(array[0]), equal_int));
        int top_of_stack = 5;
        CU_ASSERT_EQUAL(top_of_stack, to_int(stack_peek(stack)));
        stack_pop(stack);
        stack_pop(stack);
        top_of_stack = 1;
        CU_ASSERT_EQUAL(top_of_stack, to_int(stack_peek(stack)));
        stack_delete(stack);

        // char
        Stack *stack1 = stack_init();
        CU_ASSERT_TRUE(stack_empty(stack1));
        stack_add_data(stack1, char_array, sizeof(char_array), sizeof(char_array[0]));
        CU_ASSERT_TRUE(match(char_array, stack1->array, sizeof(char_array), sizeof(char_array[0]), equal_char));
        char top_of_stack1 = 'b';
        CU_ASSERT_EQUAL(top_of_stack1, to_char(stack_peek(stack1)));
        stack_pop(stack1);
        stack_pop(stack1);
        top_of_stack1 = 'r';
        CU_ASSERT_EQUAL(top_of_stack1, to_char(stack_peek(stack1)));
        stack_delete(stack);

        // string
        Stack *stack2 = stack_init();
        CU_ASSERT_TRUE(stack_empty(stack2));
        stack_add_data(stack2, string_array, sizeof(string_array), sizeof(string_array[0]));
        CU_ASSERT_TRUE(match(string_array, stack1->array, sizeof(string_array), sizeof(string_array[0]), equal_string));
        char *top_of_stack2 = "coyote";
        CU_ASSERT_EQUAL(top_of_stack2, to_string(stack_peek(stack2)));
        stack_pop(stack2);
        stack_pop(stack2);
        top_of_stack2 = "elephant";
        CU_ASSERT_EQUAL(top_of_stack2, to_string(stack_peek(stack2)));
        stack_delete(stack2);
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
        if (NULL == CU_add_test(suite, "Basic operations", testBASIC_STACK_OPERATIONS) ||
            NULL == CU_add_test(suite, "Multiple types", testMULTIPLE_TYPES))
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
