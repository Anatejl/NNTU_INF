//application.h
//
// Created by Anatejl on 15.04.2024.
//

#ifndef NNTU_APPLICATION_H
#define NNTU_APPLICATION_H

#include "vector.h"

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

int appRun(Application &app);
bool appInitializeK(Application &app);
bool appInitializeData(Application &app);
bool appProcessData(Application &app);
bool appGetOutput(Application &app);

#endif //NNTU_APPLICATION_H
