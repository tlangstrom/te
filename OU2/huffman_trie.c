#include "huffman_trie.h"
#include "pqueue.h"

// Comparator function for the priority queue
int compare_frequency(void *a, void *b) {
    trie_node *node_a = (trie_node *)a;
    trie_node *node_b = (trie_node *)b;

    return node_a->frequency - node_b->frequency;
}

trie_node *merge_trie_nodes(trie_node *a, trie_node *b) {
    trie_node *new_node = malloc(sizeof(trie_node));
    new_node->frequency = a->frequency + b->frequency;
    new_node->left = a;
    new_node->right = b;

    return new_node;
}

trie_node *process_frequency(charFrequency *frequency) {

    // Create a priority queue with the compare_frequency function
    pqueue *pq = pqueue_empty(compare_frequency);

    // Insert the frequencies into the priority queue
    for (int i = 0; i < 256; i++) {
        trie_node *new_node = malloc(sizeof(trie_node));
        new_node->frequency = frequency[i].frequency;
        new_node->character = frequency[i].character;
        new_node->left = NULL;
        new_node->right = NULL;

        pqueue_insert(pq, new_node);
    }

    // Merge nodes until only one remains
    while (!pqueue_is_empty(pq) && pqueue_inspect_first(pq) != NULL) {
        trie_node *a = pqueue_inspect_first(pq);
        pqueue_delete_first(pq);
        trie_node *b = pqueue_inspect_first(pq);
        pqueue_delete_first(pq);

        trie_node *merged = merge_trie_nodes(a, b);

        pqueue_insert(pq, merged);
    }
    
    // The last node in the priority queue is the root of the trie
    trie_node *root = pqueue_inspect_first(pq);

    // Deallocate resources for the priority queue
    //pqueue_kill(pq);

    return root;
}