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

    if (std::cin.fail()) {
        return false;
    }

    return true;
}

bool appInitializeData(void *app) {
    Application &tempApp = *(Application *) app;

    tempApp.temp_data.cin_read.value.push_back(vectorValueInitialize());

    return true;
}

bool appProcessData(void *app) {
    Application &tempApp = *(Application *) app;

    //DENOTE FOR GTEST ONLY
    //for (int i = 0; i < tempApp.temp_data.cin_read.value.size(); ++i) {

    for (; tempApp.temp_data.processIterator < tempApp.temp_data.cin_read.value.size(); ++tempApp.temp_data.
           processIterator) {
        if (tempApp.temp_data.cin_read.value[tempApp.temp_data.processIterator] >
            tempApp.temp_data.cin_read.value[tempApp.temp_data.processIterator - tempApp.temp_data.tempConsequenceStreak]) {
            tempApp.temp_data.tempConsequenceStreak = 0;
            tempApp.temp_data.leftWritten = false;
            }
        else if (tempApp.temp_data.processIterator == 0) {
            tempApp.finalLeft = tempApp.temp_data.processIterator;
            tempApp.finalRight = tempApp.temp_data.processIterator;
        }
        else {
            if (tempApp.temp_data.leftWritten == false) {
                tempApp.finalLeft = tempApp.temp_data.processIterator;
                tempApp.temp_data.leftWritten = true;
            }
            tempApp.finalRight = tempApp.temp_data.processIterator;
            ++tempApp.temp_data.tempConsequenceStreak;
        }
        //DENOTE FOR GTEST ONLY
        //if (i == tempApp.temp_data.processIterator && tempApp.finalLeft == INT_MAX && tempApp.finalRight == INT_MAX) {
        //    return false;
        //}
        //}
    }
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

        // 1 - Get D const
        if (!operation(&appGetConstantD, &app)) {
            std::cout << "DATA INPUT FAILURE." << std::endl;
            return 1;
        }

        // 2 - Work on input
        while (!std::cin.eof()) {
            if (!operation(&appInitializeData, &app)) {
                std::cout << "DATA INPUT FAILURE." << std::endl;
                return 1;
            }

            if (!operation(&appProcessData, &app)) {
                std::cout << "DATA INPUT FAILURE." << std::endl;
                return 1;
            }
        }

        // 3 - Display result
        if (app.finalRight - app.finalLeft < app.constD ||
            (app.temp_data.processIterator - 1 == app.valueArray.value.size() - 1 && app.finalLeft == INT_MAX && app.
             finalRight == INT_MAX)) {
            std::cout << "DATA INPUT FAILURE." << std::endl;
            return 1;
        }
        // ReSharper disable once CppRedundantElseKeywordInsideCompoundStatement
        else {
            operation(&appGetOutputToUser, &app);
        }

        return 0;
    }
