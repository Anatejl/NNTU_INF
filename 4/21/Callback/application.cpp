//
// Created by Anatejl on 17.06.2024.
//

#include "application.h"
#include <iostream>

bool operation(Callback callback, void *raw_app) {
    return (*callback)(raw_app);
}

int appRun(Application &app){
    operation(&app_get_D, &app);
    while(!std::cin.eof()) {
        ++app.iteration;
        operation(&app_read_cin, &app);
        if (operation(&app_process, &app)) {
            operation(&app_spit_result, &app);
        }
    }
    return 0;
}

bool app_get_D(void *raw_app){
    Application &app = *(Application*) raw_app;
    std::cout << "Input a D number:" << std::endl;
    std::cin >> app.const_D;
    std::cout << app.const_D << std::endl;
    return true;
}

//Read another set of values
bool app_read_cin(void *raw_app){
    Application &app = *(Application*) raw_app;
    for (int &i : app.group_index){
        std::cin >> i;
    }
    return true;
}

bool app_process(void *raw_app){
    Application &app = *(Application*) raw_app;
    //check values over D
    if(!check_neighbour(app.group_index, app.const_D)){
        return false;
    }
    ++app.case_counter;
    return true;
}

//display results if applicable
bool app_spit_result(void *raw_app){
    Application &app = *(Application*) raw_app;
    std::cout << app.iteration << " - Iter. ~ "<< app.case_counter << " CASE " << "grp. applicable: { ";
    for (int &i : app.group_index){
        std::cout << i << " ";
    }
    std::cout << "}"<< std::endl;
    return true;
}