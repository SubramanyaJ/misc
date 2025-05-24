CC=gcc
CFLAGS=-Wall -Werror -Wextra -O3 -fsanitize=address -Wpedantic -g

all: main_fcfs main_sjf main_priority main_sjf_preemptive

main_fcfs:
	$(CC) main_fcfs.c process.c $(CFLAGS) -o bin/main_fcfs.out

main_sjf:
	$(CC) main_sjf.c process.c $(CFLAGS) -o bin/main_sjf.out

main_priority:
	$(CC) main_priority.c process.c $(CFLAGS) -o bin/main_priority.out

main_sjf_preemptive:
	$(CC) main_sjf_preemptive.c process.c $(CFLAGS) -o bin/main_sjf_preemptive.out

main_priority_preemptive:
	$(CC) main_priority_preemptive.c process.c $(CFLAGS) -o bin/main_priority_preemptive.out


clean:
	rm bin/*
