//
// Created by Anatejl on 20.04.2024.
//

#include "application.h"
#include <iostream>

bool operation(Callback callback, void *data) {
    return (*callback)(data);
}

bool appGetS(void *data) {

    Application &app = *(Application*) data;

    std::cout << "Input an S constant:" << std::endl;
    std::cin >> app.constS;
    std::cout << app.constS << std::endl << std::endl;

    return true;
}

bool appGetRead(void *data) {

    Application &app = *(Application*) data;

    std::cin >> app.cin_read;

    if(std::cin.fail()){
        return false;
    }

    return true;
}

bool appProcess(void *data) {

    Application &app = *(Application*) data;

    if (app.cin_read > 0){
        app.finalSum += app.cin_read;
    }

    return true;
}

bool appMakeAnOutput(void *data) {

    Application &app = *(Application*) data;

    std::cout << app.i << " - ";
    //Output results
    if (app.finalSum > app.constS) {
        std::cout << app.finalSum << std::endl;
    }
    else {
        std::cout << "No valid result, for now..." << std::endl;
    }

    return true;
}

int appRun() {

    Application app;

    if (!operation(&appGetS, &app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

    while(!std::cin.eof()) {
        if (!operation(&appGetRead, &app)) {
            std::cout << "DATA INPUT FAILURE." << std::endl;
            return 1;
        }

        if (!operation(&appProcess, &app)) {
            std::cout << "DATA INPUT FAILURE." << std::endl;
            return 1;
        }

        if (!operation(&appMakeAnOutput, &app)) {
            std::cout << "DATA INPUT FAILURE." << std::endl;
            return 1;
        }
        ++app.i;
    }
    return 0;
}