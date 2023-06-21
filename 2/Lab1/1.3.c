#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {

	long long int inputNumber;
	printf("Input an integer:\n");
	scanf_s("%lld", &inputNumber);

	long long int processedNumber = pow(inputNumber, 2);

	if (processedNumber >= 100) {
		
		int inputLength = 0;
		long long int inputNumberTemp = inputNumber;
		while (inputNumberTemp != 0) {
			inputNumberTemp /= 10;
			inputLength++;
		}
		printf("Input number is %d digits long.\n", inputLength);
		//
		if (processedNumber > 0) {
			printf("Number is positive, here it is: initial - %lld, ^2 - %lld\n", inputNumber, processedNumber);
			}
		else if (processedNumber <= 0) {
			printf("Number is negative, here it is: initial - %lld, ^2 - %lld\n", inputNumber, processedNumber);
		}
	}
	else if (processedNumber < 100) {
		if (processedNumber > 0) {
			printf("Number is positive, here it is: initial - %lld, ^2 - %lld\n", inputNumber, processedNumber);
		}
		else if (processedNumber <= 0) {
			printf("Number is negative, here it is: initial - %lld, ^2 - %lld\n", inputNumber, processedNumber);
		}
	}

	return 0;
}