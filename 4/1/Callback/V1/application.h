//
// Created by Anatejl on 15.04.2024.
//

#ifndef NNTU_APPLICATION_H
#define NNTU_APPLICATION_H

#include "vector.h"

typedef bool (*Callback)(void *object);
bool operation (Callback callback, void *data);

//Data for program to handle.
struct Application {

    VectorPair finalValueArray;
    int constR = 0;
    int lastRight = 0;
    int processIteratorCounter = 0;
};

// To execute application
int appRun();

bool appGetConstantD(void *app);
bool appProcessResult(void *app);
bool appGetOutputToUser(void *app);

#endif //NNTU_APPLICATION_H
