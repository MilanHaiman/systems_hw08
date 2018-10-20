#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sieve.h"

int sieve(int target) {
	int tablesize;
	if (target < 25) {
		tablesize = 100;
	}
	else {
		tablesize = target * (int) (log((double) target) * 1.5);		
	}
	int* table = malloc(tablesize * sizeof(int));
	for(int i = 0; i < tablesize; i++) {
		table[i] = 0;
	}
	table[0] = 1;
	table[1] = 1;
	int min = 2;
	int count = 0;
	while (min < tablesize) {
		if (table[min] == 0) {
			for (int i = 2; i*min < tablesize;i++) {
				table[i * min] = 1;
			}
			count ++;
			if (count == target) {
				return min;
			}
		}
		min++;
	}
	return 0;
}