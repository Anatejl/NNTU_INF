#include <stdio.h>
#include <math.h>

#define MAX_ARRAY_LENGTH 50

int main() {

	long long int list1[MAX_ARRAY_LENGTH];

	for (int i = 0; i < MAX_ARRAY_LENGTH; i++) {
		list1[i] = pow(i, 2);
	}
	
	for (int i = 0; i < MAX_ARRAY_LENGTH; i++) {
		list1[i] = pow(list1[i], 2);
		printf("Number %d - %lld\n", i, list1[i]);
	}

	return 0;
}