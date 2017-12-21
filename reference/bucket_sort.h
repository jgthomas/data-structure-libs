typedef struct new_node {
    int n;
    struct new_node *next;
}
Node;

int pick_bucket(int n, int max, int len);
void init_buckets(Node *buckets[], int len);
void print_bucket(Node *node_ptr);
void print_all_buckets(Node *buckets[], int len);
Node *make_node(int val);
void bucket_sort(int array[], int len);
void scatter(Node *buckets[], int array[], int len);
void gather(Node *buckets[], int array[], int len);
void insert(Node **head, int val);
void delete_bucket(Node *node);
void delete_buckets(Node *buckets[], int len);
