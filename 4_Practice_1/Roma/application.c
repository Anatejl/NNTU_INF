#include "application.h"

bool app_run(void* p_app){

    //cast void pointer to App pointer
    App* app = (App*) p_app;

    //hardcode book count
    app->count = BOOKS_COUNT; //25

    //artificially fill library
    library_fill(app->library);

    //at an ask of a user, infinite while cycle
    do {

        app_get_input(app);
        app_process(app);
        app_get_output(app);

    }while(app_rerun()); //if user answers 1, cycle repeats, if else, stops

    //goodbye message
    printf("Goodbye!");

    return true;
}

bool app_get_input(void* p_app){

    //cast void pointer to App pointer
    App* app = (App*) p_app;

    //reset app.search_string to 0
    memset(app->search_string,0,strlen(app->search_string));
    printf("Enter desired author's name:\n");

    //get input name from stdin, remove \n newline character at the end, crucial for right comparison
    if (fgets(app->search_string, MAX_NAME_SIZE, stdin) != NULL) {
        size_t size = strlen(app->search_string);
        if (size > 0 && app->search_string[strlen(app->search_string) - 1] == '\n') {
            app->search_string[strlen(app->search_string) - 1] = '\000';
        }
    }

    //clear stdin
    fflush(stdin);

    return true;
}

bool app_process(void* p_app){

    //cast void pointer to App pointer
    App* app = (App*) p_app;

    //assign found_index controlled value, it would never come on its own
    app->found_index = MIN_VAL;

    //search library for name match
    for (int i = 0; i < app->count; ++i) {
        if (strcmp(app->library[i].author, app->search_string) == 0 && app->library[i].inplace) {
            //if found, make book's index into found_index variable
            app->found_index = i;
            //printf("DEBUG: %d\n", app->found_index);
        }
    }
    return true;
}

bool app_get_output(void* p_app){

    //cast void pointer to App pointer
    App* app = (App*) p_app;

    //if index was found, display availability, if not, display it's not
    if (app->found_index > -1) {
        printf("Book by the requested author is - available\n");
    } else {
        printf("Book by the requested author is - unavailable\n");
    }
    return true;
}

bool app_rerun(){

    //Ask user to rerun program? if answer 1 - rerun, if else - end
    int temp_read;
    printf("Wish to get info on other book? (1 = yes, else = no)\n");
    scanf_s("%d", &temp_read);
    fflush(stdin);
    if(temp_read == 1){
        return true;
    }
    else{
        return false;
    }
}