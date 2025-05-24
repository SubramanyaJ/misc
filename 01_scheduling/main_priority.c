#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include "process.h"

#define STRCAST (struct Process *)

int compare(const void *x, const void *y) {
	return (STRCAST x)->PRI - (STRCAST y)->PRI;
}

void
schedule_priority(struct Process *table, int n) {
	int time = 0;
	int idx, min;
	bool *done = calloc(n, sizeof(bool));
	int count = 0;

	while(count < n) {

		idx = -1;
		min = INT_MAX;
		for(int i = 0; i < n; i++) {
			if(
				!done[i]
				&& table[i].PRI < min
				&& table[i].AT <= time
			  ) {
				idx = i;
				min = table[i].PRI;
			}
		}

		if(idx == -1) {time++; continue;}

		done[idx] = true;
		table[idx].RT = time;
		table[idx].WT = time - table[idx].AT;
		time += table[idx].BT;
		table[idx].CT = time;
		table[idx].TAT = time - table[idx].AT;
		count++;

	}
	free(done);
}

int
main() {
	int n;
	struct Process *table = get_input(&n, 1);
	qsort(table, n, sizeof(struct Process), compare);

	schedule_priority(table, n);
	display_processes(table, n);

	free(table);
	return 0;
}
