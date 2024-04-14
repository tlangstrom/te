#include "huffman_table.h"


huffmanTable *build_huffman_table(trie_node *root) {
    huffmanTable *table = malloc(MAX_CHAR * sizeof(huffmanTable));

    // Initialize the table
    for (int i = 0; i < MAX_CHAR; i++) {
        table[i].character = malloc(2); // space for character and '\0'
        table[i].sequence = malloc(MAX_CHAR + 1); // space for sequence and '\0'
        sprintf(table[i].character, "%c", i);
        table[i].sequence[0] = '\0';
    }

    // Build the table by traversing the Huffman trie
    char code[MAX_CHAR + 1] = {0};
    build_huffman_table_recursive(root, code, table);

    for (int i = 0; i < MAX_CHAR; i++) {
        printf("Character: %s, Huffman code: %s\n", table[i].character, table[i].sequence);
    }
    
    return table;
}

void build_huffman_table_recursive(trie_node *node, char *code, huffmanTable *table) {
    if (node->left == NULL && node->right == NULL) {
        // This is a leaf node, so add an entry to the table
        strncpy(table[(unsigned char)node->character].sequence, code, MAX_CHAR);
    } else {
        // This is an internal node, so recurse on its children
        int length = strlen(code);
        if (node->left != NULL) {
            code[length] = '0';
            code[length + 1] = '\0';
            build_huffman_table_recursive(node->left, code, table);
        }
        if (node->right != NULL) {
            code[length] = '1';
            code[length + 1] = '\0';
            build_huffman_table_recursive(node->right, code, table);
        }
    }
}