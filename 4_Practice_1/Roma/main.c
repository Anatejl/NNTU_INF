//
// Created by Anatejl on 01.07.2024.
//

#include "application.h"

int main(int argc, char* argv[]){

    App app;
    app.count = BOOKS_COUNT; //25
    library_fill(app.library);

    do {

        app_get_input(&app);
        app_process(&app);
        app_get_output(&app);

    }while(app_rerun(&app));

    printf("Goodbye!");

    return 0;
}