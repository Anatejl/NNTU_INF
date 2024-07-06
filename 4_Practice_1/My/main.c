//
// Created by Anatejl on 19.06.2024.
//

#include "application.h"

int main(int argc, char *argv[]){

    //declare a variable of type Application and name in to app
    Application app;

    //call main run function and pass address of that app variable to it
    int ret = app_run(&app);

    return ret;
}