#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include "vector_handle.h"

typedef struct Application{
    int n;
    std::vector<int>array;
    int odd = 0, even = 0, zero = 0;

}Application;

int app_launch(Application& app);
bool app_input(Application& app);
bool app_process(Application& app);
bool app_output(Application& app);

#endif //HEADER_H