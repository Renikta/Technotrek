CFLAGS = -MD -Wall
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
CC = gcc

all: solve

solve: solve_square_eq.o sqeq.o
	$(CC) -o $@ $^ -lm

unittest: unittest.o sqeq.o
	$(CC) -o $@ $^ -lm

gcov_solve: gcov_solve.out
	./gcov_solve.out

gcov_solve.out: sqeq.c unittest.c
	$(CC) $(GCOV_FLAGS) -o $@ $^ -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $<

-include *.d

.PHONY: clean

clean:
	rm *.d *.o *.gcda *.gcno *.gcov
