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

int app_run(void* raw_app);
int app_get_length_of_an_array();

#endif //NNTU_APPLICATION_H