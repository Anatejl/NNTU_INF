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

    FILE *f_start = fopen(file_name, "r");

    //Count lines in file
    int final_line_count = 0;
    char* retrieved_line;
    char* tempStr = malloc(HOLDER_MAX * sizeof (char));
    do{
        retrieved_line = fgets(tempStr,HOLDER_MAX, f_start);
        if(retrieved_line != NULL){
            ++final_line_count;
        }
    } while (retrieved_line != NULL);

    free(tempStr);

    return final_line_count;
}

char** handler_init_file (void* file_name){
    //we open file
    FILE *f_start = fopen(file_name, "r");

    if(f_start != NULL){
        //total lines in file counter
        int line_count = handler_get_size_of_an_array(file_name);
        char* retrieved_line;

        //Seek to start
        fseek(f_start, 0, SEEK_SET);

        //Read all lines into array
        char** resulting_array = malloc(sizeof (char*)*line_count);
        for(int i = 0; i < line_count; ++i){
            resulting_array[i] = malloc(HOLDER_MAX*sizeof (char));
            retrieved_line = fgets(resulting_array[i], HOLDER_MAX, f_start);
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

    //init array
    array_template main_array[to_create];
    srand(time(0));

    //fill array
    for(int i = 0; i < to_create; ++i){

        strcpy(main_array[i].starting_point, starting_locations[rand()% handler_get_size_of_an_array(start_end_files[1])]);
        strcpy(main_array[i].ending_point, ending_locations[rand()%handler_get_size_of_an_array(start_end_files[1])]);
        main_array[i].code = rand()%100;

        printf("\n%d is:\n",i);
        printf("%s\n%s\n\%d\n\n",main_array[i].starting_point, main_array[i].ending_point, main_array[i].code);

        //printf("%d\n", p_array[i].code);
    }

    void* p_main_array = &main_array;
    return p_main_array;
}

void handler_destroy(void* to_free){

    free(to_free);

}

