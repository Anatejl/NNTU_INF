//
// Created by Anatejl on 01.07.2024.
//

#include "application.h"

int main(int argc, char* argv[]){

    //declare app of App type variable
    App app;
    //hardcode book count
    app.count = BOOKS_COUNT; //25
    //artificially fill library
    library_fill(app.library);

    //at an ask of a user, infinite while cycle
    do {

        app_get_input(&app);
        app_process(&app);
        app_get_output(&app);

        //if user answers 1, cycle repeats, if else, stops
    }while(app_rerun(&app));

    //goodbye message
    printf("Goodbye!");

    return 0;
}