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

    Application &tempApp = *(Application*)app;
    
    std::cout << "Input a R constant, to compare adjacent values:" << std::endl;
    std::cin >> tempApp.constR;
    std::cout << tempApp.constR << std::endl;

    return true;
}

bool appInitializeData(void *app) {

    Application &tempApp = *(Application*)app;

    tempApp.initialValueArray.value.push_back(vectorValueInitialize());

    return true;
}

bool appProcessDataIntoFinalResult(void *app) {

    Application &tempApp = *(Application*)app;
    
    for (int i = 0; i < vectorGetSize(tempApp.initialValueArray); ++i) {

        if ((tempApp.initialValueArray.value[i] - tempApp.initialValueArray.value[i - 1] > tempApp.constR) ||
            ((i != 0 && tempApp.initialValueArray.value[i] == 0) && (tempApp.initialValueArray.value[i - 1] - tempApp.initialValueArray.value[i] > tempApp.constR))
            ){
            tempApp.finalValueArray.value.push_back(
                std::make_pair(tempApp.initialValueArray.value[i - 1], tempApp.initialValueArray.value[i]));
        }

        if (i == vectorGetSize(tempApp.initialValueArray) && vectorGetEmpty(tempApp.initialValueArray)) {
            return false;
        }

        if (i == 0 && vectorGetSize(tempApp.initialValueArray) == 1) {
            std::cout << std::endl << "Can't compare with void." << std::endl;
            return false;
        }
    }

    return true;
}

bool appGetOutputToUser(void *app) {

    Application &tempApp = *(Application*)app;
    
    //Output results
    if (!vectorGetEmpty_pair(tempApp.finalValueArray)) {

        std::cout << std::endl << "Final values are (Index - Left element / Right element):" << std::endl;

        for (int i = 0; i < vectorGetSize_pair(tempApp.finalValueArray); ++i) {
            std::cout << "Index: " << i+1 << " - " << tempApp.finalValueArray.value[i].first <<
                    "/" << tempApp.finalValueArray.value[i].second << std::endl;
        }
    }

    else {
        std::cout << std::endl << "No matches are applicable." << std::endl;
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

    if (!operation(&appInitializeData, &app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

    if (!operation(&appProcessDataIntoFinalResult, &app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

    if (!operation(&appGetOutputToUser, &app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

    return 0;
}