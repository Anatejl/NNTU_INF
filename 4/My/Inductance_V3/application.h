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

// To execute application
int appRun(Application& app);
bool appInitializeData(Application &app);
bool appGetConstantD(Application &app);
bool appProcess(Application &app);
bool appGetOutputToUser(Application &app);

#endif //NNTU_APPLICATION_H
