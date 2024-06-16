//
// Created by Anatejl on 20.04.2024.
//

#include "application.h"
#include <iostream>

int appRun(Application &app) {
    if (!appGetS(app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }
    while(!std::cin.eof()) {
        if (!appGetRead(app)) {
            std::cout << "DATA INPUT FAILURE." << std::endl;
            return 1;
        }
        if (!appProcess(app)) {
            std::cout << "DATA INPUT FAILURE." << std::endl;
            return 1;
        }
        if (!appMakeAnOutput(app)) {
            std::cout << "DATA INPUT FAILURE." << std::endl;
            return 1;
        }
        ++app.i;
    }
    return 0;
}

bool appGetS(Application &app) {
    std::cout << "Input an S constant:" << std::endl;
    std::cin >> app.constS;
    std::cout << app.constS << std::endl << std::endl;
    return true;
}

bool appGetRead(Application &app) {
    std::cin >> app.cin_read;
    if(std::cin.fail()){
        return false;
    }
    return true;
}

bool appProcess(Application &app) {
    app.tempSum += app.cin_read;
    if(app.tempSum > app.finalSum){
        app.finalSum = app.tempSum;
    }
    return true;
}

bool appMakeAnOutput(Application &app) {
    std::cout << app.i << " - ";
    //Output results
    if (app.finalSum > app.constS) {
        std::cout << app.finalSum << std::endl;
        //DEBUG ENTRY
        //std::cout << "DEBUG: " << app.tempSum << std::endl;
    }
    else {
        std::cout << "No valid result, for now..." << std::endl;
    }

    return true;
}