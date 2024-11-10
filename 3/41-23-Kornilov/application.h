#ifndef HEADER_H
#define HEADE_H

#include <iostream>
#include <vector>
#include "vector_handle.h"

typedef struct Application
{
    int n, a0;
    std::vector<int>array;
    int odd, even, zero;

}Application;

int app_launch(Application& app);
bool app_input(Application& app);
bool app_process(Application& app);
bool app_output(Application& app);

#endif //HEADER_H