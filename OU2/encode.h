#ifndef ENCODE_H
#define ENCODE_H

#include "huffman_table.h"
#include "huffman_trie.h"
void encode_file(FILE *process_file_p, FILE *out_file_p, huffmanTable *table);

#endif // ENCODE_H