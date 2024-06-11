//
// Created by Anatejl on 20.04.2024.
//

#include "application.h"
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
    std::cout << "Input a R constant, to compare adjacent values:" << std::endl;
    std::cin >> app.constR;
    std::cout << app.constR << std::endl;

    return true;
}

bool appInitializeData(Application &app) {
    app.initialValueArray = vectorValueArrayInitialize(app.initialValueArray);
    std::cout << "Input array has been successfully processed." << std::endl;

    return true;
}

bool appProcessDataIntoFinalResult(Application &app) {

    for (int i = 0; i < vectorGetSize(app.initialValueArray); ++i) {

        if ((app.initialValueArray.value[i] - app.initialValueArray.value[i - 1] > app.constR) ||
            ((i != 0 && app.initialValueArray.value[i] == 0) && (app.initialValueArray.value[i - 1] - app.initialValueArray.value[i] > app.constR))
                ){
            app.finalValueArray.value.push_back(
                    std::make_pair(app.initialValueArray.value[i - 1], app.initialValueArray.value[i]));
        }

        if (i == vectorGetSize(app.initialValueArray) && vectorGetEmpty(app.initialValueArray)) {
            return false;
        }

        if (i == 0 && vectorGetSize(app.initialValueArray) == 1) {
            std::cout << std::endl << "Can't compare with void." << std::endl;
            return false;
        }
    }

    return true;
}

bool appGetOutputToUser(Application &app) {

    //Output results
    if (!vectorGetEmpty_pair(app.finalValueArray)) {

        std::cout << std::endl << "Final values are (Index - Left element / Right element):" << std::endl;

        for (int i = 0; i < vectorGetSize_pair(app.finalValueArray); ++i) {
            std::cout << "Index: " << i+1 << " - " << app.finalValueArray.value[i].first <<
                      "/" << app.finalValueArray.value[i].second << std::endl;
        }
    }

    else {
        std::cout << std::endl << "No matches are applicable." << std::endl;
        return false;
    }

    return true;
}