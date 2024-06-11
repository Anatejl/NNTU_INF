//
// Created by l3t on 11.06.2024.
//

#ifndef NNTU_APPLICATION_H
#define NNTU_APPLICATION_H

#include <climits>
#include <iostream>

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

std::string formatResult(Application &app, bool isFirst);
bool inputConstantR(Application &app);
bool inputNextValue(Application &app);
bool processCurrentValue(Application &app);
bool printCurrentResult(Application &app);

#endif //NNTU_APPLICATION_H
