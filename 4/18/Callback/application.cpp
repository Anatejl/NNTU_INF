//application.cpp
//
// Created by Anatejl on 20.04.2024.
//

#include "application.h"
#include <iostream>

bool operation(Callback callback, void *data) {
    return (*callback)(data);
}

bool appInitializeK(void *p_app) {

    Application &app = *(Application*) p_app;

    std::cin >> app.constK;

    //assign controlled value to i counter
    app.temp_data.cin_read_current.first = INT_MAX;

    if (std::cin.fail()) {
        return false;
    }

    return true;
}

bool appInitializeData(void *p_app) {

    Application &app = *(Application*) p_app;

    std::cin >> app.temp_data.cin_read_current.second;

    //assign 0 or ++ to counter, based on i
    if(app.temp_data.cin_read_current.first == INT_MAX){
        app.temp_data.cin_read_current.first = 0;
    }
    else{
        ++app.temp_data.cin_read_current.first;
    }

    return true;
}

bool appProcessData(void *p_app) {

    Application &app = *(Application*) p_app;

    //check for first iteration, do special things for it
    if(app.temp_data.cin_read_current.first==0){
        ++app.temp_data.temp_counter.first;
        app.temp_data.temp_counter.second = app.temp_data.cin_read_current.second;
        return true;
    }

    //check for x_n == x_n-1
    if (app.temp_data.cin_read_current.second == app.temp_data.temp_counter.second){
        ++app.temp_data.temp_counter.first;
    }
    else{
        app.temp_data.temp_counter.first = 1;
        app.temp_data.temp_counter.second = app.temp_data.cin_read_current.second;
        app.last_plato = app.final.first;
    }

    //check for current plato counter > K,
    // if so then assign current values to final to display
    if (app.temp_data.temp_counter.first > app.last_plato && app.temp_data.temp_counter.first > app.constK){
        app.final.first = app.temp_data.temp_counter.first;
        app.final.second = app.temp_data.temp_counter.second;
    }

    return true;
}

bool appGetOutput(void *p_app) {

    Application &app = *(Application*) p_app;

    std::cout << app.temp_data.cin_read_current.first << " - Iteration: ";
    std::cout << app.final.first << " of " << app.final.second << std::endl;

    return true;
}

int appRun() {

    Application app;

    if (!operation(&appInitializeK, &app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

    while (!std::cin.eof()) {

        //Get Value from cin
        if (!operation(&appInitializeData, &app)) {
            std::cout << "DATA INPUT FAILURE." << std::endl;
            return 1;
        }

        if (!operation(&appProcessData, &app)) {
            std::cout << "DATA INPUT FAILURE." << std::endl;
            return 1;
        }

        if (!operation(&appGetOutput, &app)) {
            std::cout << "DATA INPUT FAILURE." << std::endl;
            return 1;
        }
    }

    return 0;
}