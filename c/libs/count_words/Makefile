CC=gcc
CFLAGS=-I. -Wall -std=c99
DEPS = count_words.h
OBJ = count_words.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

count_words: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(CFLAGS)


