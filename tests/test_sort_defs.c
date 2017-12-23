#include <stdio.h>
#include "tools/printing.h"
#include "tools/comparison.h"
#include "tests/shared_test.h"
#include "tests/test_sort_defs.h"


TestCase **basic_tests(int num_tests)
{        
        int test_int[] = {1,7,6,5,22,8,1,15,74};
        char test_char[] = {'c','d','b','f','g','a'};
        char *test_string[] = {"abacus",
                               "zebra",
                               "doggy",
                               "thinning",
                               "soldier"};
        
        int answer_int[] = {1,1,5,6,7,8,15,22,74};
        char answer_char[] = {'a','b','c','d','f','g'};
        char *answer_string[] = {"abacus",
                                 "doggy",
                                 "soldier",
                                 "thinning",
                                 "zebra"};
        

        TestCase **test_array = init_tests(num_tests);

        TestCase *testint = new_test(test_int, answer_int, sizeof(test_int), sizeof(int), equal_int, less_than_int, print_int);
        TestCase *testchar = new_test(test_char, answer_char, sizeof(test_char), sizeof(char), equal_char, less_than_char, print_char);
        TestCase *teststring = new_test(test_string, answer_string, sizeof(test_string), sizeof(char *), equal_string, less_than_string, print_string);

        test_array[0] = testint;
        test_array[1] = testchar;
        test_array[2] = teststring;

        return test_array;
}


TestCase **empty_test(int num_tests)
{
        int test_int[] = {};
        char test_char[] = {};
        char *test_string[] = {};

        TestCase **tests = init_tests(num_tests);

        TestCase *testint = new_test(test_int, test_int, sizeof(test_int), sizeof(int), equal_int, less_than_int, print_int);
        TestCase *testchar = new_test(test_char, test_char, sizeof(test_char), sizeof(char), equal_char, less_than_char, print_char);
        TestCase *teststring = new_test(test_string, test_string, sizeof(test_string), sizeof(char *), equal_string, less_than_string, print_string);

        tests[0] = testint;
        tests[1] = testchar;
        tests[2] = teststring;

        return tests;
}


TestCase **single_element_test(int num_tests)
{
        int test_int[] = {8};
        char test_char[] = {'c'};
        char *test_string[] = {"doggy"};

        TestCase **tests = init_tests(num_tests);

        TestCase *testint = new_test(test_int, test_int, sizeof(test_int), sizeof(int), equal_int, less_than_int, print_int);
        TestCase *testchar = new_test(test_char, test_char, sizeof(test_char), sizeof(char), equal_char, less_than_char, print_char);
        TestCase *teststring = new_test(test_string, test_string, sizeof(test_string), sizeof(char *), equal_string, less_than_string, print_string);

        tests[0] = testint;
        tests[1] = testchar;
        tests[2] = teststring;

        return tests;
}
