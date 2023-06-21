#include <stdio.h>
#include <math.h>
#define BREAK_PERIOD 6

int main() {

	int debt = 120000;

	for (int i = 0; i < BREAK_PERIOD; i++) {
		debt = debt * 1.06;
		//printf("interation_%d, value_%d\n", i, debt);
	}

	printf("Total debt is: $%d", debt);

	return 0;
}