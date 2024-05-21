//
// Created by Anatejl on 15.04.2024.
//

#ifndef NNTU_APPLICATION_H
#define NNTU_APPLICATION_H

#include <climits>
#include "vector.h"

typedef bool (*Callback)(void *object);
bool operation (Callback callback, void *data);

struct tempVar {

    int first = 0;
    int second = 0;

};

//Data for program to handle
struct Application {

    initialVector initialArray;
    tempVar temp_var;

    int va = INT_MAX;
    int a0 = INT_MAX;
    int vb = INT_MAX;
    int b0 = INT_MAX;

};

// To execute application
int appRun();

bool appInitializeData(void *app);
bool appInitializeA(void *app);
bool appInitializeB(void *app);
bool appProcessDataIntoFinalResult(void *app);
bool appGetOutputToUser(void *app);

#endif //NNTU_APPLICATION_H
