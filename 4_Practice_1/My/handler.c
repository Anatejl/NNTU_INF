//
// Created by Anatejl on 19.06.2024.
//

#include "handler.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

//Assume a line in an array won't be larger than 32 symbols
#define HOLDER_MAX 32

int handler_get_size_of_an_array(void* file_name){

    //open a file of given with an argument, hence "file_name"
    FILE *file = fopen(file_name, "r");

    if(file != NULL) {
        //Counter for lines in file
        int final_line_count = 0;

        //fully retrieved line
        char *retrieved_line;

        //temporary variable to act as a buffer for fgets()
        char *tempStr = malloc(HOLDER_MAX * sizeof(char));

        //cycle until all lines in provided file are read
        do {
            //get a line
            retrieved_line = fgets(tempStr, HOLDER_MAX, file);

            //if a line isn't NULL -> add 1 to line counter
            if (retrieved_line != NULL) {
                ++final_line_count;
            }
        } while (retrieved_line != NULL);

        //deallocate our "buffer" variable
        free(tempStr);

        //close the file which was read through
        fclose(file);

        //return number of lines in a file
        return final_line_count;
    }
    else{
        // if any error occurs with file, print an error and return NULL
        printf("ER:011 - Error while opening text file.\n");
        return 0;
    }
}

char** handler_init_file (void* file_name){

    //open a file of given with an argument, hence "file_name"
    FILE *file = fopen(file_name, "r");

    //if a file of given name exists, then do code, else -> print an error
    if(file != NULL){
        //total lines in file, given for function to process
        int line_count = handler_get_size_of_an_array(file_name);

        //Read all lines into array
        //malloc for resulting array
        char** resulting_array = malloc(sizeof (char*)*line_count);

        //sequentially read all lines
        for(int i = 0; i < line_count; ++i){
            //malloc for each line in the array, assume line is no longer then 32
            resulting_array[i] = malloc(HOLDER_MAX*sizeof (char));

            //read line into the array's line
            fgets(resulting_array[i], HOLDER_MAX, file);
        }

        //close the file
        fclose(file);

        //for each line
        for (int i = 0; i < line_count; ++i) {

            //knowing the length of a string
            size_t size = strlen(resulting_array[i]);

            //if last character of a string contains newline escape
            if (size > 0 && resulting_array[i][strlen(resulting_array[i])- 1]  == '\n') {

                //then delete it
                resulting_array[i][strlen(resulting_array[i])- 1] = '\000';
            }
        }

        //return resulting array
        return resulting_array;
    }
    else{

        // if any error occurs with file, print an error and return NULL
        printf("ER:011 - Error while opening text file.\n");
        return NULL;
    }
}

void* handler_init_array(int to_create){

    //provide names of two files being used
    char *start_end_files[] = { NULL,
                                "array_start_locations.txt",
                                "array_end_locations.txt"};

    //get contents of both files into arrays of starting and ending cities
    char** starting_locations = handler_init_file(start_end_files[1]);
    char** ending_locations = handler_init_file(start_end_files[2]);

    //malloc for main array
    array_template* main_array = malloc(sizeof (array_template)*to_create);
    //give a rand() seed to generate upon
    srand(time(0));

    //get lines from each file
    int start_lines = handler_get_size_of_an_array(start_end_files[1]);
    int end_lines = handler_get_size_of_an_array(start_end_files[2]);

    //assemble main array
    //for each of number entered as a threshold of locations
    for(int i = 0; i < to_create; ++i){

        //randomly select starting and ending point of the route
        strcpy(main_array[i].starting_point, starting_locations[rand()% start_lines]);
        strcpy(main_array[i].ending_point, ending_locations[rand()% end_lines]);

        //arbitrarily limit routes to 100, then random from 1 to 100
        // it's common sense that routes of public transport is usually in 1-100
        main_array[i].code = rand()%100;

        //give a user a list of available routes
        if(i == 0){
            printf("Available routes: ");
        }
        //print a route number for each route being generated
        printf("%d ", main_array[i].code);

        //Debug entry to display routes being generated
        //printf("\n%d is:\n",i);
        //printf("%s\n%s\n%d\n\n",main_array[i].starting_point, main_array[i].ending_point, main_array[i].code);

    }

    //print two newline escapes into terminal
    printf("\n\n");

    //deallocate both distinct arrays of starting and ending locations
    free(starting_locations);
    free(ending_locations);

    return main_array;
}