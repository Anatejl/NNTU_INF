#include <stdio.h>
#include <string.h>

int main() {

	int inputNumber;
	printf("Input an integer:\n");
	scanf_s("%d", &inputNumber);
	if (inputNumber % 2) {
		printf("This number (%d) is even.", inputNumber);
	}
	else {
		printf("This nubmber (%d) is odd.", inputNumber);
	}

	getchar();

	return 0;
}