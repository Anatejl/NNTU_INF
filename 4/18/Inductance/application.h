//application.h
//
// Created by Anatejl on 15.04.2024.
//

#ifndef NNTU_APPLICATION_H
#define NNTU_APPLICATION_H

#include <utility>

//Temporary data storage
struct temp_data {
    // 1-n, 2-x
    std::pair <int, int> cin_read_current;
    // 1-streak 2-x
    std::pair <int, int> temp_counter;
};

//Data for program to handle
struct Application {
    temp_data temp_data;
    //k
    int constK;
    //lp
    int last_plato;
    // 1-streak, 2-x
    std::pair <int, int> final;
};

int appRun(Application &app);
bool appInitializeK(Application &app);
bool appInitializeData(Application &app);
bool appProcessData(Application &app);
bool appGetOutput(Application &app);

#endif //NNTU_APPLICATION_H