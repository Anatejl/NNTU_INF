//
// Created by Anatejl on 13.04.2023.
//
//2.1 SEEMS KURCOVAYA

#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "array.c"

int *getInputID() {

    printf("Welcome to our cozy world archive. \n");
    printf("Choose a number of a continent (1-EU, 2-AS, 3-AF, 4-NA):\n");
    int *inputID = malloc(32);
    scanf_s("%d", inputID);
    fflush(stdin);

    return inputID;
}

int *getInputArea() {

    printf("\nWell, finally, input area in square thousands km, without any separators:\n");
    int *inputArea = malloc(32);
    scanf_s("%d", inputArea);
    fflush(stdin);

    return inputArea;
}

void processing(int inputID, int inputArea) {

    for (int i = 1; i < 21; i++) {

        if (inputID == AccessCode[i].continentCode && inputArea > AccessCode[i].area) {
            arrayFinal[i].ID = i;
        } else {
            arrayFinal[i].ID = 0;
        }

    }
}


void getOutput() {

    int resultControl = 1;

    for (int i = 1; i < 21; i++) {

        if (arrayFinal[i].ID != 0) {
            printf("\n%d. Title: %s\n", resultControl, AccessCode[i].title);
            printf("   Continent: %s\n", AccessCode[i].continent);
            printf("   Population: %s /thousands\n", AccessCode[i].population);
            printf("   Area %ld /TKM^2\n", AccessCode[i].area);
            resultControl++;
        }
    }

    if (resultControl - 1 == 0) {
        printf("Insufficient query. Try again.");
    }

}

int main() {

    char userAnswer = 'y';

    while (userAnswer == 'y') {

        arrayInit();

        int *inputID = getInputID();
        int *inputArea = getInputArea();

        processing(*inputID, *inputArea);

        getOutput();

        free(inputID);
        free(inputArea);

        printf("\n");
        printf("Again? (y/n) :\n");
        scanf_s("%s", &userAnswer);
        printf("\n");

    }
    return 0;
}

