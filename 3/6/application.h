#ifndef NNTU_APPLICATION_H
#define NNTU_APPLICATION_H

#include "vector.h"

typedef struct Application {
    std::vector<int> array; 
} Application;

int app_run(Application& app);
bool app_begin(Application& app);
bool app_process(Application& app);
bool app_end(Application& app);

#endif // NNTU_APPLICATION_H