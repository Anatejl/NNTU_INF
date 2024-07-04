//
// Created by Anatejl on 19.06.2024.
//

#include "handler.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#define HOLDER_MAX 32

int handler_get_size_of_an_array(void* file_name){

    FILE *file = fopen(file_name, "r");

    //Count lines in file
    int final_line_count = 0;
    char* retrieved_line;
    char* tempStr = malloc(HOLDER_MAX * sizeof (char));
    do{
        retrieved_line = fgets(tempStr,HOLDER_MAX, file);
        if(retrieved_line != NULL){
            ++final_line_count;
        }
    } while (retrieved_line != NULL);

    free(tempStr);

    fclose(file);
    return final_line_count;
}

char** handler_init_file (void* file_name){
    //open file
    FILE *file = fopen(file_name, "r");

    if(file != NULL){
        //total lines in file counter
        int line_count = handler_get_size_of_an_array(file_name);
        char* retrieved_line;

        //Seek to start
        fseek(file, 0, SEEK_SET);

        //Read all lines into array
        char** resulting_array = malloc(sizeof (char*)*line_count);
        for(int i = 0; i < line_count; ++i){
            resulting_array[i] = malloc(HOLDER_MAX*sizeof (char));
            retrieved_line = fgets(resulting_array[i], HOLDER_MAX, file);
        }
        fclose(file);

        for (int i = 0; i < line_count; ++i) {
            size_t size = strlen(resulting_array[i]);
            if (size > 0 && resulting_array[i][strlen(resulting_array[i])- 1]  == '\n') {
                resulting_array[i][strlen(resulting_array[i])- 1] = '\000';
            }
        }
        return resulting_array;
    }
    else{
        printf("ER:011 - Error while opening text file.\n");
    }
    return NULL;
}

void* handler_init_array(int to_create){

    char *start_end_files[] = { NULL,
                                "array_start_locations.txt",
                                "array_end_locations.txt"};

    char** starting_locations = handler_init_file(start_end_files[1]);
    char** ending_locations = handler_init_file(start_end_files[2]);

    //init array
    array_template main_array[to_create];
    srand(time(0));

    int start_lines = handler_get_size_of_an_array(start_end_files[1]);
    int end_lines = handler_get_size_of_an_array(start_end_files[2]);

    //fill array
    for(int i = 0; i < to_create; ++i){

        strcpy(main_array[i].starting_point, starting_locations[rand()% start_lines]);
        strcpy(main_array[i].ending_point, ending_locations[rand()% end_lines]);
        main_array[i].code = rand()%100;

        printf("\n%d is:\n",i);
        printf("%s\n%s\n%d\n\n",main_array[i].starting_point, main_array[i].ending_point, main_array[i].code);

    }

    free(starting_locations);
    free(ending_locations);

    return &main_array;
}

