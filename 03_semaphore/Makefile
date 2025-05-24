CC=gcc
CFLAGS=-Wall -Werror -Wextra -O3 -fsanitize=address -Wpedantic -g

all: main_producer_consumer main_dining_philosopher

main_producer_consumer:
	$(CC) main_producer_consumer.c -o bin/main_producer_consumer.out

main_dining_philosopher:
	$(CC) main_dining_philosopher.c -o bin/main_producer_consumer.out

clean:
	rm bin/*
