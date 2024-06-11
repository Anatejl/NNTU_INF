//
// Created by Anatejl on 15.04.2024.
//

#ifndef NNTU_APPLICATION_H
#define NNTU_APPLICATION_H

#include <climits>

typedef bool (*Callback)(void *object);

bool operation(Callback callback, void *data);

//Data for program to handle.
struct Application {
    int prevValue = INT_MIN;
    int curValue = INT_MIN;
    int curIndex = 0;
    int constR = 0;
};

// To execute application
int appRun(Application &app);

bool inputNextValue(void *rawApp);

bool processCurrentValue(void *rawApp);

bool printCurrentResult(void *rawApp);

#endif //NNTU_APPLICATION_H
