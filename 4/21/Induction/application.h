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

int appRun(Application &app);
bool app_get_D(Application &app);
bool app_read_cin (Application &app);
bool app_process (Application &app);
bool app_spit_result (Application &app);

#endif //NNTU_APPLICATION_H
