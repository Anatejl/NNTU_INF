//
// Created by Anatejl on 19.06.2024.
//
#include "application.h"

int app_run(void* raw_app){

    //cast raw to an app
    Application app = *(Application*) raw_app;

    //get int for array building
    app_get_size_of_an_array(&app);

    //p to allocated memory
    int* p_array = application_malloc(app.size_of_an_array);

    //DESTRUCTOR SECTION
    //destroy p to array;
    application_destroy(p_array);

    return 0;
}

bool app_get_size_of_an_array(void* raw_app){

    Application &app = *(Application*) raw_app;

    printf("Enter a number to build array upon: \n");
    scanf_s("%d", app.size_of_an_array);

    return true;
}