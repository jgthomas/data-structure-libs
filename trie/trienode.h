enum {ALPHABET_SIZE = 26, MAX_LENGTH = 45, CHAR_BASE = 97};

typedef struct TNode {
    struct TNode *children[ALPHABET_SIZE];
    bool end_of_word;
}
TrieNode;
