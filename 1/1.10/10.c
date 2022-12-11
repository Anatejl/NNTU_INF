//
// Created by Anatejl on 05.11.2022.
//
//Task 4 - Var 14

#include <stdio.h>

int main() {

    printf("Enter split number: \n");
    int splitNumber;
    scanf_s("%d", &splitNumber);

    printf("Enter array length: \n");
    int arrayLength;
    scanf_s("%d", &arrayLength);

    printf("Enter a line of numbers: \n");
    char array[arrayLength];
    scanf("%s", array);

    char arrayFinal[arrayLength];

    for (int i = 0; i < arrayLength; ++i) {
       int j=(i+splitNumber) %arrayLength;
       arrayFinal[j] = array[i];
    }

    printf("Final array is: \n");
    for(int i = 0; i < arrayLength; ++i){
        printf("%c", arrayFinal[i]);
    }

    return 0;
}