//
// Created by Anatejl on 15.04.2024.
//

#ifndef NNTU_APPLICATION_H
#define NNTU_APPLICATION_H

#include "vector.h"

//Data for program to handle.
struct Application {

    Vector initialValueArray;
    VectorPair finalValueArray;
    int constR;
};

// To execute application
int appRun(Application& app);

bool appInitializeData(Application &app);
bool appGetConstantD(Application &app);
bool appProcessDataIntoFinalResult(Application &app);
bool appGetOutputToUser(Application &app);

#endif //NNTU_APPLICATION_H
