CC=gcc
CFLAGS=-Wall -Werror -Wextra -O3 -fsanitize=address -Wpedantic -g

all: main

main:
	$(CC) main.c process.c $(CFLAGS) -o bin/main.out
	./bin/main.out

clean:
	rm bin/*
