#ifndef NNTU_APPLICATION_H
#define NNTU_APPLICATION_H

#include <iostream>
#include <vector>
#include <utility>

typedef struct Application{

    std::vector<std::pair<int, int>> array;
    int n;
    std::pair<std::pair<int,int>, std::pair<int,int>> distanced;
    //distanced.first - dot 1
    //distanced.second - dot 2 
    //distanced.first.first/second - x/y of a 1nd dot
    //distanced.second.first/second - x/y of a 2nd dot

}Application;

bool app_run(Application& app);
bool app_start(Application& app);
bool app_process(Application &app);
bool app_end(Application& app);


#endif //NNTU_APPLICATION_H