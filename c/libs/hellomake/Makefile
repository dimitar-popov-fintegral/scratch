CC=gcc
CFLAGS=-std=c99 -Wall -I.
DEPS = hellomake.h
OBJ = hellomake.o hellofunc.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hello_make: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
