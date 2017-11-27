#ifndef TRIE_H
#define TRIE_H

enum {ALPHABET_SIZE = 26, MAX_LENGTH = 45, CHAR_BASE = 97};


typedef struct TNode {
    struct TNode *children[ALPHABET_SIZE];
    bool end_of_word;
}
TrieNode;


TrieNode *make_node(void);
void insert(TrieNode *root, char *key);
bool search(TrieNode *root, char *key);
bool load(TrieNode *root, char *text);
bool has_no_children(TrieNode *node);
void unmark_as_end(TrieNode *node);
bool not_end_of_word(TrieNode *node);
void delete_key(TrieNode *root, char *key);
bool delete_helper(TrieNode *node, char *key, int length, int level);
void free_trie(TrieNode *root);
int count(TrieNode *root, char *key);
int prefix_count(TrieNode *node);
TrieNode *find_node(TrieNode *root, char *prefix);
void print_key(TrieNode *root, char *key);
void print_helper(TrieNode *node, char cache[MAX_LENGTH+1], int pos);

#endif
