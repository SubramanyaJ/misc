#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "process.h"

#define STRCAST (struct Process *)

int compare(const void *x, const void *y) {
	return (STRCAST x)->PRI - (STRCAST y)->PRI;
}

void
schedule_priority_preemptive(struct Process *table, int n) {
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

		if(table[idx].BT == table[idx].REM) {
			table[idx].RT = time;
		}
		table[idx].REM--;
		if(table[idx].REM == 0) {
			count++;
			done[idx] = true;
			table[idx].CT = time + 1;
			table[idx].TAT = table[idx].CT - table[idx].AT;
			table[idx].WT = table[idx].TAT - table[idx].BT;
		}
		time++;
	}
	free(done);

}

int
main() {
	int n;
	struct Process *table = get_input(&n, 1);

	schedule_priority_preemptive(table, n);
	display_processes(table, n);

	free(table);
	return 0;
}
