//
// Created by Anatejl on 15.04.2024.
//
#pragma once
#ifndef NNTU_APPLICATION_H
#define NNTU_APPLICATION_H

#include <climits>
#include <utility>
#include <vector>

//Data for program to handle.
struct Application {

    //assume 1 - bool of whether radius belongs to the target
    //       2 - 1- Computed R of a given set of XY,
    //           2 - initial XY
    std::vector<std::pair <bool, std::pair<double, std::pair<int, int>>>> temp_group;
    std::pair <int, int>init_xy;

    //CIRCLE
    //Assume 1-X 2-Y
    std::pair<int,int> circle_center;
    std::pair<int,int> circle_edge;
    int circle_r;
    int const_k;
    int iteration = 1;
    bool isInBounds = false;
};

typedef bool (*Callback)(void *ADT);
bool operation(Callback callback, void *ADT);

// To execute application
int appRun();

bool appGetConstantK(void *object);
bool appGetCircleDimensions(void *object);
bool appInitializeData(void *object);
bool appProcessCurrentXYRadius(void *object);
bool appProcessResult(void *object);
bool appGetOutputToUser(void *object);

#endif //NNTU_APPLICATION_H
