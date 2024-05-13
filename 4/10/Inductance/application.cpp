//
// Created by Anatejl on 20.04.2024.
//

#include "application.h"
#include "vector.h"
#include <iostream>

int appRun(Application &app) {

    if (!appGetConstantD(app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

    if (!appInitializeData(app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

    if (!appProcessDataIntoFinalResult(app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

    if (!appGetOutputToUser(app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

    return 0;
}

bool appGetConstantD(Application &app) {
    std::cout << "Input an S constant:" << std::endl;
    std::cin >> app.constS;
    std::cout << app.constS << std::endl;

    return true;
}

bool appInitializeData(Application &app) {
    app.initialValueArray = vectorValueArrayInitialize(app.initialValueArray);
    std::cout << "Input array has been successfully processed." << std::endl;

    return true;
}

bool appProcessDataIntoFinalResult(Application &app) {

    int tempSumm = 0;

    for (int i = 0; i <  app.initialValueArray.counter; ++i) {
        if((tempSumm + app.initialValueArray.value[i]) > tempSumm) {
            tempSumm += app.initialValueArray.value[i];
        }
    }
    if (tempSumm >= app.constS) {
        app.finalSumm = tempSumm;
    }

    return true;
}

bool appGetOutputToUser(Application &app) {

    //Output results
    if (app.finalSumm > 0) {
        std::cout << std::endl << "Final summ is - " << app.finalSumm << std::endl;
    }
    else {
        std::cout << "Entered data doesn't resolve into acceptable value." << std::endl;
        return false;
    }

    return true;
}