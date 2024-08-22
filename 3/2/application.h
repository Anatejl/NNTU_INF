//
// Created by anatejl on 8/21/24.
//

#ifndef APPLICATION_H
#define APPLICATION_H
#include "handler.h"
#include <vector>
#include <iostream>

struct batch_template {

    int b;
    int a;
    bool is_good;

};

struct Application {

    std::vector<batch_template> batch;
    int delta;
    int n;

};

int app_run(Application& app);
bool app_generate_batch(Application& app);
bool app_get_input(Application& app);
bool app_evaluate_batch(Application& app);
bool app_do_output(Application& app);


#endif //APPLICATION_H
