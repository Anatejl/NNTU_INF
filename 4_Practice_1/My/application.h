//
// Created by Anatejl on 19.06.2024.
//

#ifndef NNTU_APPLICATION_H
#define NNTU_APPLICATION_H

#include "handler.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct Application{

    int length_of_an_array;

}Application;

void app_do_output(void* raw_app, void* raw_array);
int app_run(void* raw_app);
int app_get_length_of_an_array(void* raw_app);
bool app_rerun();

#endif //NNTU_APPLICATION_H