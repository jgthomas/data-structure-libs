#include <stdio.h>
#include "printing.h"
#include "shared_test.h"
#include "shared_sort.h"
#include "bubble_sort.h"


enum {NUM_TESTS = 3};


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


TestCase **make_tests(int num_tests)
{        
        TestCase **test_array = init_tests(num_tests);

        TestCase *testint = new_test(test_int, answer_int, sizeof(test_int), sizeof(int));
        TestCase *testchar = new_test(test_char, answer_char, sizeof(test_char), sizeof(char));
        TestCase *teststring = new_test(test_string, answer_string, sizeof(test_string), sizeof(char *));

        test_array[0] = testint;
        test_array[1] = testchar;
        test_array[2] = teststring;

        return test_array;
}


int main(void)
{
        TestCase **test_array = make_tests(NUM_TESTS);

        print_array(test_array[0]->test, test_array[0]->data_size, test_array[0]->elem_size, print_int);
        print_array(test_array[1]->test, test_array[1]->data_size, test_array[1]->elem_size, print_char);
        print_array(test_array[2]->test, test_array[2]->data_size, test_array[2]->elem_size, print_string);

        clean_tests(test_array, NUM_TESTS);
}
