//
// Created by Anatejl on 15.05.2023.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "data.h"
#include "array.c"

void getInput(){

    printf("\nWelcome to dot count program!\n");

    for (int i = 1; i < INPUT_MAX_DOTS; i++){

        printf("Input %d/%d set of coordinates (x y):", i, INPUT_MAX_DOTS-1);
        scanf_s("%d",&inputCode[i].x);
        scanf_s("%d",&inputCode[i].y);
    }

}

int *processing(){

    int *resultValue = malloc(sizeof (int*));
    *resultValue = 0;
    for (int j = 1; j < CIRCLES_MAX; j++){

        for (int i = 1; i < INPUT_MAX_DOTS; i++) {

            if (inputCode[i].x <= circlesCode[j].x && inputCode[i].y <= circlesCode[j].y) {

                printf("\nDA #i-%d. #j-%d\n", i, j);
                (*resultValue)++;
            }
        }
    }

    return resultValue;
}


void getOutput(int resultValue){

    printf("Result is: %d", resultValue/(INPUT_MAX_DOTS-1));

}



int main(){

    getInput();

    explicitCirclesArray();

    int *processedValue = processing();

    getOutput(*processedValue);



    ////debug
    //for(int i = 1; i < CIRCLES_MAX; i++){
    //    printf("\nDA %d, %d", circlesCode[i].x, circlesCode[i].y);
    //}

    free(processedValue);
    return 0;
}