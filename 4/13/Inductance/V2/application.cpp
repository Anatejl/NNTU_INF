//
// Created by Anatejl on 20.04.2024.
//

#include "application.h"
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
    //use !std::cin.eof for testing
    while(true) {
        if (!appGetData(app)) {
            std::cout << "DATA INPUT FAILURE." << std::endl;
            return 1;
        }

        if (appProcess(app)) {
            appDoOutput(app);
        }
        ++app.iteration;
    }
    return 0;
}

int appGetA(Application &app) {
    if (app.va == INT_MAX && app.a0 == INT_MAX) {
        std::cin >> app.va >> app.a0;
        return true;
    }
    else{
        int calculated = app.va * app.iteration + app.a0;
        return calculated;
    }
}

int appGetB(Application &app) {
    if (app.vb == INT_MAX && app.b0 == INT_MAX) {
        std::cin >> app.vb >> app.b0;
        return true;
    }
    else{
        int calculated = app.vb * app.iteration + app.b0;
        return calculated;
    }
}

bool appGetData(Application &app) {
    std::cin >> app.cin_read;
    if(std::cin.fail()){
        return false;
    }
    return true;
}

bool appProcess(Application &app) {
    if(app.cin_read > appGetA( app) &&  app.cin_read < appGetB(app)){
       return true;
    }
    return false;
}

bool appDoOutput(Application &app) {
    std::cout << app.iteration << " - " << app.cin_read << std::endl;
    //DEBUG
    std::cout << appGetA(app) << " ÷ " << appGetB(app) << std::endl << std::endl;
    return true;
}
