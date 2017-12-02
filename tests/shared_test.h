#include <stdbool.h>
#include "../data_structures/linked_list.h"

typedef struct TestCase {
        void *test;
        void *answer;
        size_t data_size;
        size_t elem_size;
        bool (*equal)(void *, void *);
        bool (*compare)(void *, void *);
        void (*print)(void *);
}
TestCase;


TestCase **init_tests(int num_tests);
TestCase *new_test(void *test,
                   void *answer,
                   size_t data_size,
                   size_t elem_size,
                   bool (*equal)(void *x, void *y),
                   bool (*compare)(void *x, void *y),
                   void (*print)(void *x));
void build_test(void *test, void *data, size_t data_size, size_t elem_size);
void clean_tests(TestCase **test_array, int num_tests);
void copy_data(void *test, void *data, size_t data_size, size_t elem_size);
bool arrays_match(void *array1,
                  void *array2,
                  size_t data_size,
                  size_t elem_size,
                  bool (*equal)(void *x, void *y));
bool match(void *array1,
           void *array2[],
           size_t data_size,
           size_t elem_size,
           bool (*equal)(void *x, void *y));

bool ll_array_match(Node *node,
                    void *array2,
                    size_t data_size,
                    size_t elem_size,
                    bool (*equal)(void *x, void *y));
