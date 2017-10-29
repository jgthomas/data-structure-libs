#include "trienode.h"

TrieNode *make_node(void);
void insert(TrieNode *root, const char *key);
bool search(TrieNode *root, const char *key);
bool load(TrieNode *root, const char *text);
bool has_no_children(TrieNode *node);
void unmark_as_end(TrieNode *node);
bool not_end_of_word(TrieNode *node);
void delete_key(TrieNode *root, const char *key);
bool delete_helper(TrieNode *node, const char *key, int length, int level);
void free_trie(TrieNode *root);
int count(TrieNode *root, const char *key);
int prefix_count(TrieNode *node);
TrieNode *find_node(TrieNode *root, const char *prefix);
void print_key(TrieNode *root, const char *key);
void print_helper(TrieNode *node, char cache[MAX_LENGTH+1], int pos);
