//
// Created by Anatejl on 15.04.2024.
//

#ifndef NNTU_APPLICATION_H
#define NNTU_APPLICATION_H

#include <climits>
#include "vector.h"

//Data for program to handle.
struct Application {

    initialVector initialValueArray;
    initialVector sortedArray;

    int va = 0;
    int a0 = 0;
    int vb = 0;
    int b0 = 0;

};

// To execute application
int appRun(Application& app);

bool appInitializeData(Application &app);
bool appInitializeA(Application &app);
bool appInitializeB(Application &app);
bool appProcessDataIntoFinalResult(Application &app);
bool appGetOutputToUser(Application &app);

#endif //NNTU_APPLICATION_H
