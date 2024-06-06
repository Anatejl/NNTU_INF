//
// Created by Anatejl on 20.04.2024.
//

#include "application.h"
#include "vector.h"
#include <iostream>

int appRun(Application &app) {

    if (!appGetA(app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

    if (!appGetB(app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

    if (!appInitializeData(app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

    if (!appGetA(app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

    if (!appGetB(app)) {
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

bool appGetA(Application &app) {

    if (app.va == INT_MAX && app.a0 == INT_MAX) {
        std::cin >> app.va >> app.a0;
        return true;
    }
    else{
        int calculated = app.va * app.iteration + app.a0;
        return calculated;
    }
}

bool appGetB(Application &app) {

    if (app.vb == INT_MAX && app.b0 == INT_MAX) {
        std::cin >> app.vb >> app.b0;
        return true;
    }
    else{
        int calculated = app.vb * app.iteration + app.b0;
        return calculated;
    }
}

bool appInitializeData(Application &app) {

    std::cin >> app.cin_read;

    if(std::cin.fail()){
        return false;
    }

    return true;
}

bool appProcess(Application &app) {

    if(app.cin_read > appGetA(app) && appGetB(app) < app.cin_read){
       app.judgement = true;
    }

    return false;
}

bool appDoOutput(Application &app) {

    std::cout << "After exclusion, left-over values are:" << std::endl;
    for (int i = 0; i < vectorGetSizeInitialData(app.initialArray); ++i) {
        std::cout << app.initialArray.initialData[i] << " ";
    }
    std::cout << std::endl;

    return true;
}
