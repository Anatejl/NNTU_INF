//Temperature.c
//Temperature conversion from Celsius to Fahrenheit
#include <stdio.h>	

int main()
{
	printf("Enter temperature in Celsius: ");
	int Celsius;
	scanf_s("%lf", &Celsius);
	int Fahrenheit = (Celsius * 9) / 5 + 32;
	printf("Fahrenheit value is: %d degree\n", Fahrenheit);
	return 0;
}