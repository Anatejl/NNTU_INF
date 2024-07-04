//
// Created by Anatejl on 19.06.2024.
//

#include "handler.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>

#define HOLDER_MAX 32

char** handler_init_file (void* file_name){
    //we open file
    FILE *f_start = fopen(file_name, "r");

    //total lines in file counter
    int line_count = 0;

    if(f_start != NULL){
        //Count lines in file
        char* tempStr = malloc(HOLDER_MAX * sizeof (char));
        char* retrieved_line;
        do{
            retrieved_line = fgets(tempStr,HOLDER_MAX, f_start);
            if(retrieved_line != NULL){
                ++line_count;
            }
        } while (retrieved_line != NULL);
        free(tempStr);

        //Seek to start
        fseek(f_start, 0, SEEK_SET);

        //Read all lines into array
        char** resulting_array = malloc(sizeof (char*)*line_count);
        for(int i = 0; i < line_count; ++i){
            resulting_array[i] = malloc(HOLDER_MAX*sizeof (char));
            retrieved_line = fgets(resulting_array[i], HOLDER_MAX, f_start);
            if(retrieved_line != NULL){
                printf("DA? %s\n", resulting_array[i]);
            }
        }

        fclose(f_start);

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

    printf("\n\nYA TYT %s",starting_locations[4]);
    //for (int i = 0; i < sizeof (starting_locations)/sizeof (char); ++i) {
    //    printf("1- %s\n", starting_locations[i]);
    //}

    //init array
    array_template* p_array = (array_template*) malloc(to_create * sizeof(array_template));
    p_array -> code = 2;

    //fill array
    for(int i = 0; i < to_create; ++i){

        p_array[i].code = i;

        //printf("%d\n", p_array[i].code);
    }

    return p_array;
}

void handler_destroy(void* to_free){

    free(to_free);

}

