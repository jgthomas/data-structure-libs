typedef struct Record {
   void *key;
   void *value;
} Record;

Record **new_hashtable(int hashtable_size);
Record *new_record(void *key, void *value);
void insert(Record **hashtable, Record *r, int hashtable_size, unsigned int (*hash_ptr)(void *));
Record *search(Record **hashtable, int hashtable_size, void *key, bool (*cmp_ptr)(void *, void *), unsigned int (*hash_ptr)(void *));
void delete_key(Record **hashtable, int hashtable_size, void *key, bool (*cmp_ptr)(void *, void *), unsigned int (*hash_ptr)(void *));
void delete_table(Record **hashtable, int hashtable_size);
void print_hash_table(Record **hashtable, int hashtable_size, void (*print_fptr)(Record *r));
void print_int_kv(Record *r);
void print_string_kv(Record *r);
