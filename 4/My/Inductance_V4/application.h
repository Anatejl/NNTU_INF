//application.h
//
// Created by Anatejl on 15.04.2024.
//

#ifndef NNTU_APPLICATION_H
#define NNTU_APPLICATION_H

#include <climits>
#include <utility>
#include "predicator.h"

//Data for program to handle.
struct Application {

    //Assume 1- iteration 2 - element
    std::pair<int, int> tempLeft; //tRi, tRv
    std::pair<int, int> tempRight; //tRi, tRv
    int tempCS = 1; //tCS

    //Assume 1 - n 2 - value
    std::pair<int, int> finalLeft; //fLi, fLv
    std::pair<int, int> finalRight; //fRi, fRv
    int finalCS = 0; //fCS

    //Assume 1- iteration 2 - element
    std::pair<int, int> current_element; // x_n, n
    bool isFirst = true; // isFirst
    int last_element; //lx
    int delta_v=0; // ∆v
    int delta_i=0; // ∆i
    int const_D;

    std::pair <int, int> result; //y


};

// To execute application
int appRun(Application& app);
bool appInitializeData(Application &app);
bool appGetConstantD(Application &app);
bool appProcess(Application &app);
bool appGetOutputToUser(Application &app);

bool appIsFirst(Application &app);

#endif //NNTU_APPLICATION_H
