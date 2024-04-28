//
// Created by Anatejl on 15.04.2024.
//

#ifndef NNTU_APPLICATION_H
#define NNTU_APPLICATION_H

#include "vector.h"

//Data for program to handle.
struct Application {

    Vector valueArray;
    Vector indexArray;
    unsigned constD;

    unsigned finalLeft = -1;
    unsigned finalRight = -1;
    unsigned finalConsequenceStreak = 0;
};

// To execute application
int appRun(Application& app);

#endif //NNTU_APPLICATION_H
