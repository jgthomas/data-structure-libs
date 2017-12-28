#include <stdio.h>
#include "tools/printing.h"
#include "tools/comparison.h"
#include "tests/shared_test.h"
#include "tests/comparison_sort_tests.h"


/**
 * Odd number of elements
 *
 * */
int odd_int[] = {1,7,6,5,22,8,1,15,74};
char odd_char[] = {'c','d','b','f','g','a','w'};
char *odd_string[] = {"abacus",
                       "zebra",
                       "doggy",
                       "thinning",
                       "soldier"};

int odd_int_answer[] = {1,1,5,6,7,8,15,22,74};
char odd_char_answer[] = {'a','b','c','d','f','g','w'};
char *odd_string_answer[] = {"abacus",
                             "doggy",
                             "soldier",
                             "thinning",
                             "zebra"};


TestCase **odd_test(int num_tests)
{        
        TestCase **test_array = init_tests(num_tests);

        TestCase *testint = new_test(odd_int, odd_int_answer, sizeof(odd_int), sizeof(int), equal_int, less_than_int, print_int);
        TestCase *testchar = new_test(odd_char, odd_char_answer, sizeof(odd_char), sizeof(char), equal_char, less_than_char, print_char);
        TestCase *teststring = new_test(odd_string, odd_string_answer, sizeof(odd_string), sizeof(char *), equal_string, less_than_string, print_string);

        test_array[0] = testint;
        test_array[1] = testchar;
        test_array[2] = teststring;

        return test_array;
}


/**
 * Even number of elements
 *
 * */
int even_int[] = {1,7,6,5,22,8,15,74};
char even_char[] = {'c','d','b','f','g','a'};
char *even_string[] = {"abacus",
                       "doggy",
                       "thinning",
                       "soldier"};

int even_int_answer[] = {1,5,6,7,8,15,22,74};
char even_char_answer[] = {'a','b','c','d','f','g'};
char *even_string_answer[] = {"abacus",
                              "doggy",
                              "soldier",
                              "thinning"};


TestCase **even_test(int num_tests)
{        
        TestCase **test_array = init_tests(num_tests);

        TestCase *testint = new_test(even_int, even_int_answer, sizeof(even_int), sizeof(int), equal_int, less_than_int, print_int);
        TestCase *testchar = new_test(even_char, even_char_answer, sizeof(even_char), sizeof(char), equal_char, less_than_char, print_char);
        TestCase *teststring = new_test(even_string, even_string_answer, sizeof(even_string), sizeof(char *), equal_string, less_than_string, print_string);

        test_array[0] = testint;
        test_array[1] = testchar;
        test_array[2] = teststring;

        return test_array;
}


/**
 * Empty array
 *
 * */
int empty_int[] = {};
char empty_char[] = {};
char *empty_string[] = {};

TestCase **empty_test(int num_tests)
{
        TestCase **tests = init_tests(num_tests);

        TestCase *testint = new_test(empty_int, empty_int, sizeof(empty_int), sizeof(int), equal_int, less_than_int, print_int);
        TestCase *testchar = new_test(empty_char, empty_char, sizeof(empty_char), sizeof(char), equal_char, less_than_char, print_char);
        TestCase *teststring = new_test(empty_string, empty_string, sizeof(empty_string), sizeof(char *), equal_string, less_than_string, print_string);

        tests[0] = testint;
        tests[1] = testchar;
        tests[2] = teststring;

        return tests;
}


/**
 * Single element
 *
 * */
int single_int[] = {8};
char single_char[] = {'c'};
char *single_string[] = {"doggy"};

TestCase **single_element_test(int num_tests)
{
        TestCase **tests = init_tests(num_tests);

        TestCase *testint = new_test(single_int, single_int, sizeof(single_int), sizeof(int), equal_int, less_than_int, print_int);
        TestCase *testchar = new_test(single_char, single_char, sizeof(single_char), sizeof(char), equal_char, less_than_char, print_char);
        TestCase *teststring = new_test(single_string, single_string, sizeof(single_string), sizeof(char *), equal_string, less_than_string, print_string);

        tests[0] = testint;
        tests[1] = testchar;
        tests[2] = teststring;

        return tests;
}


/**
 * Repeat elements
 *
 * */
int repeat_int[] = {2,1,1,2,0};
char repeat_char[] = {'c','c','w','w','p'};
char *repeat_string[] = {"donkey",
                         "donkey",
                         "giraffe",
                         "giraffe",
                         "ape"};

int repeat_int_answer[] = {0,1,1,2,2};
char repeat_char_answer[] = {'c','c','p','w','w'};
char *repeat_string_answer[] = {"ape",
                                "donkey",
                                "donkey",
                                "giraffe",
                                "giraffe"};

TestCase **repeat_element_test(int num_tests)
{
        TestCase **tests = init_tests(num_tests);

        TestCase *testint = new_test(repeat_int, repeat_int_answer, sizeof(repeat_int), sizeof(int), equal_int, less_than_int, print_int);
        TestCase *testchar = new_test(repeat_char, repeat_char_answer, sizeof(repeat_char), sizeof(char), equal_char, less_than_char, print_char);
        TestCase *teststring = new_test(repeat_string, repeat_string_answer, sizeof(repeat_string), sizeof(char *), equal_string, less_than_string, print_string);

        tests[0] = testint;
        tests[1] = testchar;
        tests[2] = teststring;

        return tests;
}


/**
 * Just two repeats
 *
 * */
int single_rep_int[] = {8,8};
char single_rep_char[] = {'c','c'};
char *single_rep_string[] = {"doggy","doggy"};

TestCase **single_rep_test(int num_tests)
{
        TestCase **tests = init_tests(num_tests);

        TestCase *testint = new_test(single_rep_int, single_rep_int, sizeof(single_rep_int), sizeof(int), equal_int, less_than_int, print_int);
        TestCase *testchar = new_test(single_rep_char, single_rep_char, sizeof(single_rep_char), sizeof(char), equal_char, less_than_char, print_char);
        TestCase *teststring = new_test(single_rep_string, single_rep_string, sizeof(single_rep_string), sizeof(char *), equal_string, less_than_string, print_string);

        tests[0] = testint;
        tests[1] = testchar;
        tests[2] = teststring;

        return tests;
}


/**
 * Already sorted
 *
 * */
int sorted_int[] = {1,5,6,7,8,15,22,74};
char sorted_char[] = {'a','b','c','d','f','g'};
char *sorted_string[] = {"abacus",
                         "doggy",
                         "soldier",
                         "thinning"};


TestCase **sorted_test(int num_tests)
{        
        TestCase **test_array = init_tests(num_tests);

        TestCase *testint = new_test(sorted_int, sorted_int, sizeof(sorted_int), sizeof(int), equal_int, less_than_int, print_int);
        TestCase *testchar = new_test(sorted_char, sorted_char, sizeof(sorted_char), sizeof(char), equal_char, less_than_char, print_char);
        TestCase *teststring = new_test(sorted_string, sorted_string, sizeof(sorted_string), sizeof(char *), equal_string, less_than_string, print_string);

        test_array[0] = testint;
        test_array[1] = testchar;
        test_array[2] = teststring;

        return test_array;
}
