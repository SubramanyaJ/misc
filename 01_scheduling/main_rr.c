#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "process.h"

#define STRCAST (struct Process *)

int compare(const void *x, const void *y) {
	return (STRCAST x)->AT - (STRCAST y)->AT;
}

void
schedule_rr(struct Process *table, int n, int tq) {
	int time = 0, count = 0;
	bool *done = calloc(n, sizeof(bool));


}

int
main() {
	int n, tq;
	struct Process *table = get_input(&n, 0);

	printf("Enter the time quantum : ");
	scanf("%d", &tq);

 	schedule_rr(table , n, tq);
	display_processes(table, n);

	free(table);
	return 0;
}
