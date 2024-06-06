//
// Created by Anatejl on 15.04.2024.
//

#ifndef NNTU_APPLICATION_H
#define NNTU_APPLICATION_H

#include <climits>
#include "vector.h"

//Data for program to handle
struct Application {


    int iteration = 1;
    bool judgement = false;
    int cin_read;

    int va = INT_MAX;
    int a0 = INT_MAX;
    int vb = INT_MAX;
    int b0 = INT_MAX;

};

// To execute application
int appRun(Application& app);

bool appGetData(Application &app);
bool appGetA(Application &app);
bool appGetB(Application &app);
bool appProcess(Application &app);
bool appDoOutput(Application &app);

#endif //NNTU_APPLICATION_H
