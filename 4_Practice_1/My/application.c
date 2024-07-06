//
// Created by Anatejl on 19.06.2024.
//
#include "application.h"

int app_run(void* raw_app){

    Application* app = (Application*) raw_app;

    //get int for array building
    app_get_length_of_an_array(app);

    int *p_array = handler_init_array(app->length_of_an_array);

    do {

        app_do_output(app, p_array);

    }while(app_rerun());

    free(p_array);

    return 0;
}

void app_do_output(void* raw_app, void* raw_array){
    Application* app = (Application*) raw_app;
    array_template* array = (array_template *) raw_array;

    int to_find;
    printf("Which route you would like to know about?\n");
    scanf_s("%d", &to_find);
    fflush(stdin);

    for(int i = 0; i < app->length_of_an_array; ++i){
        if(array[i].code == to_find){
            printf("\nRoute was found!\n# - %d\nStarting at - %s\nEnding at - %s\n\n", array[i].code, array[i].starting_point, array[i].ending_point);
            break;
        }
        if(i == (app->length_of_an_array)-1){
            printf("No appropriate route was found.\n");
        }
    }
}

int app_get_length_of_an_array(void* raw_app){
    Application* app = (Application*) raw_app;

    printf("Enter total number of routes:\n");
    scanf_s("%d", &(app->length_of_an_array));
    fflush(stdin);

    return 0;
}

bool app_rerun(){
    int temp_read;
    printf("Repeat? (1 = yes, else = no)\n");
    scanf_s("%d", &temp_read);
    fflush(stdin);
    if(temp_read == 1){
        return true;
    }
    else{
        return false;
    }
}