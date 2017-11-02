#include <string.h>
#include <ctype.h>


// adapted from
// https://www.reddit.com/r/cs50/comments/1x6vc8/pset6_trie_vs_hashtable/cf9nlkn/
unsigned int simple_string_hash(const char *word)
{
        unsigned int hash = 0;

        for (int i = 0, n = strlen(word); i < n; i++)
        {
            hash = (hash << 2) ^ tolower(word[i]);
        }

        return hash;
}

// adapted from
// https://stackoverflow.com/questions/664014/what-integer-hash-function-are-good-that-accepts-an-integer-hash-key
unsigned int integer_hash(unsigned int x)
{
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x;
}


unsigned int dumb_hash(unsigned int key) 
{
   return (key % 97);
}
