#include "data.h"

void circlesArray() {

    int i = 0;
    int *p_i = &i;
    for (i = 0; i < CIRCLES_MAX; i++) {

        circleCode[i].x = 0;
        circleCode[i].y = 0;

        circleCode[i].a = circleCode[i].x;
        circleCode[i].b = *p_i * 2;
    }

}