//
// Created by Anatejl on 20.04.2024.
//

#include "application.h"
#include "vector.h"
#include <iostream>


int appRun(Application &app) {
    if (!appInitializeData(app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

    if (!appGetConstantD(app)) {
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
    app.initialValueArray = vectorValueArrayInitialize(app.initialValueArray);
    app.initialIndexArray = vectorIndexArrayInitialize(app.initialValueArray);
    std::cout << "Input array has been successfully processed." << std::endl;

    return true;
}

bool appGetConstantD(Application &app) {
    std::cout << "Input a R constant, to compare adjacent values:" << std::endl;
    app.constR = 0;
    std::cout << app.constR << std::endl;

    return true;
}

bool appProcessDataIntoFinalResult(Application &app) {
    for (int i = 0; i < app.initialValueArray.counter; ++i) {
        if ((app.initialValueArray.value[i] - app.initialValueArray.value[i - 1]) > app.constR) {
            app.finalIndexArray.value.push_back(app.initialIndexArray.value[i]);
            app.finalValueArray.value.push_back(
                std::make_pair(app.initialValueArray.value[i - 1], app.initialValueArray.value[i]));
            ++app.finalValueArray.counter && app.finalIndexArray.counter;
        }

        if (i != 0 && app.initialValueArray.value[i] == 0) {
            if ((app.initialValueArray.value[i - 1] - app.initialValueArray.value[i]) > app.constR) {
                app.finalIndexArray.value.push_back(app.initialIndexArray.value[i]);
                app.finalValueArray.value.push_back(
                    std::make_pair(app.initialValueArray.value[i - 1], app.initialValueArray.value[i]));
                ++app.finalValueArray.counter && app.finalIndexArray.counter;
            }
        }


        if (i == app.initialValueArray.counter && app.finalValueArray.value.empty()) {
            return false;
        }

        if (i == 0 && app.initialValueArray.counter == 1) {
            std::cout << std::endl << "Can't compare with void." << std::endl;
            return false;
        }
    }

    return true;
}

bool appGetOutputToUser(Application &app) {
    //Demonstrate input data


    //Output results
    if (!app.finalValueArray.value.empty()) {
        std::cout << std::endl << "Final values are (Index - Left element / Right Element):" << std::endl;

        for (int i = 0; i < app.finalValueArray.value.size(); ++i) {
            std::cout << "Index: " << app.finalIndexArray.value[i] << " - " << app.finalValueArray.value[i].first <<
                    "/" << app.finalValueArray.value[i].second << std::endl;
        }
    } else {
        std::cout << std::endl << "No matches are applicable." << std::endl;
        return false;
    }
    return true;
}
