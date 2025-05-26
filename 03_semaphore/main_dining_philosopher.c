/*
 * Write a C program to simulate dining -
 * philosophers' problem using semaphores
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX 5

int 
	ctk[MAX] = {0},
	phi[MAX] = {0},
	mutex = 1;

void
wait(int *s) {
	while((*s) <= 0) {
		/* Spinlock */
	}
	(*s)--;
}

void
signal(int *s) {
	(*s)++;
}

void
pickup(int p) {
	wait(&mutex);
	if(	!phi[p]
		&& !ctk[p]
		&& !ctk[(1 + p) % MAX]
	) {
		phi[p] = 1;
		ctk[p] = ctk[(1+p) % MAX] = 1;
		printf("Philosopher %d started eating.\n", p);
	}
	else {
		printf("Philosopher %d cannot eat / already eating.\n", p);
	}
	signal(&mutex);
}

void
putdown(int p) {
	wait(&mutex);
	if(	phi[p]
		&& ctk[p]
		&& ctk[(1 + p) % MAX]
	) {
		phi[p] = 0;
		ctk[p] = ctk[(1+p) % MAX] = 0;
		printf("Philosopher %d stopped eating.\n", p);
	}
	else {
		printf("Philosopher %d wansn't eating.\n", p);
	}
	signal(&mutex);
}

void
show_table() {
	printf("Philosophers :\n");
	for(int i = 0; i < MAX; i++) {
		printf("%d ", phi[i]);
	}
	printf("\nForks :\n");
	for(int i = 0; i < MAX; i++) {
		printf("%d ", ctk[i]);
	}
	putchar('\n');
}

int
main() {
	int pc, bc;
	srand(time(0));
	for(;;) {
		sleep(5);
		show_table();
		pc = rand() % MAX;
		bc = rand() % 2;
		
		if(bc == 0) {
			putdown(pc);
		}
		else {
			pickup(pc);
		}
	}
	return 0;
}
