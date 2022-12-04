//
// Created by Anatejl on 05.11.2022.
//
//Task 4 - Var 14

#include <stdio.h>
#include <string.h>

const unsigned MaxArrayLength = 64;

int main() {

    printf("Enter split number: ");
    unsigned splitNumber;
    scanf_s("%d", &splitNumber);

    printf("Enter array length:");
    unsigned arrayLength;
    scanf_s("%d", &arrayLength);

    printf("Enter a line of numbers: ");
    unsigned array[MaxArrayLength];
    for (unsigned i = 0; i < arrayLength; ++i) {
        scanf_s("%d", array[i]);
    };

    unsigned arrayMove = 0 + arrayLength;
    for (unsigned i = 0; i < arrayMove; ++i){
        unsigned arrayOld = array[i];
        array[i] = array[arrayMove + 1] = arrayOld;
    };


    unsigned arrayFinal[MaxArrayLength];


    printf("%d", array[1]);

    //printf("%u", &string);

    return 0;
}