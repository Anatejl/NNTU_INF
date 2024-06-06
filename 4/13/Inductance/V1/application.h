//
// Created by Anatejl on 15.04.2024.
//

#ifndef NNTU_APPLICATION_H
#define NNTU_APPLICATION_H

#include <climits>
#include "vector.h"

//Data for program to handle
struct Application {

    initialVector initialArray;

    int va = INT_MAX;
    int a0 = INT_MAX;
    int vb = INT_MAX;
    int b0 = INT_MAX;

};

// To execute application
int appRun(Application& app);

bool appInitializeData(Application &app);
bool appInitializeA(Application &app);
bool appInitializeB(Application &app);
bool appProcessDataIntoFinalResult(Application &app);
bool appGetOutputToUser(Application &app);

#endif //NNTU_APPLICATION_H
