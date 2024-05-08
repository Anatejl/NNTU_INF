//
// Created by Anatejl on 20.04.2024.
//

#include "application.h"
#include "vector.h"
#include <iostream>
#include <numeric>


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

    if(app.va == INT_MAX && app.a0 == INT_MAX) {
        std::cin >> app.va >> app.a0;
    }

    if(!app.initialArray.initialData.empty()) {
        for(int i = 0; i < app.initialArray.initialData.size(); ++i){
            app.initialArray.AVector.push_back(app.va * i + app.a0);
        }
    }
    return true;
}

bool appInitializeB(Application &app) {

    if(app.vb == INT_MAX && app.b0 == INT_MAX) {
        std::cin >> app.vb >> app.b0;
    }

    if(!app.initialArray.initialData.empty()) {
        for(int i = 0; i < app.initialArray.initialData.size(); ++i){
            app.initialArray.BVector.push_back(app.vb * i + app.b0);
        }
    }
    return true;
}

bool appInitializeData(Application &app) {

    app.initialArray = vectorInitializeData(app.initialArray);

    return true;
}

bool appProcessDataIntoFinalResult(Application &app) {

    for (int i = 0; i < app.initialArray.initialData.size(); ++i) {

        

    }

    return true;
}

bool appGetOutputToUser(Application &app) {



    return true;
}
