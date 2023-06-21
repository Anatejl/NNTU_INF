#include <stdio.h>

int main() {

	int list2[] = {
		2, 7, 19, 0, 8
	};

	int arrayLength = sizeof(list2) / 4;
	printf("Array length is: %d\n", arrayLength);

	printf("Sum of the first (%d) and last (%d) entries of an array is: %d\n", 
		list2[0], list2[arrayLength-1], list2[0] + list2[arrayLength-1]);

	return 0;
}