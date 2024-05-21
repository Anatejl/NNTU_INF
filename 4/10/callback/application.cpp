//
// Created by Anatejl on 20.04.2024.
//

#include "application.h"
#include "vector.h"
#include <iostream>

bool operation(Callback callback, void *data) {
    return (*callback)(data);
}

bool appGetConstantD(void *app) {

    Application &tempApp = *(Application*) app;

    std::cout << "Input an S constant:" << std::endl;
    std::cin >> tempApp.constS;
    std::cout << tempApp.constS << std::endl;

    if(std::cin.fail()) {
        return false;
    }

    return true;
}

bool appInitializeData(void *app) {

    Application &tempApp = *( Application* ) app;

    tempApp.initialValueArray.value.push_back(vectorValueInitialize());

    if(std::cin.fail()) {
        return false;
    }

    return true;
}

bool appProcessDataIntoFinalResult(void *app) {

    Application &tempApp = *(Application*) app;

    if(vectorAccumulate(tempApp.initialValueArray) + tempApp.initialValueArray.value.back()
        > vectorAccumulate(tempApp.initialValueArray) )  {

    tempApp.finalSumm += tempApp.initialValueArray.value.back();
    }

    return true;
}

bool appGetOutputToUser(void *app) {

    Application &tempApp = *(Application*) app;

    //Output results
    if (tempApp.finalSumm > tempApp.constS) {
        std::cout << std::endl << "Final summ is - " << tempApp.finalSumm << std::endl;
    }
    else {
        std::cout << "Entered data doesn't resolve into acceptable value." << std::endl;
        return false;
    }

    return true;
}

int appRun() {

    Application app;

    if (!operation(&appGetConstantD, &app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

    while(!std::cin.eof()) {
        if (!operation(&appInitializeData, &app)) {
            std::cout << "DATA INPUT FAILURE." << std::endl;
            return 1;
        }

        if (!operation(&appProcessDataIntoFinalResult, &app)) {
            std::cout << "DATA INPUT FAILURE." << std::endl;
            return 1;
        }
    }

    if (!operation(&appGetOutputToUser, &app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

    return 0;
}