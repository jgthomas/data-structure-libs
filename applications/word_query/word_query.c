/**
 * DESCRIPTION:
 *
 * Loads text file and allows query of words in file
 *
 * search  :  check whether word present
 * del     :  delete a word
 * count   :  return number of words starting with a prefix
 * print   :  print all words starting with a prefix
 * quit    :  unload the file from memory
 *
 *
 * DATA STRUCTURES:
 *
 * Uses a TRIE
 *
 *
 * */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "trie.h"
#include "get_input.h"


void print_commands(void);


int main(int argc, char *argv[])
{
        if (argc == 1)
        {
                printf("usage: tire_word_in_file file\n");
                exit(1);
        }

        TrieNode *root = make_node();

        char *text = argv[1];
        bool loaded = load(root, text);

        if (!loaded)
        {
            printf("Could not load %s.\n", text);
            return 1;
        }
 
        char command[20];

        print_commands();

        while (1)
        {
            printf("Enter a command: ");
            fgets(command, sizeof(command), stdin);
            
            if (strncmp(command, "search", 5) == 0)
            {
                char word[MAX_LENGTH + 1];
                char *msg = "Word to find";
                get_string(msg, word, MAX_LENGTH);
                
                if (search(root, word))
                {
                    printf("found\n");
                }
                else
                {
                    printf("not found\n");
                }
            }
            else if (strncmp(command, "del", 3) == 0)
            {
                char word[MAX_LENGTH + 1];
                char *msg = "Word to delete";
                get_string(msg, word, MAX_LENGTH);
                delete_key(root, word);
            }
            else if (strncmp(command, "count", 5) == 0)
            {
                char prefix[MAX_LENGTH + 1];
                char *msg = "Prefix to count";
                get_string(msg, prefix, MAX_LENGTH);
                printf("%d\n", count(root, prefix));

            }
            else if (strncmp(command, "print", 5) == 0)
            {
                char prefix[MAX_LENGTH + 1];
                char *msg = "Prefix to print";
                get_string(msg, prefix, MAX_LENGTH);
                print_key(root, prefix);

            }
            else if (strncmp(command, "quit", 4) == 0)
            {
                free_trie(root);
                break;
            }
            else
            {
                    print_commands();
            }
        }
 
        return 0;
}


void print_commands(void)
{
        printf("commands: search, del, count, print, quit\n\n");
}
