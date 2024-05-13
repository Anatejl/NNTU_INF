//
// Created by Anatejl on 15.04.2024.
//
#pragma once
#ifndef NNTU_APPLICATION_H
#define NNTU_APPLICATION_H

#include <climits>
#include "vector.h"

//Data for program to handle.
struct Application {

    //DATA
    initialVector initialArray;
    finalVector finalArray;

    //CIRCLE
    //Assume 1-X 2-Y
    std::pair<int,int> circleCenter;
    std::pair<int,int> circleEdge;
    int circleR;
    int constK;
};

// To execute application
int appRun(Application& app);

bool appInitializeData(Application &app);
bool appGetCircleDimensions(Application &app);
bool appGetConstantD(Application &app);
bool appGetConstantK(Application &app);
bool appProcessXYArrayIntoRArray(Application &app);
bool appProcessFinalResult(Application &app);
bool appGetOutputToUser(Application &app);

#endif //NNTU_APPLICATION_H
