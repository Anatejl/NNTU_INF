//
// Created by Anatejl on 19.06.2024.
//
#include "application.h"

int app_run(void* raw_app){

    //cast an address received from main function, to a pointer to Application type, name it app
    Application* app = (Application*) raw_app;

    //prompt user to enter a number of routes to generate
    app_get_length_of_an_array(app);

    //get a pointer to main array of routes with starting and ending locations
    //as an argument, give it number entered by user in previous line
    int *p_array = handler_init_array(app->length_of_an_array);

    //do output cycle once, then ask user whether he wants to repeat
    do {

        //call output function that will ask a user of a route he wants to gen info on,
        //find it in array then sequentially display its contents. Starting and ending locations
        //and route number.
        //if happens that route wasn't found, display error message stating that.
        app_do_output(app, p_array);

    }while(app_rerun()); //ask user whether he wants to repeat search

    //deallocate main array
    free(p_array);

    return 0;
}

void app_do_output(void* raw_app, void* raw_array){

    //cast a void pointer of an app address to an Application type pointer named app
    Application* app = (Application*) raw_app;
    //same to main array pointer
    array_template* array = (array_template *) raw_array;

    //declare number to find in an array
    int to_find;

    //ask user to enter that number
    printf("Which route you would like to know about?\n");

    //retrieve that number from input
    scanf("%d", &to_find);

    //clear input buffer
    fflush(stdin);

    //go through each entry in the main array
    for(int i = 0; i < app->length_of_an_array; ++i){
        // if route number is equal to one in the array's entry, -> display it and break from cycle
        if(array[i].code == to_find){
            printf("\nRoute was found!\n# - %d\nStarting at - %s\nEnding at - %s\n\n", array[i].code, array[i].starting_point, array[i].ending_point);
            break;
        }
        //if no route was found, display clarification on that
        if(i == (app->length_of_an_array)-1){
            printf("No appropriate route was found.\n");
        }
    }
}

int app_get_length_of_an_array(void* raw_app){

    //cast a void pointer of an app address to an Application type pointer named app
    Application* app = (Application*) raw_app;

    //ask user of total number of routes to build array upon
    printf("Enter total number of routes:\n");
    scanf("%d", &(app->length_of_an_array));
    fflush(stdin);

    return 0;
}

bool app_rerun(){

    //used to ask user whether he wants to repeat search cycle, if answer is 1 (i.e. - yes)
    // then search again, if else, effectively end the program
    int temp_read;
    printf("Repeat? (1 = yes, else = no)\n");
    scanf("%d", &temp_read);
    fflush(stdin);
    if(temp_read == 1){
        return true;
    }
    else{
        return false;
    }
}