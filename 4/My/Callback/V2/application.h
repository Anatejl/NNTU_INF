//
// Created by Anatejl on 15.04.2024.
//

#ifndef NNTU_APPLICATION_H
#define NNTU_APPLICATION_H

#include <climits>
#include "vector.h"

struct temp_data {

    Vector cin_read;
    int tempConsequenceStreak = 0;
    int processIterator = 0;
    int outputIterator = 0;

};

struct Application {

    Vector valueArray;
    temp_data temp_data;

    int constD = 0;
    int finalLeft = INT_MAX;
    int finalRight = INT_MAX;
    int finalConsequenceStreak = 0;

};

typedef bool (*Callback)(void *object);
bool operation(Callback callback, void *data);

int appRun();
bool appInitializeData(void *app);
bool appGetConstantD(void *app);
bool appProcessData(void *app);
bool appGetOutputToUser(void *app);

#endif //NNTU_APPLICATION_H
