#include "application.h"

bool app_run(Application& app){

    app_start(app);
    app_process(app);
    app_end(app);

    return true;
}

bool app_start(Application& app){

    std::cout << "START START" << std::endl;

    return true;
}

bool app_process(Application& app){

    std::cout << "PROCESSING" << std::endl;

    return true;
}

bool app_end(Application& app){

    std::cout << "ENDING" << std::endl;
    
    return true;
}