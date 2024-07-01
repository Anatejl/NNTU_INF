//
// Created by Anatejl on 01.07.2024.
//

#include "application.h"
bool app_get_input(void* p_app){
    App* app = (App*) p_app;
    memset(app->search_string,0,strlen(app->search_string));
    printf("Enter desired author's name:\n");
    if (fgets(app->search_string, MAX_NAME_SIZE, stdin) != NULL) {
        size_t size = strlen(app->search_string);
        if (size > 0 && app->search_string[strlen(app->search_string) - 1] == '\n') {
            app->search_string[strlen(app->search_string) - 1] = '\000';
        }
    }
    fflush(stdin);
    return true;
}

bool app_process(void* p_app){
    App* app = (App*) p_app;
    app->found_index = MIN_VAL;
    for (int i = 0; i < app->count; ++i) {
        if (strcmp(app->library[i].author, app->search_string) == 0 && app->library[i].inplace) {
            app->found_index = i;
            printf("DEBUG: %d\n", app->found_index);
        }
    }
    return true;
}

bool app_get_output(void* p_app){
    App* app = (App*) p_app;
    if (app->found_index > -1) {
        printf("Book by the requested author is - available\n");
    } else {
        printf("Book by the requested author is - unavailable\n");
    }
    return true;
}

bool app_rerun(void* p_app){
    App* app = (App*) p_app;
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