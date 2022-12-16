//
// Created by Anatejl on 05.11.2022.
//
//Task 4 - Var 14 - array

#include <stdio.h>
#include <stdlib.h>

int splitNumber;
int arrayLength;
char userAnswer = 'y';

int getSplitNumber() {

    printf("Enter split number: \n");
    scanf_s("%d", &splitNumber);

    return splitNumber;
}

int getArrayLength() {

    printf("Enter array length: \n");
    scanf_s("%d", &arrayLength);

    return arrayLength;
}

char *getArray() {

    printf("Enter a line: \n");
    char *array = malloc(arrayLength);
    scanf("%s", array);

    return array;
}

int getOutput(char *arrayFinal) {

    printf("Final array is: \n");
    for (int i = 0; i < arrayLength; ++i){
        printf("%c", arrayFinal[i]);
    }
    printf("\n");
    return 0;
}

int main() {

    while (userAnswer == 'y') {
        getSplitNumber();
        getArrayLength();
        char *array = getArray();

        char arrayFinal[arrayLength];

        for (int i = 0; i < arrayLength; ++i) {
            int j = (i + splitNumber) % arrayLength;
            arrayFinal[j] = array[i];
        }

        getOutput(arrayFinal);
        free(array);

        printf("\n");
        printf("Again? (y/n) :\n");
        scanf_s("%s", &userAnswer);
        printf("\n");
    }

    return 0;
}