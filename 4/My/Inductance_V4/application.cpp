//application.cpp
//
// Created by Anatejl on 20.04.2024.
//

#include "application.h"
#include <iostream>

bool appGetConstantD(Application &app) {

    std::cout << "Input a D constant to compare:" << std::endl;
    std::cin >> app.const_D;
    std::cout << app.const_D << std::endl;

    app.current_element.first = 1;
    return true;
}

bool appInitializeData(Application &app) {

    std::cin >> app.current_element.second;

    if(!app.isFirst) {
        if (app.current_element.second < app.last_element) {
            app.delta_v = 0;
            app.delta_i = 0;
        } else {
            app.delta_v = app.current_element.second - app.tempLeft.second;
            app.delta_i = app.current_element.first - app.tempCS;
        }
    }
    return true;
}

bool appIsFirst(Application &app){
    if(!app.isFirst) {

    }
    return true;
}

bool appProcess(Application &app) {

    while(true) {
        if(pred_R1(&app)){
            app.finalLeft.first = 0;
            app.finalLeft.second = 0;
            app.finalRight.first = 0;
            app.finalRight.second = 0;
            app.isFirst = false;
            break;
        }

        if(pred_R2(&app)){
            app.tempCS = 0;
            app.tempLeft.first = app.current_element.first;
            app.tempLeft.second = app.current_element.second;
            app.tempRight.first = app.current_element.first;
            app.tempRight.second = app.current_element.second;
            app.last_element = app.current_element.second;
            //app.delta_v = 0;
            //app.delta_i = 0;
            ++app.current_element.first;
            break;
        }

        if(pred_R3(&app)){
            ++app.tempCS;
            app.tempRight.first = app.current_element.first;
            app.tempRight.second = app.current_element.second;
            //app.delta_v = app.current_element.second - app.tempLeft.second;
            //app.delta_i = app.current_element.first - app.tempCS;
            app.last_element = app.current_element.second;
            ++app.current_element.first;
            break;
        }

        if(pred_R4(&app)){
            ++app.tempCS;
            app.tempRight.first = app.current_element.first;
            app.tempRight.second = app.current_element.second;
            //app.delta_v = app.current_element.second - app.tempLeft.second;
            //app.delta_i = app.current_element.first - app.tempCS;
            app.last_element = app.current_element.second;
            ++app.current_element.first;
            break;
        }

        if (pred_R5(&app)){
            ++app.tempCS;
            app.tempRight.first = app.current_element.first;
            app.tempRight.second = app.current_element.second;

            app.finalLeft.first = app.tempLeft.first;
            app.finalLeft.second = app.finalLeft.second;
            app.finalRight.first = app.tempRight.first;
            app.finalRight.second = app.tempRight.second;
            app.finalCS = app.tempCS;

            //app.delta_v = app.current_element.second - app.tempLeft.second;
            //app.delta_i = app.current_element.first - app.tempCS;
            app.last_element = app.current_element.second;
            ++app.current_element.first;
            break;
        }

    }

    return true;
}

bool appGetOutputToUser(Application &app) {

    //DEBUG
    std::cout << app.current_element.first << " - Iteration" << std::endl;

    std::cout << "fLi - " << app.finalLeft.first << std::endl;
    std::cout << "fRi - " << app.finalRight.first << std::endl << std::endl;

    return true;
}

int appRun(Application &app) {

    if (!appGetConstantD(app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

    appProcess(app);

    //Default condition is "true", consider using "!std::con.eof()" for testing purposes.
    while(!std::cin.eof()) {
        if (!appInitializeData(app)) {
            std::cout << "DATA INPUT FAILURE." << std::endl;
            return 1;
        }

        if (!appProcess(app)) {
            std::cout << "DATA INPUT FAILURE." << std::endl << "No matches applicable." << std::endl;
            return 1;
        }

        if (!appGetOutputToUser(app)) {
            std::cout << "DATA INPUT FAILURE." << std::endl;
            return 1;
        }
        ++app.current_element.first;
    }

    return 0;
}