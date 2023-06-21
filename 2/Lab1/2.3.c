#include <stdio.h>
#include <math.h>

int main() {

	int iteration = 1;

	for (int value = 1; value < 100000; value *= 2) {
		printf("#%d - %d\n", iteration, value);
		iteration++;
	}

	return 0;
}