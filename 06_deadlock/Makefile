CC=gcc
CFLAGS=-Wall -Werror -Wextra -O3 -fsanitize=address -Wpedantic -g

all: main_avoidance main_detection

main_avoidance:
	$(CC) main_avoidance.c $(CFLAGS) -o bin/main_avoidance.out

main_detection:
	$(CC) main_detection.c $(CFLAGS) -o bin/main_detection.out

clean:
	rm bin/*
