Node **create_hashtable(int hashtable_size)
{
}


unsigned int find_hash(Node **hashtable,
                       int hashtable_size,
                       void *key,
                       unsigned int (*hash_ptr)(void *))
{
}


void insert(Node **hashtable,
            int hashtable_size,
            void *new_data,
            size_t data_size,
            unsigned int (*hash_ptr)(void *))
{
}


bool search(Node **hashtable,
            int hashtable_size,
            void *key,
            bool (*cmp_ptr)(void *, void *),
            unsigned int (*hash_ptr)(void *))
{
}
