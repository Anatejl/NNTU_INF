//
// Created by Anatejl on 13.04.2023.
//
//2.1 SEEMS KURCOVAYA

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "data.h"
#include "array.c"
#define NAME_MAX_SIZE 25

int inputArea;
int inputCont;

void getInput(){

    printf("Welcome to our cozy world archive. \n");
    printf("Choose a continent (1-EU, 2-AS, 3-AF, 4-NA):\n");
    scanf_s("%c", &inputCont);
    printf("\n%c\n", inputCont);
    fflush(stdin);
    printf("\nWell, finally, input expected area. You'll see any matches with that value, or less.\n");
    scanf_s("%d", &inputArea);
    fflush(stdin);

}

// EU = 1
// AS = 2
// AF = 3
// NA = 4

void getOutput(){

    //PLACEHOLDER

}

int main(){

    printf("Welcome to Hell.\n");

    arrayInit();
    getInput();

    //PLACEHOLDER

    getOutput();

    printf("yes, area - %d, contRAW - %c", inputArea, inputCont);

    return 0;
}

