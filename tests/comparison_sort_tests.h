#ifndef TEST_DEFS_H
#define TEST_DEFS_H

enum {NUM_TESTS = 3};

TestCase **basic_tests(int num_tests);
TestCase **empty_test(int num_tests);
TestCase **single_element_test(int num_tests);
TestCase **repeat_element_test(int num_tests);

#endif
