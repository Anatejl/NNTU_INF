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

    int size_of_an_array;

}Application;

int app_run(void* raw_app);
bool app_get_size_of_an_array(void* raw_app);

#endif //NNTU_APPLICATION_H