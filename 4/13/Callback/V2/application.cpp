//
// Created by Anatejl on 20.04.2024.
//

#include "application.h"
#include <iostream>

bool operation(Callback callback, void *abstract) {
    return (*callback)(abstract);
}

bool appGetA(void *abstract) {

    Application &app = *(Application*) abstract;

    if (app.va == INT_MAX && app.a0 == INT_MAX) {
        std::cin >> app.va >> app.a0;
    }
    else {
        app.current_A = app.va * app.iteration + app.a0;
    }
    return true;
}

bool appGetB(void *abstract) {

    Application &app = *(Application*) abstract;

    if (app.vb == INT_MAX && app.b0 == INT_MAX) {
        std::cin >> app.vb >> app.b0;
    }
    else {
        app.current_B = app.vb * app.iteration + app.b0;
    }

    return true;
}

bool appGetData(void *abstract) {

    Application &app = *(Application*) abstract;

    std::cin >> app.cin_read;

    if(std::cin.fail()){
        return false;
    }

    return true;
}

bool appProcess(void *abstract) {

    Application &app = *(Application*) abstract;

    if(app.cin_read > app.current_A && app.cin_read < app.current_B){
       return true;
    }

    return false;
}

bool appDoOutput(void *abstract) {

    Application &app = *(Application*) abstract;

    std::cout << app.iteration << " - " << app.cin_read << std::endl;

    //DEBUG
    std::cout << app.current_A << " ÷ " << app.current_B << std::endl << std::endl;

    return true;
}

int appRun() {

    Application app;

    if (!operation(&appGetA, &app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

    if (!operation(&appGetB, &app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

    while(!std::cin.eof()) {
        if (!operation(&appGetData, &app)) {
            std::cout << "DATA INPUT FAILURE." << std::endl;
            return 1;
        }

        if (!operation(&appGetA, &app)) {
            std::cout << "DATA INPUT FAILURE." << std::endl;
            return 1;
        }

        if (!operation(&appGetB, &app)) {
            std::cout << "DATA INPUT FAILURE." << std::endl;
            return 1;
        }

        if (operation(&appProcess, &app)) {
            operation(&appDoOutput, &app);
        }
        ++app.iteration;
    }
    return 0;
}