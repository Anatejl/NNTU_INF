#include <stdio.h>
#include <math.h>

int main() {
	
	int inputNumber = 0;

	while (1) {

		int temp = 0;

		printf("Input an integer:");
		scanf_s("%d", &inputNumber);
		
		if (inputNumber % 3 == 0 && inputNumber % 5 != 0 ) {
			printf("Number remain the same - %d\n", inputNumber);
		}

		else if (inputNumber % 5 == 0) {
			
			if (inputNumber % 3 == 0) {

				printf("Initial - %d, powered - %lf\n", inputNumber, pow(inputNumber, 2));

			}
			
			else {
				temp = pow(inputNumber, 2);
				printf("Number been raised by the power of 2 - %d\n", temp);
			}
		}
		
		else if(inputNumber % 7 ==0){
			printf("Success!\n");
			break;
		}
		else {
			printf("Try again.\n");
		}
	}

	return 0;
}