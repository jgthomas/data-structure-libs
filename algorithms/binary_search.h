int binary_search(void *array,
                  void *target,
                  size_t data_size,
                  size_t elem_size,
                  bool (*is_larger)(void *x, void *y));
