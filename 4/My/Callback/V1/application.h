//
// Created by Anatejl on 15.04.2024.
//

#ifndef NNTU_APPLICATION_H
#define NNTU_APPLICATION_H

#include <climits>
#include "vector.h"

//Data for program to handle.
struct Application {

    Vector valueArray;

    int constD;
    int finalLeft = INT_MAX;
    int finalRight = INT_MAX;
    int finalConsequenceStreak = 0;
    int tempConsequenceStreak = 0;
};

typedef bool (*Callback)(void *object);

bool operation(Callback callback, void *data);

// To execute application

int appRun(void *app);
bool appInitializeData(void *app);
bool appGetConstantD(void *app);
bool appProcessDataIntoFinalResult(void *app);
bool appGetOutputToUser(void *app);

#endif //NNTU_APPLICATION_H
