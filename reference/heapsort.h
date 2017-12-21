void heapsort(int heap[], int heap_len);
void bubble_up(int heap[], int child_index);
void sink_down(int heap[], int heap_len, int index);
void heapify(int heap[], int heap_len);
int left_child_idx(int pos);
int right_child_idx(int pos);
int parent_node(int pos);
