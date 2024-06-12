//
// Created by l3t on 11.06.2024.
//

#include "application.h"
#include <iostream>

bool operation(Callback callback, void *data) {
    return (*callback)(data);
}

int app_run(Application &app) {
    if (!operation(&app_get_threshold, &app)) {
        std::cout << "INPUT FAILURE, ABORT ABORT" << std::endl;
    }
    //use !std::cin.eof() for debugging!
    while (!std::cin.eof()) {
        if (!operation(&app_get_another, &app)) {
            std::cout << "SEQ. INPUT FAILURE, ABORT ABORT" << std::endl;
        }
        if (!operation(&app_evaluate, &app)) {
            std::cout << "PROCESSING FAILURE, ABORT ABORT" << std::endl;
        }
        if (!operation(&app_give_output, &app)) {
            std::cout << "OUTPUT FAILURE, ABORT ABORT" << std::endl;
        }
    }
    return 0;
}

bool app_get_threshold(void *raw_app) {
    Application &app = *(Application*) raw_app;
    std::cout << "Input an int, to act as threshold:" << std::endl;
    std::cin >> app.threshold;
    if (std::cin.fail()) {
        return false;
    }
    std::cout << app.threshold << std::endl;
    return true;
}

bool app_get_another(void *raw_app) {
    Application &app = *(Application*) raw_app;
    std::cin >> app.cin_read;
    if (std::cin.fail()) {
        return false;
    }
    return true;
}

bool app_evaluate(void *raw_app) {
    Application &app = *(Application*) raw_app;
    if (app.iteration == 0) {
        app.max.first = 1;
        app.max.second = app.cin_read;
    } else {
        if (app.cin_read == app.max.second) {
            ++app.max.first;
            return true;
        } else if (app.cin_read > app.max.second && app.cin_read < app.threshold) {
            app.max.first = 1;
            app.max.second = app.cin_read;
        }
    }
    return true;
}

bool app_give_output(void *raw_app) {
    Application &app = *(Application*) raw_app;
    std::cout << app.iteration << " - " <<
              app.max.second << " : " << app.max.first << " times." << std::endl;
    ++app.iteration;
    return true;
}