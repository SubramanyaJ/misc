#include <stdio.h>
#include <stdlib.h>
#include "process.h"

#define STRCAST (struct Process *)

int compare(const void *x, const void *y) {
	return (STRCAST x)->AT - (STRCAST y)->AT;
}

void
schedule_fcfs(struct Process *table, int n) {
	int time = 0;
	for(int i = 0; i < n; i++) {
loop:
		if(time < table[i].AT) {
			time++;
			goto loop;
		}

		table[i].RT = time;
		table[i].WT = time - table[i].AT;
		time += table[i].BT;
		table[i].CT = time;
		table[i].TAT = time - table[i].AT;

	}
}

int
main() {
	int n;
	struct Process *table = get_input(&n, 0);
	qsort(table, n, sizeof(struct Process), compare);

 	schedule_fcfs(table , n);
	display_processes(table, n);

	free(table);
	return 0;
}
