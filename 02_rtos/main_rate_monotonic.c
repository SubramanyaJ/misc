/*
 * Write a C program to simuate
 * Rate - Monotonic scheduling
 */

#include <stdio.h>
#include <stdlib.h>

struct Process {
	int PID;
	int BT;
	int PER;
};

int compare(const void *x, const void *y) {
	return ((struct Process *) x)->PER  - ((struct Process *) y)->PER
}

struct Process *
get_processes(int *n) {
	printf("Enter the number of processes : ");
	scanf("%d", n);

	struct Process *arr = calloc(*n, sizeof(struct Process));
	printf("Enter Burst Time and Period : \n");
	for(int i = 0; i < n; i++) {
		printf("[%d] : ", i+1);
		scanf("%d %d", &arr[i].BT, &arr[i].PER);
		arr[i].PID = i + 1;
	}
	qsort(arr, *n, sizeof(struct Process), compare);
	return arr;
}

void
schedule_rate_monotonic(struct Process *arr, int n) {
	int max_time = arr[n-1].PER * 2;
	int time = 0;
	struct Process *curr = NULL, *prev = NULL;

	while(time < max_time) {
		
	}
	return;
}

int
main() {
	int n;
	struct Process *arr = get_processes(&n);

	schedule_rate_monotonic(arr, n);

	free(arr);
	return 0;
}
