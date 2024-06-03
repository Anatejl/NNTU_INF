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

    return true;
}

bool appInitializeData(Application &app) {

    std::cin >> app.current_element.second;

    return true;
}

bool appProcess(Application &app) {

    while(true) {

        if(algo_check_first_iteration(&app)){
            break;
        }

        if(algo_check_breakage(&app)){
            break;
        }

        if(!algo_check_ascending(&app)){
            break;
        }

        if(!algo_check_D(&app)){
            break;
        }

        break;
    }

    algo_update_last(&app);

    return true;
}

bool appGetOutputToUser(Application &app) {

    std::cout << app.current_element.first << " - Iteration" << std::endl;
    std::cout << "L - " << app.finalLeft.first << std::endl;
    std::cout << "R - " << app.finalRight.first << std::endl << std::endl;

    return true;
}

int appRun(Application &app) {

    if (!appGetConstantD(app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

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