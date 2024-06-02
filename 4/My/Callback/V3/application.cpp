//application.cpp
//
// Created by Anatejl on 20.04.2024.
//

#include "application.h"
#include "algo.h"
#include <iostream>

bool operation(Callback callback, void *data) {
    return (*callback)(data);
}



bool appGetConstantD(void *object) {

    Application &app = *((Application*) object);

    std::cout << "Input a D constant to compare:" << std::endl;
    std::cin >> app.const_D;
    std::cout << app.const_D << std::endl;

    return true;
}

bool appInitializeData(void *object) {

    Application &app = *((Application*) object);

    std::cin >> app.current_element.second;

    return true;
}

bool appProcess(void *object) {

    Application &app = *((Application*) object);

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

bool appGetOutputToUser(void *object) {

    Application &app = *((Application*) object);

    std::cout << app.current_element.first << " - Iteration" << std::endl;
    std::cout << "L - " << app.finalLeft.first << std::endl;
    std::cout << "R - " << app.finalRight.first << std::endl << std::endl;

    return true;
}

int appRun() {

    Application app;

    if (!operation(&appGetConstantD, &app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

    //Default condition is "true", consider using "!std::con.eof()" for testing purposes.
    while(!std::cin.eof()) {
        if (!operation(&appInitializeData, &app)) {
            std::cout << "DATA INPUT FAILURE." << std::endl;
            return 1;
        }

        if (!operation(&appProcess, &app)) {
            std::cout << "DATA INPUT FAILURE." << std::endl << "No matches applicable." << std::endl;
            return 1;
        }

        if (!operation(&appGetOutputToUser, &app)) {
            std::cout << "DATA INPUT FAILURE." << std::endl;
            return 1;
        }
        ++app.current_element.first;
    }

    return 0;
}