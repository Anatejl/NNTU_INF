//
// Created by l3t on 11.06.2024.
//

#include "application.h"
#include <iostream>

int app_run(Application &app){

    app_get_threshold(app);

    //use !std::cin.eof() for debugging!
    while(!std::cin.eof()){

        app_get_another(app);
        app_evaluate(app);
        app_give_output(app);

    }

    return 0;
}

bool app_get_threshold(Application &app){

    std::cout << "Input an int, to act as threshold:" << std::endl;
    std::cin >> app.threshold;
    std::cout << app.threshold << std::endl;

    return true;
}

bool app_get_another(Application &app){

    std::cin >> app.cin_read;
    if (std::cin.fail()){
        return false;

    }
    return true;
}

bool app_evaluate(Application &app){

    if(app.iteration == 0 ){
        app.max.first = 1;
        app.max.second = app.cin_read;
    }
    else{

        if(app.cin_read == app.max.second){
            ++app.max.first;
            return true;
        }
        else if(app.cin_read > app.max.second && app.cin_read < app.threshold){
            app.max.first = 1;
            app.max.second = app.cin_read;
        }
    }

    return true;
}

bool app_give_output(Application &app){

    std::cout << app.iteration << " - " <<
    app.max.second << " : " << app.max.first << " times." << std::endl;

    ++app.iteration;
    return 0;
}