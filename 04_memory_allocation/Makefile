CC=gcc
CFLAGS=-Wall -Werror -Wextra -O3 -fsanitize=address -Wpedantic -g

all: main_first_fit main_worst_fit main_best_fit

main_first_fit:
	$(CC) main_first_fit.c $(CFLAGS) -o bin/main_first_fit.out

main_worst_fit:
	$(CC) main_worst_fit.c $(CFLAGS) -o bin/main_worst_fit.out

main_best_fit:
	$(CC) main_best_fit.c $(CFLAGS) -o bin/main_best_fit.out

clean:
	rm bin/*
