//
// Created by Anatejl on 15.05.2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "data.h"
#include "array.c"

void getInput(){

    printf("\nWelcome to dot count program!\n");

    for (int i = 0; i < INPUT_MAX_DOTS; i++){

        printf("Input %d/%d set of coordinates (x y):", i+1, INPUT_MAX_DOTS);
        scanf_s("%d",&inputDot[i].x);
        scanf_s("%d",&inputDot[i].y);
    }

}

void process_count(){



}

int *process_compare(){

    int *resultValue = malloc(sizeof (int*));
    *resultValue = 0;

    for (int i = 0; i < INPUT_MAX_DOTS; i++){

        for (int j = 0; j < CIRCLES_MAX; j++) {

            if (inputDot[i].x <= circleCode[j].x && inputDot[i].y <= circleCode[j].y) {

                printf("\nDA #i-%d. #j-%d\n", i, j);
                (*resultValue)++;
            }
        }

    }

    return resultValue;
}

void getOutput(int resultValue){

    printf("\nResult is: %d\n", resultValue);

}



int main(){

    getInput();

    explicitCirclesArray();
    process_count();
    int *processedValue = process_compare();

    getOutput(*processedValue);

   //for (int i = 0; i < CIRCLES_MAX; ++i) {
   //    printf("\nC-%d : %d\n", i, circleCode[i].y);
   //}

    free(processedValue);
    return 0;
}