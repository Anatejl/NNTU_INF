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
    Vector seqTracker;
    unsigned constD;

    //unsigned finalLeftByValue = 0 ;
    //unsigned finalRightByValue = -1;

    unsigned finalLeftByIndex = 0;
    unsigned finalRightByIndex = 0;
    unsigned finalConsequenceStreak = 0;
};

// To execute application
int appRun(Application& app);

#endif //NNTU_APPLICATION_H
