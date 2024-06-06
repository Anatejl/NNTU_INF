//
// Created by Anatejl on 20.04.2024.
//

#include "application.h"
#include "vector.h"
#include <iostream>

int appRun(Application &app) {

    if (!appInitializeA(app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

    if (!appInitializeB(app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

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

bool appInitializeA(Application &app) {

    if (app.va == INT_MAX && app.a0 == INT_MAX) {
        std::cin >> app.va >> app.a0;
    }

    if (!vectorGetEmptyInitialData(app.initialArray)) {
        app.initialArray.AVector = vectorAVectorInitialize(app.initialArray, app.va, app.a0);
    }

    return true;
}

bool appInitializeB(Application &app) {

    if (app.vb == INT_MAX && app.b0 == INT_MAX) {
        std::cin >> app.vb >> app.b0;
    }

    if (!vectorGetEmptyInitialData(app.initialArray)) {
        app.initialArray.BVector = vectorBVectorInitialize(app.initialArray, app.vb, app.b0);
    }

    return true;
}

bool appInitializeData(Application &app) {

    app.initialArray = vectorInitializeData(app.initialArray);

    return true;
}

bool appProcessDataIntoFinalResult(Application &app) {

    std::vector<int> tempToErase;

    for (int i = 0; i < vectorGetSizeInitialData(app.initialArray); ++i) {
        if (!(app.initialArray.initialData[i] > app.initialArray.AVector[i] &&
              app.initialArray.initialData[i] < app.initialArray.BVector[i])) {
            tempToErase.push_back(i);
        }
    }

    for (int i = tempToErase.size(); i > 0; --i) {
        app.initialArray.initialData.erase(app.initialArray.initialData.begin() + tempToErase[i - 1]);
    }

    return true;
}

bool appGetOutputToUser(Application &app) {

    std::cout << "After exclusion, left-over values are:" << std::endl;
    for (int i = 0; i < vectorGetSizeInitialData(app.initialArray); ++i) {
        std::cout << app.initialArray.initialData[i] << " ";
    }
    std::cout << std::endl;

    return true;
}
