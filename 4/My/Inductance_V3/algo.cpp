//algo.cpp
//
// Created by Anatejl on 01.06.2024.
//

#include "algo.h"

void algo_update_last(void *object){

    Application &app = *((Application*)object);

    app.last_element.first = app.current_element.first;
    app.last_element.second = app.current_element.second;
    ++app.tempCS;

}

bool algo_check_first_iteration(void *object){

    Application &app = *((Application*)object);

    if(app.current_element.first == 0){
        app.finalLeft.first = app.current_element.first;
        app.finalLeft.second = app.current_element.second;
        app.finalRight.first = app.current_element.first;
        app.finalRight.second = app.current_element.second;
        return true;
    }

    return false;
}

bool algo_check_breakage(void *object){

    Application &app = *((Application*)object);

    if(app.current_element.second <= app.last_element.second){
        app.tempCS = 0;

        return true;
    }

    return false;
}

bool algo_check_ascending(void *object){

    Application &app = *((Application*)object);

    if(app.tempCS > app.finalCS) {

        return true;
    }

    return false;
}

bool algo_check_D(void *object){

    Application &app = *((Application*)object);

    if(app.current_element.second - app.finalLeft.second > app.const_D){
        app.finalLeft.first = app.current_element.first - app.tempCS;
        app.finalRight.first = app.current_element.first;
        app.finalCS = app.tempCS;
        return true;
    }

    return false;
}

