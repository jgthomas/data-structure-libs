typedef struct new_node {
    void *data;
    struct new_node *next;
}
Node;


typedef struct List {
    struct Node *next;
}
List;