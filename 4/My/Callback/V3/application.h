//application.h
//
// Created by Anatejl on 15.04.2024.
//

#ifndef NNTU_APPLICATION_H
#define NNTU_APPLICATION_H

#include <climits>
#include <utility>
#include "algo.h"

//Data for program to handle.
struct Application {

    int const_D;

    //Assume 1- iteration 2 - element
    std::pair<int, int> current_element;
    std::pair<int, int> last_element;

    //Assume 1 - index 2 - value
    std::pair<int, int> finalLeft;
    std::pair<int, int> finalRight;
    int finalCS = 0;
    int tempCS = 0;
};

typedef bool (*Callback)(void *object);
bool operation(Callback callback, void *data);

// To execute application
int appRun();
bool appInitializeData(void *object);
bool appGetConstantD(void *object);
bool appProcess(void *object);
bool appGetOutputToUser(void *object);

#endif //NNTU_APPLICATION_H
