//
// Created by Anatejl on 19.06.2024.
//
#include "application.h"

int app_run(void* raw_app){

    //cast raw to an app
    Application app = *(Application*) raw_app;

    //get int for array building
    app.length_of_an_array = app_get_length_of_an_array();

    int *p_array = handler_init_array(app.length_of_an_array);

    //DESTRUCTOR SECTION
    //destroy p to array;
    handler_destroy(p_array);

    return 0;
}

int app_get_length_of_an_array(){

    int read;

    printf("Enter a number to build array upon: \n");
    scanf_s("%d", &read);

    return read;
}