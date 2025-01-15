#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include "vector_handle.h"

typedef struct Application{

    int counter_positive = 0, counter_negative = 0, counter_zero = 0;

}Application;


typedef struct Source_data{

    std::vector<int>array;

}Source_data;


int app_launch(Application& app, Source_data& source);
bool app_input(Application& app, Source_data& source);
bool app_process(Application& app, Source_data& source);
bool app_output(Application& app);

#endif //HEADER_H