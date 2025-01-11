#ifndef NNTU_APPLICATION_H
#define NNTU_APPLICATION_H

#include <iostream>
#include "cartesian.h"

typedef struct Application_mainline{

    std::pair<std::pair<double, double>, std::pair<double, double>> distanced;
    //distanced.first - dot 1
    //distanced.second - dot 2 
    //distanced.first.first/second - x/y of a 1nd dot
    //distanced.second.first/second - x/y of a 2nd dot

}Application_mainline;

typedef struct Application_source{

    std::vector<std::pair<double, double>> array;

}Application_source;

int app_run(Application_mainline& app_main, Application_source& app_source);
bool app_start(Application_mainline& app_main, Application_source& app_source);
bool app_process(Application_mainline &app_main, Application_source& app_source);
bool app_end(Application_mainline& app_main, Application_source& app_source);


#endif //NNTU_APPLICATION_H