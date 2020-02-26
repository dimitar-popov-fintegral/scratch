CC=gcc
CFLAGS=-c -Wall -std=c99
LDFLAGS=-lcheck -lpthread -lm

all: run_tests

run_tests: tests.o 
	$(CC) $^ -o $@ $(LDFLAGS)

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o *~ run_tests
