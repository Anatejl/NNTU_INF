#include "application.h"

int main(int argc, char* argv[]){

    //declare app of App type variable
    App app;

    //run an app
    int ret = app_run(&app);

    return ret;
}