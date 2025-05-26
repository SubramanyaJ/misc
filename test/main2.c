/* Rate Monotonic */

#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define STRCAST (struct Task *)

struct Task {
	int
		PID,
		CT, /* Completion Time */
		RT, /* Remaining Time */
		PER, /* Period */
		ND, /* Next Deadline */
		DL, /* Deadline */
		ADL; /* Absolute Deadline */
};

int
compare(const void *x, const void *y) {
	return (STRCAST x)->ADL - (STRCAST y)->ADL;
}

void
schedule_rms(struct Task *arr, int n, int maxtime) {
	for(int time = 0; time < maxtime; time++) {
		
	}
}
