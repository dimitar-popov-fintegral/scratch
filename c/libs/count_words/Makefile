CC=/usr/local/bin/gcc-9
CFLAGS=-I. -Wall -std=c99
DEPS = count_words.h
OBJ = count_words.o main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f *.o *~ main


