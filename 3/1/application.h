//
// Created by anatejl on 8/21/24.
//

#ifndef NNTU_APPLICATION_H
#define NNTU_APPLICATION_H

#include <iostream>
#include <vector>

struct Application {

    unsigned n;
    std::vector<int> initial_array;
    std::vector<int> processed_array;
};

bool app_get_n(Application& app);
bool app_get_array(Application& app);
bool app_process_array(Application& app);
bool app_output(Application& app);

int app_run(Application& app);

#endif //NNTU_APPLICATION_H
