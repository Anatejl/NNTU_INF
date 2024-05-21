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

    if (tempApp.va == INT_MAX && tempApp.a0 == INT_MAX) {
        std::cin >> tempApp.va >> tempApp.a0;
    }

    if (!vectorGetEmptyInitialData(tempApp.initialArray)) {
        tempApp.initialArray.AVector = vectorAVectorInitialize(tempApp.initialArray, tempApp.va, tempApp.a0);
    }

    return true;
}

bool appInitializeB(void *app) {

    Application &tempApp = *(Application *) app;

    if (tempApp.vb == INT_MAX && tempApp.b0 == INT_MAX) {
        std::cin >> tempApp.vb >> tempApp.b0;
    }

    if (!vectorGetEmptyInitialData(tempApp.initialArray)) {
        tempApp.initialArray.BVector = vectorBVectorInitialize(tempApp.initialArray, tempApp.vb, tempApp.b0);
    }

    return true;
}

bool appInitializeData(void *app) {

    Application &tempApp = *(Application *) app;

    tempApp.initialArray = vectorInitializeData(tempApp.initialArray);

    return true;
}

bool appProcessDataIntoFinalResult(void *app) {

    Application &tempApp = *(Application *) app;

    if (tempApp.temp_var.first < vectorGetSizeInitialData(tempApp.initialArray)) {
        if (!(tempApp.initialArray.initialData[tempApp.temp_var.first] > tempApp.initialArray.AVector[tempApp.temp_var.first] &&
              tempApp.initialArray.initialData[tempApp.temp_var.first] < tempApp.initialArray.BVector[tempApp.temp_var.first])) {
            tempApp.temp_var.temp_vector.temp_to_erase.push_back(tempApp.temp_var.first);
        }
        ++tempApp.temp_var.first;
    }

    if(tempApp.temp_var.first == vectorGetSizeInitialData(tempApp.initialArray) && tempApp.temp_var.second == 0) {
        for (int i = vectorGetSizeTempData(tempApp.temp_var.temp_vector); i > 0; --i) {
            tempApp.initialArray.initialData.erase(tempApp.initialArray.initialData.begin() + tempApp.temp_var.temp_vector.temp_to_erase[i - 1]);
        }
    }
    return true;
}

bool appGetOutputToUser(void *app) {

    Application &tempApp = *(Application *) app;

    if (tempApp.temp_var.third == 0) {
        std::cout << "After exclusion, left-over values are:" << std::endl;
    }

    std::cout << tempApp.initialArray.initialData[tempApp.temp_var.third] << " ";
    ++tempApp.temp_var.third;

    if (tempApp.temp_var.third == vectorGetSizeInitialData(tempApp.initialArray)) {
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

    if (!operation(&appInitializeData, &app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

    if (!operation(&appInitializeA, &app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

    if (!operation(&appInitializeB, &app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

    for(int i = 0; i < vectorGetSizeInitialData(app.initialArray); ++i) {
        if (!operation(&appProcessDataIntoFinalResult, &app)) {
            std::cout << "DATA INPUT FAILURE." << std::endl;
            return 1;
        }
    }

    for (int i = 0; i < vectorGetSizeInitialData(app.initialArray); ++i) {
        if (!operation(&appGetOutputToUser, &app)) {
            std::cout << "DATA INPUT FAILURE." << std::endl;
            return 1;
        }
    }
    return 0;
}