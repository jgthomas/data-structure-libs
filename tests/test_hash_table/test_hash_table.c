#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <BCUnit/Basic.h>
#include <BCUnit/BCUnit.h>
#include "tests/shared_test.h"
#include "tools/printing.h"
#include "tools/comparison.h"
#include "data_structures/hash_table.h"


enum {NUM_TESTS = 3};


int test_int[] = {15,13,46,10,1};
int answer_int[] = {1,10,46,13,15};

char test_char[] = {'e','a','r','t','b'};
char answer_char[] = {'b','t','r','a','e'};

char *test_string[] = {"hello",
                       "everyone",
                       "of",
                       "jr",
                       "functionality",
                       "house"};

char *answer_string[] = {"hello",
                         "everyone",
                         "of",
                         "jr",
                         "functionality",
                         "house"};


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


void testHASHTABLE_LOOKUP(void)
{
        TestCase **tests = make_tests(NUM_TESTS);

        for (int i = 0; i < NUM_TESTS; i++)
        {
                int hashtable_size = 65536;
                HashTable *hashtable = hashtable_create(hashtable_size);

                if (i == 0)
                {
                        hashtable_add_data(hashtable, tests[i]->test, tests[i]->data_size, &Integer);
                        int n = 10;
                        void *present = &n;
                        int m = 1000;
                        void *not_present = &m;
                        CU_ASSERT_TRUE(hashtable_search(hashtable, present, &Integer));
                        CU_ASSERT_FALSE(hashtable_search(hashtable, not_present, &Integer));
                }
                else if (i == 1)
                {
                        // add char type to hashtable!!
                        hashtable_delete(hashtable);
                        continue;
                }
                else if (i == 2)
                {
                        hashtable_add_data(hashtable, tests[i]->test, tests[i]->data_size, &String);
                        char *s = "functionality";
                        void *present = &s;
                        char *s1 = "donkey";
                        void *not_present = &s1;
                        CU_ASSERT_TRUE(hashtable_search(hashtable, present, &String));
                        CU_ASSERT_FALSE(hashtable_search(hashtable, not_present, &String));
                }

                hashtable_delete(hashtable);
        }

        clean_tests(tests, NUM_TESTS);
}


void testHASHTABLE_DELETE(void)
{
        TestCase **tests = make_tests(NUM_TESTS);

        for (int i = 0; i < NUM_TESTS; i++)
        {
                int hashtable_size = 65536;
                HashTable *hashtable = hashtable_create(hashtable_size);

                if (i == 0)
                {
                        hashtable_add_data(hashtable, tests[i]->test, tests[i]->data_size, &Integer);
                        int n = 10;
                        void *present = &n;
                        CU_ASSERT_TRUE(hashtable_search(hashtable, present, &Integer));
                        hashtable_key_delete(hashtable, present, &Integer);
                        CU_ASSERT_FALSE(hashtable_search(hashtable, present, &Integer));
                }
                else if (i == 1)
                {
                        // add char type to hashtable!!
                        hashtable_delete(hashtable);
                        continue;
                }
                else if (i == 2)
                {
                        hashtable_add_data(hashtable, tests[i]->test, tests[i]->data_size, &String);
                        char *s = "functionality";
                        void *present = &s;
                        CU_ASSERT_TRUE(hashtable_search(hashtable, present, &String));
                        hashtable_key_delete(hashtable, present, &String);
                        CU_ASSERT_FALSE(hashtable_search(hashtable, present, &String));
                }

                hashtable_delete(hashtable);
        }

        clean_tests(tests, NUM_TESTS);
}


void testHASHTABLE_SEARCH_PROMOTE(void)
{
        TestCase **tests = make_tests(NUM_TESTS);

        for (int i = 0; i < NUM_TESTS; i++)
        {
                int hashtable_size = 65536;
                HashTable *hashtable = hashtable_create(hashtable_size);

                if (i == 0)
                {
                        hashtable_add_data(hashtable, tests[i]->test, tests[i]->data_size, &Integer);

                        int n = 10;
                        void *present = &n;
                        CU_ASSERT_TRUE(hashtable_search(hashtable, present, &Integer));

                        Node *chained_list = hashtable_get_bucket(hashtable, present, &Integer);
                        CU_ASSERT_TRUE(hashtable_search_promote(hashtable, present, &Integer));
                        CU_ASSERT_TRUE(tests[i]->equal(chained_list->data, present));
                }
                else if (i == 1)
                {
                        // add char type to hashtable!!
                        hashtable_delete(hashtable);
                        continue;
                }
                else if (i == 2)
                {
                        hashtable_add_data(hashtable, tests[i]->test, tests[i]->data_size, &String);

                        // item is in hashtable
                        char *s = "functionality";
                        void *present = &s;
                        CU_ASSERT_TRUE(hashtable_search(hashtable, present, &String));

                        // item is not first item in the chained list
                        Node *chained_list = hashtable_get_bucket(hashtable, present, &String);
                        CU_ASSERT_FALSE(tests[i]->equal(chained_list->data, present));

                        // move item to front
                        CU_ASSERT_TRUE(hashtable_search_promote(hashtable, present, &String));

                        // item now is at front of chained list
                        chained_list = hashtable_get_bucket(hashtable, present, &String);
                        CU_ASSERT_TRUE(tests[i]->equal(chained_list->data, present));
                }

                hashtable_delete(hashtable);
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
        if (NULL == CU_add_test(suite, "Check if value found", testHASHTABLE_LOOKUP) ||
            NULL == CU_add_test(suite, "Delete key", testHASHTABLE_DELETE) ||
            NULL == CU_add_test(suite, "Move found item to front of chain", testHASHTABLE_SEARCH_PROMOTE))
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
