//
// Created by Anatejl on 20.04.2024.
//

#include "application.h"
#include <iostream>

bool operation(Callback callback, void *data) {
    return (*callback)(data);
}

bool appGetConstantD(void *app) {

    Application &tempApp = *(Application *) app;

    std::cout << "Input a D constant to compare:" << std::endl;
    std::cin >> tempApp.constD;
    std::cout << tempApp.constD << std::endl;

    return true;
}

bool appInitializeData(void *app) {

    Application &tempApp = *(Application *) app;

    tempApp.valueArray = vectorValueArrayInitialize(tempApp.valueArray);

    return true;
}

bool appProcessDataIntoFinalResult(void *app) {

    Application &tempApp = *(Application *) app;

    //DENOTE FOR GTEST ONLY
    //for (int i = 0; i < tempApp.valueArray.value.size(); ++i) {

    if ((tempApp.processIterator != vectorGetSize(tempApp.valueArray) - 1 &&
        tempApp.valueArray.value[tempApp.processIterator] > tempApp.valueArray.value[tempApp.processIterator + 1])
        ||
        (tempApp.processIterator == vectorGetSize(tempApp.valueArray) - 1)){

            if (tempApp.tempConsequenceStreak > tempApp.finalConsequenceStreak &&
                (tempApp.valueArray.value[tempApp.processIterator] -
                 tempApp.valueArray.value[tempApp.processIterator - (tempApp.tempConsequenceStreak - 1)] >
                 tempApp.constD ||
                 tempApp.valueArray.value[tempApp.processIterator] -
                 tempApp.valueArray.value[tempApp.processIterator - tempApp.tempConsequenceStreak] > tempApp.constD)) {

                if ((tempApp.finalLeft == INT_MAX && tempApp.finalRight == INT_MAX) &&
                    (tempApp.processIterator == tempApp.tempConsequenceStreak ||
                     tempApp.processIterator == tempApp.tempConsequenceStreak + 1)) {
                    tempApp.finalLeft = tempApp.processIterator - tempApp.tempConsequenceStreak;
                }
                else {
                    tempApp.finalLeft = tempApp.processIterator - (tempApp.tempConsequenceStreak - 1);
                }

                tempApp.finalRight = tempApp.processIterator;
                tempApp.finalConsequenceStreak = tempApp.tempConsequenceStreak;
            }

        tempApp.tempConsequenceStreak = 0;
    }


    if (tempApp.finalLeft == INT_MAX && tempApp.finalRight == INT_MAX && vectorGetSize(tempApp.valueArray) == 1) {
        tempApp.finalLeft = 0;
        tempApp.finalRight = 0;
    }

    ++tempApp.tempConsequenceStreak;
    ++tempApp.processIterator;

    //DENOTE FOR GTEST ONLY
    //if (i == tempApp.valueArray.value.size() - 1 && tempApp.finalLeft == INT_MAX && tempApp.finalRight == INT_MAX) {
    //    return false;
    //}
    //}

    return true;
}

bool appGetOutputToUser(void *app) {

    Application &tempApp = *(Application *) app;

    std::cout << std::endl << tempApp.finalLeft << " - Left Index" << std::endl;
    std::cout << tempApp.finalRight << " - Right Index" << std::endl;

    return true;
}

int appRun() {

    Application app;

    //std::cout << "tempapp - apprun "<< &tempApp << std::endl;

    // 1 - Get D  const
    if (!operation(&appGetConstantD, &app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

    // 2 - Read through cin
    while (!std::cin.eof()) {

        if (!operation(&appInitializeData, &app)) {
            std::cout << "DATA INPUT FAILURE." << std::endl;
            return 1;
        }
    }

    // 3 - Process data
    for (int i = 0; i < app.valueArray.value.size(); ++i) {

        operation(&appProcessDataIntoFinalResult, &app);

        if (i == app.valueArray.value.size() - 1 && app.finalLeft == INT_MAX && app.finalRight == INT_MAX) {
            std::cout << "DATA INPUT FAILURE." << std::endl;
            return 1;
        }
    }

    // 4 - Display result
    operation(&appGetOutputToUser, &app);

    return 0;
}
