//
// Created by Anatejl on 15.05.2023.
//
#include <stdio.h>
#include <string.h>

#include "data.h"
#include "array.c"

void getInput(){

    printf("\nWelcome to dot count program!\n");

    for (int i = 1; i < INPUT_MAX_DOTS; i++){

        printf("Input %d/3 set of coordinates (x; y):", i);
        scanf_s("%d",&inputCode[i].x);
        scanf_s("%d",&inputCode[i].y);
    }

}

void processing(){


}


void getOutput(){



}



int main(){

    getInput();

    //debug
    //printf("%d", inputCode[2].y);

    return 0;
}