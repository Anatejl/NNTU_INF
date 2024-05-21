//
// Created by Anatejl on 20.04.2024.
//

#include "application.h"
#include <iostream>

bool operation(Callback callback, void *data) {
    return (*callback)(data);
}

bool appInitializeA(void *app) {
    Application &tempApp = *(Application *) app;

    if (tempApp.va != INT_MAX && tempApp.a0 != INT_MAX) {
        tempApp.initialArray.AVector.push_back(
            vectorAVectorInitialize(tempApp.va, tempApp.a0, tempApp.temp_var.second));
    }
    else {
        std::cin >> tempApp.va >> tempApp.a0;
    }

    return true;
}

bool appInitializeB(void *app) {
    Application &tempApp = *(Application *) app;

    if (tempApp.vb != INT_MAX && tempApp.b0 != INT_MAX) {
        tempApp.initialArray.BVector.push_back(
            vectorBVectorInitialize(tempApp.vb, tempApp.b0, tempApp.temp_var.second));
    }
    else {
        std::cin >> tempApp.vb >> tempApp.b0;
    }

    return true;
}

bool appInitializeData(void *app) {
    Application &tempApp = *(Application *) app;

    tempApp.initialArray.initialData.push_back(vectorInitializeData());

    return true;
}

bool appProcessDataIntoFinalResult(void *app) {
    Application &tempApp = *(Application *) app;

    if (
        (tempApp.initialArray.initialData.back() < tempApp.initialArray.AVector.back()
         && tempApp.initialArray.initialData.back() < tempApp.initialArray.BVector.back())
        ||
        (tempApp.initialArray.initialData.back() > tempApp.initialArray.AVector.back()
         && tempApp.initialArray.initialData.back() > tempApp.initialArray.BVector.back())
    ) {
        tempApp.initialArray.initialData.pop_back();
        tempApp.initialArray.AVector.pop_back();
        tempApp.initialArray.BVector.pop_back();
    }

    return true;
}

bool appGetOutputToUser(void *app) {
    Application &tempApp = *(Application *) app;

    if (tempApp.temp_var.first == 0) {
        std::cout << "After exclusion, left-over values are:" << std::endl;
    }

    std::cout << tempApp.initialArray.initialData[tempApp.temp_var.first] << " ";
    ++tempApp.temp_var.first;

    if (tempApp.temp_var.first == vectorGetSizeInitialData(tempApp.initialArray)) {
        std::cout << std::endl;
    }

    return true;
}

int appRun() {
    Application app;

    if (!operation(&appInitializeA, &app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

    if (!operation(&appInitializeB, &app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

    while (!std::cin.eof()) {

        //Get Value from cin
        if (!operation(&appInitializeData, &app)) {
            std::cout << "DATA INPUT FAILURE." << std::endl;
            return 1;
        }

        //Get left border
        if (!operation(&appInitializeA, &app)) {
            std::cout << "DATA INPUT FAILURE." << std::endl;
            return 1;
        }

        //Get right border
        if (!operation(&appInitializeB, &app)) {
            std::cout << "DATA INPUT FAILURE." << std::endl;
            return 1;
        }

        //Decide whether value is applicable
        if (!operation(&appProcessDataIntoFinalResult, &app)) {
            std::cout << "DATA INPUT FAILURE." << std::endl;
            return 1;
        }

        ++app.temp_var.second;
    }

    for (int i : app.initialArray.initialData) {
        if (!operation(&appGetOutputToUser, &app)) {
            std::cout << "DATA INPUT FAILURE." << std::endl;
            return 1;
        }
    }
    return 0;
}