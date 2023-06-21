#include <stdio.h>

int main() {

	int list2[] = {
		2, 7, 19, 0, 8
	};

	int arrayLength = sizeof(list2) / sizeof(list2[0]);
	printf("Array length is: %d\n", arrayLength);

	printf("Sum of the first (%d) and last (%d) entries of an array is: %d\n", 
		list2[0], list2[arrayLength-1], list2[0] + list2[arrayLength-1]);

	list2[3] = 3;
	printf("Third element of an array is now 3.\n");

	int arraySum = 0;
	for (int i = 0; i < arrayLength; i++) {
		arraySum += list2[i];
	}
	printf("Summ for all entries of an array is: %d\n", arraySum);

	return 0;
}