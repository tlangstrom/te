#ifndef HUFFMAN_TRIE
#define HUFFMAN_TRIE

#include <stdio.h>
#include "pqueue.h"
#include "calc_frequency.h"

// Trie node data type
typedef struct trie_node {
    int frequency;
    char character;
    struct trie_node *left, *right;
} trie_node;

int compare_frequency(void *a, void *b);

trie_node *merge_trie_nodes(trie_node *a, trie_node *b);
trie_node *process_frequency(charFrequency *frequency);


#endif