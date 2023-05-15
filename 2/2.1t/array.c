//
// Created by Anatejl on 15.05.2023.
//

#include "data.h"

void explicitCirclesArray(){

    int i = 0;
    int *p_i = &i;
    for (i = 0; i < CIRCLES_MAX; i++) {

        circleCode[i].x1 = 5;
        circleCode[i].y1 = 0;

        circleCode[i].x2 = 5;
        circleCode[i].y2 = *p_i * 2;
    }

}