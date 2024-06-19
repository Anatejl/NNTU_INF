//
// Created by Anatejl on 19.06.2024.
//

#include <stdlib.h>
#include "application.h"

int app_run(void* raw_app){

    Application app = *(Application*) raw_app;

    int* p_array = application_malloc(3);

    application_destroy(p_array);

    return 0;
}
