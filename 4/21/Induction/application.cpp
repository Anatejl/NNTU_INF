//
// Created by Anatejl on 17.06.2024.
//

#include "application.h"
#include <iostream>
int appRun(Application &app){
    app_get_D(app);
    while(!std::cin.eof()) {
        ++app.iteration;
        app_read_cin(app);
        if (app_process(app)) {
            app_spit_result(app);
        }
    }
    return 0;
}

bool app_get_D(Application &app){
    std::cout << "Input a D number:" << std::endl;
    std::cin >> app.const_D;
    std::cout << app.const_D << std::endl;
    return true;
}

bool app_read_cin(Application &app){
    for (int &i : app.group_index){
        std::cin >> i;
    }
    return true;
}

bool app_process (Application &app){
    if(!check_neighbour(app.group_index, app.const_D)){
        return false;
    }
    ++app.case_counter;
    return true;
}

bool app_spit_result(Application &app){
    std::cout << app.iteration << " - Iter. ~ "<< app.case_counter << " CASE " << "grp. applicable: { ";
    for (int &i : app.group_index){
        std::cout << i << " ";
    }
    std::cout << "}"<< std::endl;
    return true;
}