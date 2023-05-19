#include "data.h"

void circlesArray() {

    int i = 0;
    int *p_i = &i;
    for (i = 0; i < CIRCLES_MAX; i++) {

        circleMaster[i].x = 0;
        circleMaster[i].y = 0;

        circleMaster[i].a = circleMaster[i].x;
        circleMaster[i].b = *p_i * 2;
    }

}