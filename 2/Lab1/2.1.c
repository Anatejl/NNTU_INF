#include <stdio.h>

#define ARRAY_LENGTH 30

int main() {

	int numbers[ARRAY_LENGTH];

	for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++) {
		numbers[i] = i;
	}

	for (int i = 0; i < ARRAY_LENGTH; i++) {
		if (numbers[i] % 2 == 0) {
			if (numbers[i] % 4 != 0) {
				printf("Catch! - %d\n", numbers[i]);
			}
			//DELETE WHATS UNDER ME!
			else {
				printf("Thrown out: %d\n", numbers[i]);
			}
		}

		
	}

	return 0;
}