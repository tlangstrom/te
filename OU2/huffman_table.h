#ifndef HUFFMAN_TABLE
#define HUFFMAN_TABLE

#include <stdio.h>
#include <string.h>
#include "huffman_trie.h"

#define MAX_CHAR 256

typedef struct {
    char *character;
    char *sequence;
} huffmanTable;

huffmanTable *build_huffman_table(trie_node *root);
void build_huffman_table_recursive(trie_node *node, char *code, huffmanTable *table);


#endif