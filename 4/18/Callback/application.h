//application.h
//
// Created by Anatejl on 15.04.2024.
//

#ifndef NNTU_APPLICATION_H
#define NNTU_APPLICATION_H

#include <utility>

//Temporary data storage
struct temp_data {

    // 1-n, 2-value
    std::pair <int, int> cin_read_current;
    // 1-streak
    std::pair <int, int> temp_counter;

};

//Data for program to handle
struct Application {

    temp_data temp_data;
    int constK;
    int last_plato;

    // 1-streak, 2-value
    std::pair <int, int> final;

};

typedef bool (*Callback)(void *object);
bool operation(Callback callback, void *data);

// To execute application

int appRun();
bool appInitializeK(void *p_app);
bool appInitializeData(void *p_app);
bool appProcessData(void *p_app);
bool appGetOutput(void *p_app);

#endif //NNTU_APPLICATION_H
