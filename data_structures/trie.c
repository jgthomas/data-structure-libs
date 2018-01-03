#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"


bool load(TrieNode *root, char *text)
{
        FILE *fp = fopen(text, "r");

        if (fp == NULL)
        {
                fprintf(stderr, "Could not open file %s\n", text);
                return false;
        }

        char word[MAX_LENGTH + 1];

        // scan in words
        while (fgets(word, sizeof(word), fp))
        {
            // strip out newline character
            word[strcspn(word, "\n")] = '\0';
            
            insert(root, word);
        }

        fclose(fp);
        return true;
}


TrieNode *make_node(void)
{
        TrieNode *new_node = malloc(sizeof(*new_node));
 
        if (new_node == NULL)
        {
                printf("failed to allocate memory\n");
                exit(1);
        }
 
        new_node->end_of_word = false;
 
        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
                new_node->children[i] = NULL;
        }
 
        return new_node;
}


void insert(TrieNode *root, char *key)
{
        int length = strlen(key);
 
        TrieNode *p_crawl = root;
 
        for (int level = 0; level < length; level++)
        {
                int index = key[level] - CHAR_BASE;

                if (p_crawl->children[index] == NULL)
                {
                        p_crawl->children[index] = make_node();
                }
 
                p_crawl = p_crawl->children[index];
        }
        p_crawl->end_of_word = true;
}


bool search(TrieNode *root, char *key)
{
        int length = strlen(key);
        TrieNode *p_crawl = root;
 
        for (int level = 0; level < length; level++)
        {
                int index = key[level] - CHAR_BASE;

                if (p_crawl->children[index] == NULL)
                {
                        return false;
                }

                p_crawl = p_crawl->children[index];
        }

        return (p_crawl != NULL && p_crawl->end_of_word);
}


bool has_no_children(TrieNode *node)
{
        for (int index = 0; index < ALPHABET_SIZE; index++)
        {
                if (node->children[index] != NULL)
                {
                        return false;
                }
        }

        return true;
}


void unmark_as_end(TrieNode *node)
{
        node->end_of_word = false;
}


bool not_end_of_word(TrieNode *node)
{
        return (!node->end_of_word);
}


void delete_key(TrieNode *root, char *key)
{
        if (root == NULL || key == NULL)
        {
                printf("NULL key or empty trie error\n");
                return;
        }

        int length = strlen(key);
        int level = 0;

        delete_helper(root, key, length, level);
}


/**
 * Algorithm
 * 
 * 1. Traverse to end node of key
 * 2. Unmark node as end of word
 * 3. If end node has no children, delete
 * 4. For each other node up the tree, delete 
 *     IF they have no children 
 *    AND are not the end of a word
 * 
 * */
bool delete_helper(TrieNode *root, char *key, int length, int level)
{
        TrieNode *p_crawl = root;
        
        if (p_crawl == NULL)
        {
                printf("'%s' not found in tree\n", key);
        }
        
        // base case
        if (level == length)
        {
                unmark_as_end(p_crawl);

                if (has_no_children(p_crawl))
                {
                        return true;
                }

                return false;
        }
        // recursive case
        else
        {
                int index = key[level] - CHAR_BASE;
                p_crawl = p_crawl->children[index];
                bool delete_child = delete_helper(p_crawl, key, length, level+1);

                if (delete_child)
                {
                        free(p_crawl->children[index]);
                        p_crawl->children[index] = NULL;
                }

                return (not_end_of_word(p_crawl) && has_no_children(p_crawl));
        }
}


/**
 * Delete all nodes in the trie and free memory
 *
 * */
void free_trie(TrieNode *root)
{
        TrieNode *trie_ptr = root;

        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
                // RECURSIVE CASE
                // on finding a non-NULL child node...
                if (trie_ptr->children[i])
                {
                        // ...call function on that lower level
                        free_trie(trie_ptr->children[i]);
                        trie_ptr->children[i] = NULL;
                }
        }
        // BASE CASE
        // once it hits a level with NULL at all children nodes
        // free node and return to previous frame
        free(trie_ptr);
}


/**
 * Return pointer to final node in the key
 *
 * If key is 'sh', it finds the 'h' node that is a
 * child of the root's 's' node
 *
 * */
TrieNode *find_node(TrieNode *root, char *key)
{
        int key_len = strlen(key);
        TrieNode *trie_ptr = root;

        for (int i = 0; i < key_len; i++)
        {
                int index = key[i] - CHAR_BASE;

                if (trie_ptr->children[index])
                {
                        trie_ptr = trie_ptr->children[index];
                }
                else
                {
                        trie_ptr = NULL;
                        return trie_ptr;
                }

        }

        return trie_ptr;
}


void print_key(TrieNode *root, char *key)
{
        char cache[MAX_LENGTH+1];
        int key_len = strlen(key);
        TrieNode *trie_ptr = find_node(root, key);

        if (trie_ptr == NULL)
        {
                printf("key '%s' not found\n", key);
                return;
        }

        for (int i = 0; i < key_len; i++)
        {
                cache[i] = key[i];
        }


        print_helper(trie_ptr, cache, key_len);
}


void print_helper(TrieNode *node, char cache[MAX_LENGTH+1], int pos)
{
        if (node->end_of_word)
        {
                for (int i = 0; i < pos; i++)
                {
                        printf("%c", cache[i]);
                }
                printf("\n");
        }

        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
                if (node->children[i])
                {
                        cache[pos] = (char)(i + CHAR_BASE);
                        print_helper(node->children[i], cache, pos+1);
                }
        }
}


/**
 * Return number of words that start with the supplied key
 *
 * */
int count(TrieNode *root, char *key)
{
        int total = 0;
        TrieNode *trie_ptr = find_node(root, key);

        if (trie_ptr != NULL)
        {
                total += prefix_count(trie_ptr);
        }

        return total;
}


/**
 * Traverse tree from supplied prefix node, counting words
 *
 * */
int prefix_count(TrieNode *node)
{
        int total = 0;
        TrieNode *trie_ptr = node;

        if (trie_ptr->end_of_word)
        {
            total++;
        }

        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            if (trie_ptr->children[i])
            {
                total += prefix_count(trie_ptr->children[i]);
            }
        }

        return total;
}
