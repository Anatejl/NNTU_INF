//
// Created by Anatejl on 27.09.2024.
//

#ifndef NNTU_APPLICATION_H
#define NNTU_APPLICATION_H

#include <vector>
#include <iostream>

typedef struct Application{

    int n;
    std::vector<int> array;

}Application;

int app_run(const Application& app);
bool app_begin(Application &app);
bool app_process(Application &app);
bool app_end(Application &app);

#endif //NNTU_APPLICATION_H
