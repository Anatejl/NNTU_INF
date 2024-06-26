//
// Created by Anatejl on 15.04.2024.
//

#ifndef NNTU_APPLICATION_H
#define NNTU_APPLICATION_H

#include <climits>

//Data for program to handle
struct Application {
    int iteration = 1;
    int cin_read;
    bool in_bounds = false;

    /*Since we can't invoke function for it return its value as int,
    now we store A/B as a distinct variables, rather than gaining
    A/B reading by straight invoking its corresponding function*/
    int current_A, current_B;

    int va = INT_MAX;
    int a0 = INT_MAX;
    int vb = INT_MAX;
    int b0 = INT_MAX;
};

typedef bool (*Callback)(void *abstract);
bool operation(Callback callback, void *abstract);

// To execute application

int appRun();
bool appGetData(void *abstract);
bool appGetA(void *abstract);
bool appGetB(void *abstract);
bool appProcess(void *abstract);
bool appDoOutput(void *abstract);

#endif //NNTU_APPLICATION_H
