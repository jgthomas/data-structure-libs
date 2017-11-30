#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <BCUnit/Basic.h>
#include <BCUnit/BCUnit.h>
#include "tests/shared_test.h"
#include "tools/printing.h"
#include "tools/comparison.h"
#include "tools/convertors.h"
#include "data_structures/queue_array.h"


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


void testBASIC_QUEUE_OPERATIONS(void)
{
        // test queue empty 
        int array[] = {12,3,45,67,87,89,9};
        Queue *queue = queue_init();
        CU_ASSERT_EQUAL(0, queue->front);
        CU_ASSERT_EQUAL(0, queue->back);

        // test initial data load
        queue_add_data(queue, array, sizeof(array), sizeof(array[0]));
        CU_ASSERT_TRUE(match(array, queue->array, sizeof(array), sizeof(array[0]), equal_int));
        
        // test queue_peek
        int front_of_queue = 12;
        CU_ASSERT_EQUAL(front_of_queue, to_int(queue_peek(queue)));

        // test dequeue
        dequeue(queue);
        front_of_queue = 3;
        CU_ASSERT_EQUAL(front_of_queue, to_int(queue_peek(queue)));
        CU_ASSERT_EQUAL(1, queue->front);
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
        if (NULL == CU_add_test(suite, "Basic operations", testBASIC_QUEUE_OPERATIONS))
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
