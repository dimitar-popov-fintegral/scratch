CC=/usr/local/bin/gcc-9
CFLAGS=-c -Wall -std=c99 
LDFLAGS=-lcheck -lpthread -lm -I../ -I/usr/local/Cellar/check/0.14.0/include -L/usr/local/Cellar/check/0.14.0/lib
DEPS=test.h

all: run_tests

run_tests: tests.o ../count_words.o 
	$(CC) $^ -o $@ $(LDFLAGS)

.c.o: $(DEPS)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

clean:
	rm -f *.o *~ run_tests
