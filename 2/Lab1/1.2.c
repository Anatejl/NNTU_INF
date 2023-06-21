#include <stdio.h>

int main() {

	int inputNumber;
	printf("Input a number:\n");
	scanf_s("%d", &inputNumber);

	if (inputNumber > 0) {
		printf("Number (%d) is positive, here is processed value: %d\n", inputNumber, inputNumber * 2);
	}
	else if(inputNumber < 0){
		printf("Number(%d) is negavite, here is processed value: %d\n", inputNumber, inputNumber / 3);
	}
	else {
		printf("Number is zero, nothing to do with it.");
	}

	getchar();

	return 0;
}