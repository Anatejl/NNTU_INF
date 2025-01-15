#ifndef NNTU_APPLICATION_H
#define NNTU_APPLICATION_H


#include "cartesian.h"

typedef struct Application{

    std::pair<std::pair<double, double>, std::pair<double, double>> distanced;
    std::vector<std::pair<double, double>> array;
    //distanced.first - dot 1
    //distanced.second - dot 2 
    //distanced.first.first/second - x/y of a 1nd dot
    //distanced.second.first/second - x/y of a 2nd dot

}Application;

int app_run(Application& app_main);
bool app_start(Application& app_main);
bool app_process(Application& app_main);
bool app_end(Application& app_main);

#endif //NNTU_APPLICATION_H