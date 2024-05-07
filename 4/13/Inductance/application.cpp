//
// Created by Anatejl on 20.04.2024.
//

#include "application.h"
#include "vector.h"
#include <iostream>
#include <numeric>


int appRun(Application &app) {

    if (!appInitializeData(app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

    if (!appInitializeA(app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

    if (!appInitializeB(app)) {
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



    return true;
}

bool appInitializeA(Application &app) {

    vectorAVectorInitialize(app.initialValueArray, app.va, app.a0);

    return true;
}

bool appInitializeB(Application &app) {



    return true;
}

bool appGetConstantD(Application &app) {



    return true;
}

bool appProcessDataIntoFinalResult(Application &app) {



    return true;
}

bool appGetOutputToUser(Application &app) {



    return true;
}
