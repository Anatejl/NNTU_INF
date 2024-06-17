//
// Created by Anatejl on 17.06.2024.
//

#ifndef NNTU_APPLICATION_H
#define NNTU_APPLICATION_H

#include "check_neighbour.h"

struct Application{
    int iteration = 0;
    int const_D;
    int case_counter = 0;
    int group_index[3];
};

typedef bool (*Callback)(void *raw_app);
bool operation(Callback callback, void *raw_app);

int appRun(Application &app);
bool app_get_D(void *raw_app);
bool app_read_cin(void *raw_app);
bool app_process(void *raw_app);
bool app_spit_result(void *raw_app);

#endif //NNTU_APPLICATION_H
