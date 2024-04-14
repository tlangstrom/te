#ifndef DECODE_H
#define DECODE_H

#include "huffman_table.h"
#include "huffman_trie.h"

void decode_file(FILE *process_file_p, FILE *out_file_p, huffmanTable *table);
#endif // DECODE_H