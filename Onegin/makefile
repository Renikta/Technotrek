CFLAGS = -MD -Wall
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
CC = gcc

all: onegin

onegin: sort_of_poems.o sort.o
	$(CC) -o $@ $^

ghost: Onegin's_ghost.o sort.o
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

-include *.d

.PHONY: clean

clean:
	rm *.d *.o
