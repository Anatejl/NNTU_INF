//
// Created by Anatejl on 15.05.2023.
//

#include "data.h"

void explicitCirclesArray(){

    int i = 1;
    int *p_i = &i;
    for (i = 0; i < CIRCLES_MAX; i++) {

        circlesCode[i].x = 5;
        circlesCode[i].y = *p_i * 2;

    }

}

//void explicitCirclesArray(){
//
//    //1
//    circlesCode[0].x = 5;
//    circlesCode[0].y = 1;
//
//    //2
//    circlesCode[1].x = 5;
//    circlesCode[1].y = 5;
//
//    //3
//    circlesCode[2].x = 5;
//    circlesCode[2].y = 10;
//
//    //4
//    circlesCode[3].x = 5;
//    circlesCode[3].y = 15;
//
//    //5
//    circlesCode[4].x = 5;
//    circlesCode[4].y = 20;
//
//}