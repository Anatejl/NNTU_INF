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

    //assume 1 - Computed R of a given set of XY, 2 - initial XY
    std::vector<std::pair <bool, std::pair<double, std::pair<int, int>>>> temp_group;
    bool temp_eligible = false;
    std::pair <int, int>init_xy;

    //CIRCLE
    //Assume 1-X 2-Y
    std::pair<int,int> circle_center;
    std::pair<int,int> circle_edge;
    int circle_r;
    int const_k;
    int iteration = 0;
};

// To execute application
int appRun(Application& app);

bool appInitializeData(Application &app);
bool appGetCircleDimensions(Application &app);
bool appGetConstantD(Application &app);
bool appGetConstantK(Application &app);
bool appProcessCurrentXYRadius(Application &app);
bool appProcessResult(Application &app);
bool appGetOutputToUser(Application &app);

#endif //NNTU_APPLICATION_H
