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

        printf("Input %d/3 set of coordinates (x y):", i);
        scanf_s("%d",&inputCode[i].x);
        scanf_s("%d",&inputCode[i].y);
    }

}

int *processing(){

    int *resultValue = malloc(sizeof (int*));
    *resultValue = 0;
    for (int i = 1; i < INPUT_MAX_DOTS; i++){

        if (inputCode[i].x <= circlesCode[i].x && inputCode[i].y <= circlesCode[i].y){

            printf("\nDA #%d\n", i);
            //finalCode[0].ID++;
            (*resultValue)++;
        }

    }

    return resultValue;
}


void getOutput(int resultValue){

    printf("Result is: %d", resultValue);

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