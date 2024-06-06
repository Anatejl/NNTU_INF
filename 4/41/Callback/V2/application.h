//
// Created by Anatejl on 15.04.2024.
//
#pragma once
#ifndef NNTU_APPLICATION_H
#define NNTU_APPLICATION_H

#include "vector.h"

//GLORIOUS CALLBACK DECLARATION
typedef bool (*Callback)(void *object);
bool operation (Callback callback, void *data);

//Data for program to handle.

//ZA UPOKOI OTCA I SVYATOGO DYHA
struct tempVar {

    //Iterators for cycles
    int first = 0;
    int second = 0;
    int third = 0;

    //Processing function "temporary" sequence streak storage
    int tempSeqStreak = 0;

    //Blank vector
    std::vector<int> column;
    //Template for.insideTheCircleGroup
    std::vector<std::vector<int>> tempFinal;

};

struct Application {

    //DATA
    initialVector initialArray;
    finalVector finalArray;
    tempVar temp_var;

    //CIRCLE
    //Assume 1-X 2-Y
    std::pair<int,int> circleCenter;
    std::pair<int,int> circleEdge;
    int circleR;
    int constK;
};



//To execute application
int appRun();

bool appInitializeData(void *app);
bool appGetCircleDimensions(void *app);
bool appGetConstantK(void *app);
bool appProcessXYArrayIntoRArray(void *app);
bool appProcessFinalResult(void *app);
bool appGetOutputToUser(void *app);

#endif //NNTU_APPLICATION_H
