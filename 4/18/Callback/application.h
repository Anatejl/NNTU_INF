//
// Created by Anatejl on 15.04.2024.
//

#ifndef NNTU_APPLICATION_H
#define NNTU_APPLICATION_H

#include <climits>
#include "vector.h"

typedef bool (*Callback)(void *object);
bool operation (Callback callback, void *data);

//Temporary data storage
struct temp_data {

    initialVector cin_read;
    initialVector plato_candidate;
    int temp_counter = 0;
    int output_counter = 0;

};

//Data for program to handle
struct Application {

    temp_data temp_data;
    int constK;
    platoVector plato;

};

// To execute application

int appRun();
bool appInitializeK(void *app);
bool appInitializeData(void *app);
bool appProcessData(void *app);
bool appGetOutput(void *app);

#endif //NNTU_APPLICATION_H
