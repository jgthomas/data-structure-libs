enum {HEAP_BUFFER = 1024};

typedef struct BinHeap {
        void *array[HEAP_BUFFER];
        int len;
}
BinHeap;

int left_child_idx(int pos);
int right_child_idx(int pos);
int parent_node(int pos);
void heap_delete(BinHeap *heap);
BinHeap *heap_init(void);
void bubble_up(BinHeap *heap,
               size_t elem_size,
               int index,
               bool (*compare)(void *x, void *y));
void heap_insert(BinHeap *heap,
                 size_t elem_size,
                 void *data,
                 bool (*compare)(void *x, void *y));
void heap_add_data(BinHeap *heap,
                   void *data,
                   size_t data_size,
                   size_t elem_size,
                   bool (*compare)(void *x, void *y));

