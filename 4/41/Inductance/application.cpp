//
// Created by Anatejl on 20.04.2024.
//

#include "application.h"
#include "vector.h"
#include <vector>
#include <iostream>
#include  <stdlib.h>

int appRun(Application &app) {

    if (!appGetConstantD(app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

    if (!appGetConstantK(app)) {
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

bool appInitializeData(Application &app) {
    app.initialArray = vectorInitialArrayInitialize(app.initialArray, app.constK);
    std::cout << "Input array has been successfully processed." << std::endl;

    return true;
}

bool appGetConstantD(Application &app) {
    std::cout << "Input a R constant:" << std::endl;
    app.constR = 2;
    std::cout << app.constR << std::endl;

    return true;
}

bool appGetConstantK(Application &app) {
    std::cout << "Input a K constant:" << std::endl;
    app.constK = 3;
    std::cout << app.constK << std::endl;

    return true;
}

bool appProcessDataIntoFinalResult(Application &app) {

    for(int i = 0; i < 10; ++i) {
        std::cout << std::rand() % 101 << std::endl;
    }
    return true;
}

bool appGetOutputToUser(Application &app) {



    return true;
}
