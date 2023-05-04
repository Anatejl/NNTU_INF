//
// Created by Anatejl on 13.04.2023.
//
//2.1 SEEMS KURCOVAYA

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "data.h"
#include "array.c"

int *getInputID(){

    printf("Welcome to our cozy world archive. \n");
    printf("Choose a continent (1-EU, 2-AS, 3-AF, 4-NA):\n");
    int *inputID = malloc(32);
    scanf_s("%d", inputID);
    fflush(stdin);

    return inputID;
}

int *getInputArea() {

    printf("\nWell, finally, input expected area. You'll see any matches with that value, or less.\n");
    int *inputArea = malloc(32);
    scanf_s("%d", inputArea);
    fflush(stdin);

    return inputArea;
}

void processing(int inputID) {

    printf("\nINT IS IN FUNC, HERE IT IS - %d\n", inputID);
    for (int i = 1; i < 21; i++){

       if (inputID == AccessCode[i].continentCode){
           arrayFinal[i].ID = i;
           printf("\nGONE WELL: %d - %s\n", arrayFinal[i].ID, AccessCode[i].title);
       }

       else{
           arrayFinal[i].ID = 0;
           //printf("\n%d Array final ID is - %d\n", i, arrayFinal[i].ID);
           //printf("\n%s\n", AccessCode[i].title);
       }

   }
}

void getOutput() {


    //PLACEHOLDER

}

int main() {

    printf("Welcome to Hell.\n");
    arrayInit();

    int *inputID = getInputID();
    int *inputArea = getInputArea();

    printf("\nAt main inputID is - %d\n", *inputID);
    printf("\nAt main inputArea is - %d\n", *inputArea);
    processing(*inputID);

    getOutput();

    printf("\nYYYs, CID - %d; contRAW - %s; area - %s; pop - %s\n",
           AccessCode[2].continentCode, AccessCode[2].continent, AccessCode[2].area, AccessCode[2].population);

    return 0;
}

