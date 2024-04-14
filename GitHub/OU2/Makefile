CC=gcc
CFLAGS=-Wall -std=c99
DEPS = calc_frequency.h huffman_trie.h pqueue.h list.h
OBJ = huffman.o calc_frequency.o huffman_trie.o pqueue.o list.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

huffman: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)